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
	class BlendStateDX11
	{
	protected:
		ID3D11BlendState*	m_pState;

	public:
		BlendStateDX11() { m_pState = NULL; }
		~BlendStateDX11() { SAFE_RELEASE(m_pState); }

		ABOOL Create(const D3D11_BLEND_DESC * pParams);
		ABOOL Set() const;
	};
}; //Anubis