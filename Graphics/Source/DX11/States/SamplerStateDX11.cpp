#include "Graphics_pch.h"
#include "../../Final/General.h"
#include "SamplerStateDX11.h"

using namespace Anubis;

ABOOL SamplerStateDX11::Create(const D3D11_SAMPLER_DESC * params)
{
	HRESULT hr = D3D11Device()->CreateSamplerState(params, &m_pState);
	
	VALID(hr);
}

AVOID SamplerStateDX11::Set(AUINT16 slot, ShaderType type) const
{
	switch(type)
	{
	case ST_Vertex:
		D3D11DeviceContext()->VSSetSamplers(slot, 1, &m_pState);
		break;
	case ST_Hull:
		D3D11DeviceContext()->HSSetSamplers(slot, 1, &m_pState);
		break;
	case ST_Domain:
		D3D11DeviceContext()->DSSetSamplers(slot, 1, &m_pState);
		break;
	case ST_Geometry:
		D3D11DeviceContext()->GSSetSamplers(slot, 1, &m_pState);
		break;
	case ST_Pixel:
		D3D11DeviceContext()->PSSetSamplers(slot, 1, &m_pState);
		break;
	case ST_Compute:
		D3D11DeviceContext()->CSSetSamplers(slot, 1, &m_pState);
		break;
	};
}