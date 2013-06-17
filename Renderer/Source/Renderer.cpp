#include "Renderer_pch.h"
#include "Renderer.h"

#include "Final/General.h"
#include "Final/Resources/Buffers/BufferParams.h"

using namespace Anubis;

/*Matrix Buffers
		ConstantBuffer*	m_pcbWorldPlusWVP;
		ConstantBuffer* m_pcbWVP; 

		//Camera Buffers
		ConstantBuffer*	m_pcbCameraPos;

		//Lightning Buffers
		ConstantBuffer*	m_pcbLight;
		ConstantBuffer* m_pcbPointLight;
		ConstantBuffer* m_pcbSpotLight;
		ConstantBuffer*	m_pcbDirectionalLight; */

Renderer::Renderer() : m_bTexturingOn(true), m_bLightningOn(true)
{
	m_pAnisotropySampler16 = new SamplerState();
	m_pDepthDisableStencilDisable = new DepthStencilState();
	m_pDepthEnableStencilDisableStandard = new DepthStencilState();
	m_pDepthTexture = new Texture2D();
	m_pDepthSRV = new ShaderResourceView();
	m_pDepthDSV = new DepthStencilView();
}

ABOOL Renderer::VInitialize(HWND hWnd, AUINT32 width, AUINT32 height)
{
	InitializeGraphics(hWnd, width, height);

	//Initialize structure to fill buffer properties
	BufferParams * params = new BufferParams();

	/*	===============================
		==	Create Constant Buffers  ==
		===============================  */

	//Create World + WVP Matrix Buffer
	params->FillConstantBufferParams(2*sizeof(Mat4x4), true, false, false);
	m_pcbWorldPlusWVP = new ConstantBuffer();
	if (!m_pcbWorldPlusWVP->Create(params, NULL))	return false;

	//Create WVP Matrix Buffer
	params->SetSize(sizeof(Mat4x4));
	m_pcbWVP = new ConstantBuffer();
	if (!m_pcbWVP->Create(params, NULL))			return false;

	//Create Position Camera Buffer
	params->SetSize(sizeof(Vec));
	m_pcbCameraPos = new ConstantBuffer();
	if (!m_pcbCameraPos->Create(params, NULL))		return false;

	//Create Light Buffer
	params->SetSize(3* sizeof(Vec));
	m_pcbLight = new ConstantBuffer();
	if (!m_pcbLight->Create(params, NULL))			return false;

	//Create Point Light Buffer
	params->SetSize(sizeof(Vec));
	m_pcbPointLight = new ConstantBuffer();
	if (!m_pcbPointLight->Create(params, NULL))		return false;

	//Create Spot Light Buffer
	params->SetSize(sizeof(Vec));
	m_pcbSpotLight = new ConstantBuffer();
	if (!m_pcbSpotLight->Create(params, NULL))		return false;

	//Create frustum data buffer
	params->SetSize(sizeof(Vec));
	m_pcbFrustumSize = new ConstantBuffer();
	if (!m_pcbFrustumSize->Create(params, NULL))	return false;

	//Create depth buffer data buffer
	params->SetSize(sizeof(Vec));
	m_pcbDepthBuffer = new ConstantBuffer();
	if (!m_pcbDepthBuffer->Create(params, NULL))	return false;

	//Create SSAO params buffer
	params->SetSize(sizeof(Vec));
	m_pcbSSAOParams = new ConstantBuffer();
	if (!m_pcbSSAOParams->Create(params, NULL))		return false;

	//Create SSAO sample points buffer
	params->SetSize(sizeof(float3) * 8);
	m_pcbSSAOSamples = new ConstantBuffer();
	if (!m_pcbSSAOSamples->Create(params, NULL))	return false;

	//delete params structre
	delete params;

	/*	===================================
		==	Create Depth Stencil States  ==
		=================================== */
	DepthStencilParams depthStencilParams;
	depthStencilParams.Init(true, D3D11_COMPARISON_LESS, false, 0, 0);
	if (!m_pDepthEnableStencilDisableStandard->Create(&depthStencilParams))	return false;

	depthStencilParams.Init(false, D3D11_COMPARISON_LESS, false, 0, 0);
	if (!m_pDepthDisableStencilDisable->Create(&depthStencilParams))		return false;

	Texture2DParams dParams;
	dParams.Init(SCREEN_WIDTH, SCREEN_HEIGHT, 1, DXGI_FORMAT_R32_TYPELESS, true, false, false, true, 1, 0,
		1, true, false, false);
	if (!m_pDepthTexture->Create(&dParams))	return false;

	ShaderResourceViewParams srvParams;
	srvParams.InitForTexture2D(DXGI_FORMAT_R32_FLOAT, 1, 0);
	if (!m_pDepthTexture->CreateShaderResourceView(&m_pDepthSRV->m_pView, &srvParams))	return false;

	DepthStencilViewParams dsvParams;
	dsvParams.InitForTexture2D(DXGI_FORMAT_D32_FLOAT, 0);
	if (!m_pDepthTexture->CreateDepthStencilView(&m_pDepthDSV->m_pView, &dsvParams))	return false;

	return true;
}

Renderer::~Renderer()
{
	//Clean Consant Buffers in reverse order
	SAFE_DELETE(m_pcbSpotLight);
	SAFE_DELETE(m_pcbPointLight);
	SAFE_DELETE(m_pcbLight);
	SAFE_DELETE(m_pcbCameraPos);
	SAFE_DELETE(m_pcbWVP);
	SAFE_DELETE(m_pcbWorldPlusWVP);

	//remove all cameras
	while (!m_cameras.empty())
		m_cameras.pop_back();
}

AVOID Renderer::AddCamera(CameraPtr pCamera)
{
	m_cameras.push_back(pCamera);
}

AVOID Renderer::RemoveCamera(CameraPtr pCamera)
{
	//find camera in the list
	auto camera = m_cameras.begin();
	for (; camera != m_cameras.end(); camera++)
		if ((*camera) == pCamera)
			break;

	//delete camera
	if (camera != m_cameras.end())
		m_cameras.erase(camera);

	//no such camera
	ASSERT(0 && "No such camera was found!");
}

SamplerState* Renderer::AnisotropySampler16()
{
	if (m_pAnisotropySampler16)	return m_pAnisotropySampler16;

	//it's not created yet
	SamplerStateParams params;
	params.Init(FILTER_ANISOTROPIC, TEXTURE_ADDRESS_WRAP,
		TEXTURE_ADDRESS_WRAP, TEXTURE_ADDRESS_WRAP, 0, 16, COMPARISON_NEVER);
	m_pAnisotropySampler16->Create(&params);

	return m_pAnisotropySampler16;
}