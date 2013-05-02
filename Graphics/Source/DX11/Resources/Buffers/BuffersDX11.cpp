#include "Graphics_pch.h"
#include "../../../Final/General.h"
#include "BuffersDX11.h"


using namespace Anubis;

ABOOL BufferDX11::Create(const D3D11_BUFFER_DESC * desc, const SubresourceDataDX11 * pData, AUINT32 numElements)
{
	HRESULT hr = D3D11Device()->CreateBuffer(desc, pData, &m_pBuffer);
	
	VALID(hr);
}

AVOID BufferDX11::UpdateSubresource(AUINT32 destSubresource, const BoxDX11 * pBox,
			const APVOID pSrcData, AUINT32 srcRowPitch, AUINT32 srcDepthPitch)
{
	D3D11DevCon()->UpdateSubresource(m_pBuffer, destSubresource, pBox,
		pSrcData, srcRowPitch, srcDepthPitch);
}