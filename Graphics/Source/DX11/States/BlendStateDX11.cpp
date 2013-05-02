#include "Graphics_pch.h"
#include "../../Final/General.h"
#include "BlendStateDX11.h"

using namespace Anubis;

ABOOL BlendStateDX11::Create(const D3D11_BLEND_DESC * pParams)
{
	HRESULT hr = D3D11Device()->CreateBlendState(pParams, &m_pState);
	
	VALID(hr);
}