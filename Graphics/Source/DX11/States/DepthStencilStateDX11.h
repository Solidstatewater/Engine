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
		DepthStencilStateDX11() {}
		~DepthStencilStateDX11() { SAFE_RELEASE(m_pState); }
	};
}; //Anubis