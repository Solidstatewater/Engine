#include "Renderer_pch.h"
#include "GBuffer.h"

#include "Final/General.h"

using namespace Anubis;

/* ==
	==	Constructor ==
== */
GBufferOne::GBufferOne() : 
	/*m_pPosSRV(ShaderResourceView()),		m_pPosRTV(RenderTargetView()), 
	m_pNormalSRV(ShaderResourceView()),		m_pNormalRTV(RenderTargetView()), 
	m_pDiffuseSRV(ShaderResourceView()),	m_pDiffuseRTV(RenderTargetView()), 
	m_pSpecularSRV(ShaderResourceView()),	m_pSpecularRTV(RenderTargetView()) */
	m_SRVList(5), m_RTVList(5)
{
	//==
	//Initialize textures
	//==
	m_pPosTex		= make_shared<Texture2D>(Texture2D());
	m_pNormalTex	= make_shared<Texture2D>(Texture2D());
	m_pDepthTex		= make_shared<Texture2D>(Texture2D());
	m_pDiffuseTex	= make_shared<Texture2D>(Texture2D());
	m_pSpecularTex	= make_shared<Texture2D>(Texture2D());	
}

ABOOL GBufferOne::VInitialize()
{
	//==
	//Define properties for textures
	//==
	Texture2DParams * pParams = new Texture2DParams();
	pParams->Init(SCREEN_WIDTH, SCREEN_HEIGHT, 1, TEX_R32G32B32A32_FLOAT, true, false, 
		true, false, 1, 0, 1, true, false, false);
		//==
	//Create textures
	//==
	Texture2D pTex = *m_pPosTex;
	pTex.Create(pParams);
	m_pPosTex->Create(pParams);
	m_pNormalTex->Create(pParams);
	m_pDepthTex->Create(pParams);
	m_pDiffuseTex->Create(pParams);
	m_pSpecularTex->Create(pParams);


	//Define properties for shader resource views
	ShaderResourceViewParams * pSRVParams = new ShaderResourceViewParams();
	pSRVParams->InitForTexture2D(pParams->Format, 1, 0);

	//==
	//Create Shader Resource Views
	//==
	m_pPosTex->CreateShaderResourceView(m_SRVList.GetView(0), pSRVParams);
	m_pNormalTex->CreateShaderResourceView(m_SRVList.GetView(1), pSRVParams);
	m_pDepthTex->CreateShaderResourceView(m_SRVList.GetView(2), pSRVParams);
	m_pDiffuseTex->CreateShaderResourceView(m_SRVList.GetView(3), pSRVParams);
	m_pSpecularTex->CreateShaderResourceView(m_SRVList.GetView(4), pSRVParams);

	//Define properties for shader resource views
	RenderTargetViewParams * pRTVParams = new RenderTargetViewParams();
	pRTVParams->InitForTexture2D(pParams->Format, 0);

	//==
	//Create Render Target Views
	//==
	m_pPosTex->CreateRenderTargetView(m_RTVList.GetView(0), pRTVParams);
	m_pNormalTex->CreateRenderTargetView(m_RTVList.GetView(1), pRTVParams);
	m_pDepthTex->CreateRenderTargetView(m_RTVList.GetView(2), pRTVParams);
	m_pDiffuseTex->CreateRenderTargetView(m_RTVList.GetView(3), pRTVParams);
	m_pSpecularTex->CreateRenderTargetView(m_RTVList.GetView(4), pRTVParams);

	return 1;
}

AVOID GBufferOne::BindForReading(AUINT16 slot) const
{
	m_SRVList.Set(slot, ST_Pixel); //bind g-buffer for writing
}

AVOID GBufferOne::UnbindFromReading(AUINT16 slot) const
{
	UnbindShaderResourceViews(slot, 5, ST_Pixel);
}

AVOID GBufferOne::BindForWriting()
{
	m_RTVList.Clear(); //clear all render targets
	m_RTVList.Set(); //bind them to the pipeline
}

AVOID GBufferOne::UnbindFromWriting() const
{
	UnbindRenderTargetViews(5);
}