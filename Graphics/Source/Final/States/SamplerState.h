#pragma once
//========================================================================
// SamplerState.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "../../DX11/States/SamplerStateDX11.h"

namespace Anubis
{
	#ifdef ADX11_API
		class SamplerStateParams : public D3D11_SAMPLER_DESC
		{
		public:
			SamplerStateParams() { ZeroMemory(this, sizeof(SamplerStateParams)); }
			ABOOL Init(D3D11_FILTER Filter, D3D11_TEXTURE_ADDRESS_MODE AddressU,
				D3D11_TEXTURE_ADDRESS_MODE AddressV, D3D11_TEXTURE_ADDRESS_MODE AddressW,
				AREAL32 MipLODBias, AUINT32 MaxAnisotropy, D3D11_COMPARISON_FUNC ComparisonFunc,
				AREAL32* BorderColor = NULL, AREAL32 MinLOD = 0, AREAL32 MaxLOD = MAX_FLOAT32);
		};
	#endif

		class SamplerState : public
			#ifdef ADX11_API
				SamplerStateDX11
			#endif
		{
		public:
			SamplerState()
#ifdef ADX11_API
			:	SamplerStateDX11()
#endif
			{}
		};
}; //Anubis