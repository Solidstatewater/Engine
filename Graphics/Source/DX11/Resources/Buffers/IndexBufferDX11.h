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
	class IndexBufferDX11 : public BufferDX11
	{
	protected:
		DXGI_FORMAT m_format;

	public:
		AVOID Set(AUINT16 offset) const;
	};

}; //Anubis