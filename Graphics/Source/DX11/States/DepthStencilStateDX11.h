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
	class DepthStencilStateDX11
	{
	protected:
		ID3D11DepthStencilState*	m_pState;

	public:
		DepthStencilStateDX11() { m_pState = NULL; }
		~DepthStencilStateDX11() { SAFE_RELEASE(m_pState); }

		ABOOL Create(const D3D11_DEPTH_STENCIL_DESC * params);

		AVOID Set(const AUINT32 stencilRef) const;
	};
}; //Anubis