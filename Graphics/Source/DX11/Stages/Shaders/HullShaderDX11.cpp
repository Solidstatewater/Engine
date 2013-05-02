#include "Graphics_pch.h"
#include "../../../Final/General.h"
#include "HullShaderDX11.h"

using namespace Anubis;

AVOID HullShaderDX11::Set() const
{
	D3D11DeviceContext()->HSSetShader(m_pShader, 0, 0);
}

ABOOL HullShaderDX11::Create(BlobDX11 & shaderbuffer)
{
	HRESULT hr = D3D11Device()->CreateHullShader(shaderbuffer.m_pBlob->GetBufferPointer(),
		shaderbuffer.m_pBlob->GetBufferSize(), NULL, &m_pShader);
	
	VALID(hr);
}

ABOOL HullShaderDX11::VCreateAndCompile(AWSTRING fileName, ASTRING entrypoint, BlobDX11 * pErrors)
{
	//Compile the shader first
	BlobDX11 & compiledShaderBlob = BlobDX11();
	if (!compiledShaderBlob.CompileShader(fileName, entrypoint, HULL_SHADER, pErrors))
	{
		assert(0 && "Some error when compiling the hull shader occured!");
		return false;
	}

	//Create shader
	if (!Create(compiledShaderBlob))
	{
		assert(0 && "Some error when creating the hull shader occured!");
		return false;
	}

	return true;
}