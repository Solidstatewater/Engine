#include "Graphics_pch.h"
#include "../../Final/General.h"
#include "DepthStencilStateDX11.h"

using namespace Anubis;

ABOOL DepthStencilStateDX11::Create(const D3D11_DEPTH_STENCIL_DESC * params)
{
	HRESULT hr = D3D11Device()->CreateDepthStencilState(params, &m_pState);
	
	VALID(hr);
}

AVOID DepthStencilStateDX11::Set(const AUINT32 stencilRef) const
{
	D3D11DeviceContext()->OMSetDepthStencilState(m_pState, stencilRef);
}