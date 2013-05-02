#include "Graphics_pch.h"
#include "../../../Final/General.h"
#include "ConstantBufferDX11.h"

using namespace Anubis;

AVOID ConstantBufferDX11::Set(AUINT16 slot, ShaderType type)
{
	switch (type)
	{
	case ST_Vertex:
		D3D11DeviceContext()->VSSetConstantBuffers(slot, 1, &m_pBuffer);
		break;
	case ST_Geometry:
		D3D11DeviceContext()->GSSetConstantBuffers(slot, 1, &m_pBuffer);
		break;
	case ST_Pixel:
		D3D11DeviceContext()->PSSetConstantBuffers(slot, 1, &m_pBuffer);
		break;
	default:
		ASSERT(0);
		break;
	};
}