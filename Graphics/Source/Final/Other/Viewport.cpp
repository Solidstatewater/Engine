#include "Graphics_pch.h"
#include "Viewport.h"

#include "../General.h"

using namespace Anubis;

ABOOL Viewport::Init(AREAL topLeftX, AREAL topLeftY, AREAL width, AREAL height)
{
#ifdef ADX11_API
	TopLeftX = topLeftX;
	TopLeftY = topLeftY;
	Width = width;
	Height = height;
#endif

	return true;
}

AVOID Viewport::Set()
{
#ifdef ADX11_API
	D3D11DeviceContext()->RSSetViewports(1, static_cast<const D3D11_VIEWPORT *>(this));
#endif
}