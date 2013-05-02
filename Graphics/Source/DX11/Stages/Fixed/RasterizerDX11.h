#pragma once
//========================================================================
// Graphics.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

namespace Anubis
{
	class ViewportDX11 : public D3D11_VIEWPORT
	{
	public:
		ViewportDX11() { ZeroMemory(this, sizeof(ViewportDX11)); }
		ABOOL Init(AREAL topleftX, AREAL topleftY, AREAL width, AREAL height,
						 AREAL mindepth, AREAL maxdepth);

		AVOID Set(AUINT8 slot = 1) const;
	};
}; //Anubis