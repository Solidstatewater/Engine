#include "Renderer_pch.h"
#include "ShaderBunch.h"

using namespace Anubis;

ShaderBunch::~ShaderBunch()
{
	SAFE_DELETE(m_pPixelShader);
	SAFE_DELETE(m_pVertexShader);
}

AVOID ShaderBunch::VBind()
{
	m_pVertexShader->Set();
	m_pPixelShader->Set();
}

//Shaders
AVOID ShaderBunch::VSetVertexShader		(const AWSTRING & fileName, const ASTRING & shaderName, INPUT_LAYOUT* layout,
										 AUINT8 num, AUINT16 topology)
{
	//create shader
	//m_pVertexShader = make_shared<VertexShader>(VertexShader());
	m_pVertexShader = new VertexShader;

	//create and compile shader
	BlobDX11* pErrors = new BlobDX11();
	m_pVertexShader->CreateAndCompile(fileName, shaderName, layout, num, topology, pErrors);
}

AVOID ShaderBunch::VSetHullShader		(const AWSTRING & fileName, const ASTRING & shaderName)
{
	//empty here...
}

AVOID ShaderBunch::VSetDomainShader		(const AWSTRING & fileName, const ASTRING & shaderName)
{
	//empty here...
}

AVOID ShaderBunch::VSetGeometryShader	(const AWSTRING & fileName, const ASTRING & shaderName)
{
	//empty here...
}

AVOID ShaderBunch::VSetPixelShader		(const AWSTRING & fileName, const  ASTRING & shaderName)
{
	//initialize shader
	//PixelShader* pShader = new PixelShader();
	//m_pPixelShader = make_shared<PixelShader>(shader);
	//m_pPixelShader.reset(pShader);
	m_pPixelShader = new PixelShader();

	//create and compile shader
	m_pPixelShader->CreateAndCompile(fileName, shaderName);
}