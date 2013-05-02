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

	//delete params structre
	delete params;

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