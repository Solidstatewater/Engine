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
	class ConstantBufferDX11 : public BufferDX11
	{
	public:
		AVOID Set(AUINT16 slot, ShaderType type);
	};
}; //Anubis