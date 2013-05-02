#include "Graphics_pch.h"
#include "../../../Final/General.h"
#include "UnorderedAccessViewDX11.h"

using namespace Anubis;

AVOID UnorderedAccessViewDX11::Set(AUINT16 slot, const AUINT32 * pUAVInitialCounts, ShaderType type)
{
	switch (type)
	{
	case ST_Pixel:
		//m_pDevCon->PSSetUnorderedAccessViews(slot, 1, &view.m_pView);
		break;
	case ST_Compute:
		D3D11DeviceContext()->CSSetUnorderedAccessViews(slot, 1, &m_pView, pUAVInitialCounts);
		break;
	default:
		ASSERT(0);
		break;
	};
}