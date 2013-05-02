#include "Graphics_pch.h"
#include "../../../Final/General.h"
#include "VertexBufferDX11.h"

using namespace Anubis;

AVOID VertexBufferDX11::Set(AUINT16 startSlot, const AUINT32 offset) const
{
	D3D11DeviceContext()->IASetVertexBuffers(startSlot, 1, &m_pBuffer, &m_vertexSize, &offset);
}


ABOOL VertexBufferDX11::Create(const D3D11_BUFFER_DESC * desc, const SubresourceDataDX11 * pData, AUINT32 numElements, AUINT32 elementSize)
{
	m_vertexCount = numElements;
	m_vertexSize = elementSize;

	return BufferDX11::Create(desc, pData, numElements);
}