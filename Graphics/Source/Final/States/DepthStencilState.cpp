#include "Graphics_pch.h"
#include "DepthStencilState.h"

using namespace Anubis;

ABOOL DepthStencilParams::Init(ABOOL depthEnable, D3D11_COMPARISON_FUNC depthFunc,
				ABOOL stencilEnable, AUINT8 stencilReadMask, AUINT8 stencilWriteMask)
{
	DepthEnable = depthEnable;
	DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
	DepthFunc = depthFunc;
	StencilEnable = stencilEnable;
	StencilReadMask = stencilReadMask;
	StencilWriteMask = stencilWriteMask;

	return true;
}
