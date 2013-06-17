#pragma once
//========================================================================
// BlendState.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "../../DX11/States/BlendStateDX11.h"

namespace Anubis
{
	#ifdef ADX11_API
		class RenderTargetBlendParams : public D3D11_RENDER_TARGET_BLEND_DESC
		{
		public:
			RenderTargetBlendParams() { ZeroMemory(this, sizeof(RenderTargetBlendParams)); }
			ABOOL Init(ABOOL blendEnable, AUINT8 srcBlend, AUINT8 destBlend,
				AUINT8 blendOp, AUINT8 srcBlendAlpha, AUINT8 destBlendAlpha, AUINT8 blendOpAlpha,
				AUINT8 renderTargetWriteMask);
		};

		class BlendStateParams : public D3D11_BLEND_DESC
		{
		public:
			BlendStateParams();
			ABOOL Init(ABOOL alphaToCoverageEnable, ABOOL independantBlendEnable,
				RenderTargetBlendParams* targets, AUINT8 numParams);
		};
	#endif

		class BlendState : public
			#ifdef ADX11_API
				BlendStateDX11
			#endif
		{
			BlendState()
#ifdef ADX11_API
					:		BlendStateDX11()
#endif											
			{}
		};
}; //Anubis