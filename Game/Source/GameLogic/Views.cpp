#include "Game_pch.h"
#include "Views.h"

#include "../../../Graphics/Source/Final/General.h"

using namespace Anubis;

ABOOL PlayerView::VInit()
{
	/*** Create Renderer
	//
	// Implementation at Renderer project
	//
	***/
	//m_pDeferredRenderer = new DeferredRenderer();

	bgColor[0] = 1.0f;
	bgColor[1] = 1.0f;
	bgColor[2] = 1.0f;
	bgColor[3] = 1.0f;

	return true;
}

ABOOL PlayerView::VRestore()
{ 
	return true;
}

AVOID PlayerView::VUpdate(AUINT32 const deltaMilliseconds)
{
	//Update Renderer state for current player view
	//m_pDeferredRenderer->VUpdate(deltaMilliseconds);
}

AVOID PlayerView::VRender(AREAL64 r64Time, AREAL64 r64ElapsedTime)
{
	//Clean back buffer render target and depth stencil
	//ALIGN16 AREAL32 bgColor[4] = { 0.0f, 1.0f, 1.0f, 1.0f }; //color
	ALIGN16 AREAL32 bg[4] = { 1.0f, 0.0f, 0.0f, 1.0f };
	ClearRenderTargetView(bg, NULL);
	ClearDepthStencilView(true, true, 1.0f, 0, NULL);
}

LRESULT	PlayerView::VMsgProc(AppMsg & msg)
{
	return 1;
}

AVOID PlayerView::VSetCamera(CameraPtr pCamera)
{
	m_pCamera = pCamera;
	m_bHasCamera = true;
}