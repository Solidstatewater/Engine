#pragma once
//========================================================================
// Viewport.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================
namespace Anubis
{
	class Viewport : public
		#ifdef ADX11_API
			D3D11_VIEWPORT
		#endif
	{
	public:
		Viewport() { ZeroMemory(this, sizeof(*this)); }
		ABOOL Init(AREAL topLeftX, AREAL topLeftY, AREAL width, AREAL height);

		AVOID Set();
	};
}; //Anubis