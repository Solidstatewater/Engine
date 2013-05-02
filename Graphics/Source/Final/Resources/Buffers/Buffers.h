#pragma once
//========================================================================
// Graphics.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "../../../Graphics_pch.h"
#include "../../../DX11/Resources/Buffers/VertexBufferDX11.h"
#include "../../../DX11/Resources/Buffers/IndexBufferDX11.h"
#include "../../../DX11/Resources/Buffers/ConstantBufferDX11.h"
#include "../../../DX11/Resources/Buffers/StructuredBufferDX11.h"

namespace Anubis
{
	class VertexBuffer : public
		#ifdef ADX11_API
			VertexBufferDX11
		#endif
	{
	};

	class IndexBuffer : public
		#ifdef ADX11_API
			IndexBufferDX11
		#endif
	{
	};

	class ConstantBuffer : public
		#ifdef ADX11_API
			ConstantBufferDX11
		#endif
	{
	};
}; //Anubis