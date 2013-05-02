#pragma once
//========================================================================
// Graphics.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "../ResourceDX11.h"
#include "../ResourceDataDX11.h"

namespace Anubis
{
	class BufferDX11 : public ResourceDX11
	{
	protected:

		enum BufferType 
		{
			VertexBuffer,
			IndexBuffer,
			ConstantBuffer,
			StructuredBuffer,
		};
		BufferType		m_type;
		ID3D11Buffer*	m_pBuffer;

	public:
		BufferDX11() { }
		~BufferDX11() { SAFE_RELEASE(m_pBuffer); }
		ID3D11Resource* GetResourcePointer() const { return (ID3D11Resource*)m_pBuffer; }

		AVOID UpdateSubresource(AUINT32 destSubresource, const BoxDX11 * pBox,
			const APVOID pSrcData, AUINT32 srcRowPitch, AUINT32 srcDepthPitch);

		ABOOL Create(const D3D11_BUFFER_DESC * desc, const SubresourceDataDX11 * pData, const AUINT32 numElements = 0);
	};
};