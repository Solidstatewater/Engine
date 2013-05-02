#include "Graphics_pch.h"
#include "../../../Final/General.h"
#include "VertexShaderDX11.h"


using namespace Anubis;

AVOID VertexShaderDX11::Set() const
{
	D3D11DeviceContext()->VSSetShader(m_pShader, 0, 0);

	//set topology and input layout for this shader
	m_pState->SetInputLayoutAndTopology();
}

ABOOL VertexShaderDX11::Create(BlobDX11 & shaderbuffer, INPUT_LAYOUT* layout, AUINT8 num,
										 AUINT16 topology)
{
	//create vertex shader
	HRESULT hr = D3D11Device()->CreateVertexShader(shaderbuffer.m_pBlob->GetBufferPointer(),
		shaderbuffer.m_pBlob->GetBufferSize(), NULL, &m_pShader);
	if (hr != S_OK)
	{
		CheckHR(hr);
		return false;
	}

	//create input layout
	hr = D3D11Device()->CreateInputLayout(layout, num, shaderbuffer.m_pBlob->GetBufferPointer(),
		shaderbuffer.m_pBlob->GetBufferSize(), &m_pState->m_pLayout);
	if (hr != S_OK)
	{
		CheckHR(hr);
		return false;
	}

	//set primitive topology
	m_pState->m_topology = (D3D11_PRIMITIVE_TOPOLOGY)topology;

	return true;
}

ABOOL VertexShaderDX11::CreateAndCompile(	AWSTRING fileName, ASTRING entrypoint, INPUT_LAYOUT* layout, AUINT8 num,
											AUINT16 topology, BlobDX11 * pErrors)
{
	//Compile the shader first
	BlobDX11 & compiledShaderBlob = BlobDX11();
	if (!compiledShaderBlob.CompileShader(fileName, entrypoint, VERTEX_SHADER, pErrors))
	{
		assert(0 && "Some error when compiling the vertex shader occured!");
		return false;
	}

	//create vertex shader
	HRESULT hr = D3D11Device()->CreateVertexShader(compiledShaderBlob.m_pBlob->GetBufferPointer(),
		compiledShaderBlob.m_pBlob->GetBufferSize(), NULL, &m_pShader);
	if (hr != S_OK)
	{
		CheckHR(hr);
		return false;
	}

	//create input layout
	hr = D3D11Device()->CreateInputLayout(layout, num, compiledShaderBlob.m_pBlob->GetBufferPointer(),
		compiledShaderBlob.m_pBlob->GetBufferSize(), &m_pState->m_pLayout);
	if (hr != S_OK)
	{
		CheckHR(hr);
		return false;
	}

	//set primitive topology
	m_pState->m_topology = (D3D11_PRIMITIVE_TOPOLOGY)topology;

	return true;
}