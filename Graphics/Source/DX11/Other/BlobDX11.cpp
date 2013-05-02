#include "Graphics_pch.h"
#include "BlobDX11.h"
#include <D3Dcompiler.h>

#include "Error_Handling/Assert.h"

using namespace Anubis;

ABOOL BlobDX11::CompileShader(AWSTRING fileName, ASTRING entrypoint,
									ShaderType type, BlobDX11 * pErrors) const
{
	//Check what type of shader we are compiling
	ASTRING target;
	switch (type)
	{
		case ST_Vertex:
			target = "vs_5_0";
			break;
		case ST_Hull:
			target = "hs_5_0";
			break;
		case ST_Domain:
			target = "ds_5_0";
			break;
		case ST_Geometry:
			target = "gs_5_0";
			break;
		case ST_Pixel:
			target = "ps_5_0";
			break;
		case ST_Compute:
			target = "cs_5_0";
			break;
	};

	//Compilation
	//HRESULT hr = D3DCompile(fileName.c_str(), fileName.size(), NULL, NULL, NULL, entrypoint.c_str(), target.c_str(), 0, 0,
	//	(ID3DBlob**)&m_pBlob, &pErrors->m_pBlob);
	HRESULT hr = D3DX11CompileFromFile(fileName.c_str(), 0, 0, entrypoint.c_str(), target.c_str(), 0, 0, 0, 
		(ID3DBlob**)&m_pBlob, &pErrors->m_pBlob, 0);

	//If any errors, draw them to debug output
	if (hr != S_OK)
	{
		OutputDebugStringA((char*)pErrors->m_pBlob->GetBufferPointer());
		CheckHR(hr);
		return false;
	}

	return true;
}