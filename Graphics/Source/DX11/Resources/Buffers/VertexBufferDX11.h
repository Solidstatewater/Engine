#pragma once
//========================================================================
// Graphics.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "BuffersDX11.h"

namespace Anubis
{
	class VertexBufferDX11 : public BufferDX11
	{
	protected:
		AUINT32 m_vertexSize;
		AUINT32 m_vertexCount;

	public:
		ABOOL Create(const D3D11_BUFFER_DESC * desc, const SubresourceDataDX11 * pData, AUINT32 numElements, AUINT32 elementSize);
		AVOID Set(AUINT16 startSlot, const AUINT32 offset) const;
		AUINT32 Count() const { return m_vertexCount; }
	};
}; //Anubis