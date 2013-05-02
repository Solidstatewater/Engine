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
	class SamplerStateDX11
	{
	protected:
		ID3D11SamplerState*	m_pState;
		
	public:
		SamplerStateDX11() {}
		~SamplerStateDX11() { SAFE_RELEASE(m_pState); }

		ABOOL Create(const D3D11_SAMPLER_DESC * pParams);
		AVOID Set(AUINT16 slot, ShaderType type) const;
	};
}; //Anubis