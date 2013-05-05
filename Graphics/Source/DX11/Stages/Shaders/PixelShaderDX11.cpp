#include "Graphics_pch.h"
#include "../../../Final/General.h"
#include "PixelShaderDX11.h"

using namespace Anubis;

AVOID PixelShaderDX11::Set() const
{
	D3D11DeviceContext()->PSSetShader(m_pShader, 0, 0);
}

ABOOL PixelShaderDX11::Create(BlobDX11 & shaderbuffer)
{
	HRESULT hr = D3D11Device()->CreatePixelShader(shaderbuffer.m_pBlob->GetBufferPointer(),
		shaderbuffer.m_pBlob->GetBufferSize(), NULL, &m_pShader);
	
	VALID(hr);
}

ABOOL PixelShaderDX11::CreateAndCompile(const AWSTRING & fileName, const ASTRING & entrypoint, BlobDX11 * pErrors)
{
	//Compile the shader first
	BlobDX11 & compiledShaderBlob = BlobDX11();
	if (!compiledShaderBlob.CompileShader(fileName, entrypoint, PIXEL_SHADER, pErrors))
	{
		assert(0 && "Some error when compiling the pixel shader occured!");
		return false;
	}

	//Create shader
	if (!Create(compiledShaderBlob))
	{
		assert(0 && "Some error when creating the pixel shader occured!");
		return false;
	}

	return true;
}