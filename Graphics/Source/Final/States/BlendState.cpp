#include "Graphics_pch.h"
#include "BlendState.h"

using namespace Anubis;

ABOOL RenderTargetBlendParams::Init(ABOOL blendEnable, AUINT8 srcBlend, AUINT8 destBlend,
			AUINT8 blendOp, AUINT8 srcBlendAlpha, AUINT8 destBlendAlpha, AUINT8 blendOpAlpha,
			AUINT8 renderTargetWriteMask)
{
	BlendEnable				= blendEnable;
	SrcBlend				= (D3D11_BLEND)srcBlend;
	DestBlend				= (D3D11_BLEND)destBlend;
	BlendOp					= (D3D11_BLEND_OP)blendOp;
	SrcBlendAlpha			= (D3D11_BLEND)srcBlendAlpha;
	DestBlendAlpha			= (D3D11_BLEND)destBlendAlpha;
	BlendOpAlpha			= (D3D11_BLEND_OP)blendOpAlpha;
	RenderTargetWriteMask	= renderTargetWriteMask;

	return true;
}

ABOOL BlendStateParams::Init(ABOOL alphaToCoverageEnable, ABOOL independentBlendEnable,
			RenderTargetBlendParams* targets, AUINT8 numParams)
{
	AlphaToCoverageEnable = alphaToCoverageEnable;
	IndependentBlendEnable = independentBlendEnable;
	
	for (int i = 0; i < numParams; i++)
		RenderTarget[i] = targets[i];

	return true;
}