#include "Renderer_pch.h"
#include "Light.h"
#include "Final\General.h"
#include "../Renderer.h"

using namespace Anubis;

ABOOL Light::VInitialize(INPUT_LAYOUT * pLayout)
{
	m_pShaders = new ShaderBunch();
	m_pShaders->VSetVertexShader(m_shaderFile,	DEFAULT_VERTEX_SHADER_NAME, pLayout, 2, TOPOLOGY_TRIANGLELIST);
	m_pShaders->VSetPixelShader(m_shaderFile,	DEFAULT_PIXEL_SHADER_NAME);

	m_bInitialized = true;

	return true;
}

AVOID Light::VPreRender(Renderer *pRenderer)
{
	//set shader
	m_pShaders->VBind();

	//bind constant buffer to the pipeline
	pRenderer->m_pcbLight->UpdateSubresource(0, NULL, m_pData, 0, 0);
	pRenderer->m_pcbLight->Set(0, ST_Pixel);
}

AVOID Light::VRender()
{
	Draw(6, 0);
}