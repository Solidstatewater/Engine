#include "Graphics_pch.h"
#include "../../../Final/General.h"
#include "GeometryShaderDX11.h"

using namespace Anubis;

AVOID GeometryShaderDX11::Set() const
{
	D3D11DeviceContext()->GSSetShader(m_pShader, 0, 0);
}

ABOOL GeometryShaderDX11::Create(BlobDX11 & shaderbuffer)
{
	HRESULT hr = D3D11Device()->CreateGeometryShader(shaderbuffer.m_pBlob->GetBufferPointer(),
		shaderbuffer.m_pBlob->GetBufferSize(), NULL, &m_pShader);
	
	VALID(hr);
}

ABOOL GeometryShaderDX11::VCreateAndCompile(AWSTRING fileName, ASTRING entrypoint, BlobDX11 * pErrors)
{
	//Compile the shader first
	BlobDX11 & compiledShaderBlob = BlobDX11();
	if (!compiledShaderBlob.CompileShader(fileName, entrypoint, GEOMETRY_SHADER, pErrors))
	{
		assert(0 && "Some error when compiling the geometry shader occured!");
		return false;
	}

	//Create shader
	if (!Create(compiledShaderBlob))
	{
		assert(0 && "Some error when creating the geometry shader occured!");
		return false;
	}

	return true;
}
