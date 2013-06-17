#pragma once
//========================================================================
// Graphics.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "DepthStencilViewDX11.h"

namespace Anubis
{
	class RenderTargetViewParamsDX11 : public D3D11_RENDER_TARGET_VIEW_DESC
	{
	public:
		RenderTargetViewParamsDX11() { ZeroMemory(this, sizeof(RenderTargetViewParamsDX11)); }
		ABOOL InitForTexture2D( AUINT8 format,
								AUINT16 mipslice);
	};

	class RenderTargetViewDX11
	{
	public:
		ID3D11RenderTargetView*	m_pView;

	public:
		RenderTargetViewDX11() { m_pView = NULL; }
		RenderTargetViewDX11(ID3D11RenderTargetView * const pView) { m_pView = pView; }

		~RenderTargetViewDX11() { SAFE_RELEASE(m_pView); }

		AVOID Set(const DepthStencilViewDX11 & depthview) const;
		AVOID Set() const;
		AVOID Clear(const AREAL * bgColor);
		AVOID Clear();
	};

	class RenderTargetViewListDX11
	{
		ID3D11RenderTargetView**	m_ppViews;
		AUINT8	m_numViews;

	public:
		/*  ==
			Constructor and Destructor
			                          == */
		RenderTargetViewListDX11(AUINT8 numViews);
		~RenderTargetViewListDX11();

		/*** Getters ***/
		ID3D11RenderTargetView** GetView(AUINT8 index) const;

		/* ==
			Bind Shader Resource Views to the pipeline
		== */
		AVOID Set() const;
		AVOID Clear(const AREAL * bgColor);
		AVOID Clear();
	};
}; //Anubis