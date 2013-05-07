#include "Renderer_pch.h"
#include "DeferredRenderer.h"

#include "Final\General.h"
#include "Final\Resources\ResourceData.h"

using namespace Anubis;

DeferredRenderer::DeferredRenderer() : Renderer()
{
	m_pVertices		= new VertexBuffer();
	m_pTexCoords	= new VertexBuffer();

	//create matrix constant buffer
	m_pMatrixBuffer = new ConstantBuffer();
}

DeferredRenderer::~DeferredRenderer()
{
	//remove all lights
	while(!m_lights.empty())
		m_lights.pop_back();
}

ABOOL DeferredRenderer::VInitialize(HWND hWnd, AUINT32 width, AUINT32 height)
{
	if (!Renderer::VInitialize(hWnd, width, height))
	{
		assert(0 && "Some problem initializing Renderer occured");
	}

	//initialize gbuffer
	m_gbuffer.VInitialize();

	//initialize data for light pass
	BufferParams matBufferParams;
	matBufferParams.FillConstantBufferParams(sizeof(Mat4x4), true, false, false);
	m_pMatrixBuffer->Create(&matBufferParams, NULL);

	//initialize data for light rendering
	BufferParams params;
	params.FillVertexBufferParams(sizeof(float3), 6, true, false, false, false);

	//position data
	SubresourceData data;

	AREAL32 left = (AREAL32)(SCREEN_WIDTH / 2 * -1);
	AREAL32 right = left + SCREEN_WIDTH;
	AREAL32 top = (AREAL32)(SCREEN_HEIGHT / 2);
	AREAL32 bottom = top - SCREEN_HEIGHT;

	float3 pos [] = 
	{
		float3(left,	top,	0.0f), //left top
		float3(right,	top,	0.0f), //right top
		float3(left,	bottom, 0.0f), //left bottom
		float3(left,	bottom, 0.0f), //left bottom
		float3(right,	top,	0.0f), //right top
		float3(right,	bottom, 0.0f), //right bottom
	};

	data.SetData(pos);
	if (!m_pVertices->Create(&params, &data, 6, sizeof(float3)))
	{
		assert(0 && "Error creating vertex buffer in Deferred Renderer initialization!");
	}

	//texture coordinates
	params.SetSize(sizeof(float2) * 6);

	float2 texCoords [] =
	{
		float2(0.0f, 0.0f), //left top
		float2(1.0f, 0.0f), //right top
		float2(0.0f, 1.0f), //left bottom
		float2(0.0f, 1.0f), //left bottom
		float2(1.0f, 0.0f), //right top
		float2(1.0f, 1.0f), //right bottom
	};

	data.SetData(texCoords);
	if (!m_pTexCoords->Create(&params, &data, 6, sizeof(float2)))
	{
		assert(0 && "Error creating vertex buffer with texture coordinates in Deferred Renderer initialization!");
	}

	//input layout
	m_pLayout = new INPUT_LAYOUT[2];
	m_pLayout[0].SemanticName			= "POSITION";			m_pLayout[1].SemanticName			= "TEXCOORDS";
	m_pLayout[0].SemanticIndex			= 0;					m_pLayout[1].SemanticIndex			= 0;
	m_pLayout[0].Format					= TEX_R32G32B32_FLOAT;	m_pLayout[1].Format					= TEX_R32G32_FLOAT;
	m_pLayout[0].InputSlot				= 0;					m_pLayout[1].InputSlot				= 0;
	m_pLayout[0].AlignedByteOffset		= 0;					m_pLayout[1].AlignedByteOffset		= 12;
	m_pLayout[0].InputSlotClass			= IA_PER_VERTEX_DATA;	m_pLayout[1].InputSlotClass			= IA_PER_VERTEX_DATA;
	m_pLayout[0].InstanceDataStepRate	= 0;					m_pLayout[1].InstanceDataStepRate	= 0;

	return true;
}

///////////////////////////////////////////////
//Updating
///////////////////////////////////////////////
AVOID DeferredRenderer::VPushMesh(Mesh * pMesh)
{
	m_queue.VAdd(pMesh);
}

AVOID DeferredRenderer::VPushLight(Light * pLight)
{
	m_lights.push_back(pLight);
}

AVOID DeferredRenderer::VUpdate(const AUINT32 deltaMilliseconds)
{
	//Firstly, sort render queue
	m_queue.VSort();
}

///////////////////////////////////////////////
//Rendering
///////////////////////////////////////////////

AVOID DeferredRenderer::PrepareForLightPass(CameraPtr pCamera)
{
	//set vertex buffer with positions
	m_pVertices->Set(0, 0);

	//set vertex buffer with texture data
	m_pTexCoords->Set(1, 0);

	//bind matrix constant buffer to the pipeline
	Mat4x4 trans;
	trans.CreateTranslation(pCamera->GetLookAt());

	Mat4x4 rot;
	rot = rot.CreateRollPitchYaw(pCamera->GetRoll(), pCamera->GetPitch(), pCamera->GetYaw());

	Mat4x4 WVP = rot * trans * pCamera->GetView() * CreateOrthoProjectionLH(SCREEN_WIDTH, SCREEN_HEIGHT, 0.1f, 1000.0f);
	WVP.Transpose();
	m_pMatrixBuffer->UpdateSubresource(0, NULL, &WVP, 0, 0);
	m_pMatrixBuffer->Set(0, ST_Vertex);

	m_pcbCameraPos->UpdateSubresource(0, NULL, &pCamera->GetPosition(), 0, 0);
	m_pcbCameraPos->Set(0, ST_Pixel);
}

AVOID DeferredRenderer::VRender()
{
	/*** Render Scene For Each Camera ***/
	for (CameraPtr pCamera : m_cameras)
	{
		//Keep track of current view and projection matrices
		Mat4x4 view			= pCamera->GetView();
		Mat4x4 projection	= pCamera->GetProjection();
		Mat4x4 viewProj		= view * projection; //calculate view * projection matrix

		//	Rendering to g-buffer
		m_gbuffer.BindForWriting();

		// ===================================================== //
		//	Go through sorted render queue and render each mesh  //
		// ===================================================== //
		Mesh * pMesh;
		while (pMesh = m_queue.Next())
		{
			//set states needed for rendering current mesh
			pMesh->VPreRender(this, viewProj); 

			//finally render it
			pMesh->VRender(this);

			//remove previous states
			pMesh->VPostRender(this);
		} 

		//unbind g-buffer views
		m_gbuffer.UnbindFromWriting();

		//set g-buffer for reading and set back buffer as render target
		m_gbuffer.BindForReading(0);
		SetRenderTargetView(); 

		// ========================================= //
		//	Time for light pass - Render all lights  //
		// ========================================= //
		PrepareForLightPass(pCamera);

		for (Light * pLight : m_lights)
		{
			//initialize light if it hasn't been yet 
			if (!pLight->IsInitialized())
				pLight->VInitialize(m_pLayout);

			//set states needed for rendering current light
			pLight->VPreRender(this); 

			//finally render it
			pLight->VRender();
		}

		//unbind g-buffer views
		m_gbuffer.UnbindFromReading(0);
	}
}