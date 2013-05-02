#include "Renderer_pch.h"
#include "ShaderBunch.h"

using namespace Anubis;


AVOID ShaderBunch::VBind()
{
	m_pVertexShader->Set();
	m_pPixelShader->Set();
}

//Shaders
AVOID ShaderBunch::VSetVertexShader		(AWSTRING fileName, ASTRING shaderName, INPUT_LAYOUT* layout, AUINT8 num, AUINT16 topology)
{
	//create shader
	m_pVertexShader = make_shared<VertexShader>(VertexShader());

	//create and compile shader
	BlobDX11* pErrors = new BlobDX11();
	m_pVertexShader->CreateAndCompile(fileName, shaderName, layout, num, topology, pErrors);
}

AVOID ShaderBunch::VSetHullShader		(AWSTRING fileName, ASTRING shaderName)
{
	//empty here...
}

AVOID ShaderBunch::VSetDomainShader		(AWSTRING fileName, ASTRING shaderName)
{
	//empty here...
}

AVOID ShaderBunch::VSetGeometryShader	(AWSTRING fileName, ASTRING shaderName)
{
	//empty here...
}

AVOID ShaderBunch::VSetPixelShader		(AWSTRING fileName, ASTRING shaderName)
{
	//initialize shader
	m_pPixelShader = make_shared<PixelShader>(PixelShader());

	//create and compile shader
	m_pPixelShader->CreateAndCompile(fileName, shaderName);
}