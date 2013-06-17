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
	class DepthStencilViewParamsDX11 : public D3D11_DEPTH_STENCIL_VIEW_DESC
	{
	public:
		DepthStencilViewParamsDX11() { ZeroMemory(this, sizeof(DepthStencilViewParamsDX11)); }
		ABOOL InitForTexture2D( AUINT8 format,
								AUINT16 mipslice);
	};

	class DepthStencilViewDX11
	{
	public:
		ID3D11DepthStencilView*	m_pView;

	public:
		DepthStencilViewDX11() { m_pView = NULL; }
		~DepthStencilViewDX11() { SAFE_RELEASE(m_pView); }
	};
}; //Anubis