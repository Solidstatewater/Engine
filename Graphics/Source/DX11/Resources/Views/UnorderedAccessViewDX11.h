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
	class UnorderedAccessViewParamsDX11 : public D3D11_UNORDERED_ACCESS_VIEW_DESC
	{
	public:
		UnorderedAccessViewParamsDX11() { ZeroMemory(this, sizeof(UnorderedAccessViewParamsDX11)); }
		ABOOL InitForTexture2D( AUINT8 format,
								AUINT16 mipslice);
	};

	class UnorderedAccessViewDX11
	{
	public:
		ID3D11UnorderedAccessView*	m_pView;

	public:
		UnorderedAccessViewDX11() {}
		~UnorderedAccessViewDX11() { SAFE_RELEASE(m_pView); }

		AVOID Set(AUINT16 slot, const AUINT32 * pUAVInitialCounts, ShaderType type);
	};
}; //Anubis