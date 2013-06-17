#pragma once
//========================================================================
// DepthStencilState.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "../../DX11/States/DepthStencilStateDX11.h"

namespace Anubis
{
	#ifdef ADX11_API
		class DepthStencilParams : public D3D11_DEPTH_STENCIL_DESC
		{
		public:
			DepthStencilParams() { ZeroMemory(this, sizeof(DepthStencilParams)); }
			ABOOL Init(ABOOL depthEnable, D3D11_COMPARISON_FUNC depthFunc,
				ABOOL stencilEnable, AUINT8 stencilReadMask, AUINT8 stencilWriteMask);
		};
	#endif

		class DepthStencilState : public
			#ifdef ADX11_API
				DepthStencilStateDX11
			#endif
		{
		public:
			DepthStencilState()
#ifdef ADX11
			:	DepthStencilStateDX11()
#endif
			{};
		};
}; //Anubis