#include "Graphics_pch.h"
#include "../../../Final/General.h"
#include "RasterizerDX11.h"

using namespace Anubis;

ABOOL ViewportDX11::Init(AREAL topleftX, AREAL topleftY, AREAL width, AREAL height,
						 AREAL mindepth, AREAL maxdepth)
{
	TopLeftX = topleftX;
	TopLeftY = topleftY;
	Width = width;
	Height = height;
	MinDepth = mindepth;
	MaxDepth = maxdepth;

	return true;
}

AVOID ViewportDX11::Set(AUINT8 slot) const
{
	D3D11DeviceContext()->RSSetViewports(1, this);
}