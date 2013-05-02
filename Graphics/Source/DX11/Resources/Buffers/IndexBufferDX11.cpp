#include "Graphics_pch.h"
#include "../../../Final/General.h"
#include "IndexBufferDX11.h"

using namespace Anubis;

AVOID IndexBufferDX11::Set(AUINT16 offset) const
{
	D3D11DeviceContext()->IASetIndexBuffer(m_pBuffer, m_format, offset);
}