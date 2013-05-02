#include "Graphics_pch.h"
#include "../../../Final/General.h"
#include "ComputeShaderDX11.h"

using namespace Anubis;

AVOID ComputeShaderDX11::Set() const
{
	D3D11DeviceContext()->CSSetShader(m_pShader, 0, 0);
};

ABOOL ComputeShaderDX11::Create(BlobDX11 & shaderbuffer)
{
	HRESULT hr = D3D11Device()->CreateComputeShader(shaderbuffer.m_pBlob->GetBufferPointer(),
		shaderbuffer.m_pBlob->GetBufferSize(), NULL, &m_pShader);
	
	VALID(hr);
}

ABOOL ComputeShaderDX11::CreateAndCompile(AWSTRING fileName, ASTRING entrypoint, BlobDX11 * pErrors)
{
	//Compile the shader first
	BlobDX11 & compiledShaderBlob = BlobDX11();
	if (!compiledShaderBlob.CompileShader(fileName, entrypoint, COMPUTE_SHADER, pErrors))
	{
		assert(0 && "Some error when compiling the compute shader occured!");
		return false;
	}

	//Create shader
	if (!Create(compiledShaderBlob))
	{
		assert(0 && "Some error when creating the compute shader occured!");
		return false;
	}

	return true;
}