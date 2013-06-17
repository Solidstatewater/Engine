#include "Graphics_pch.h"
#include "DepthStencilViewDX11.h"

using namespace Anubis;

/** ==
	DepthStencilViewParamsDX11
== **/
ABOOL DepthStencilViewParamsDX11::InitForTexture2D(	AUINT8 format,
													AUINT16 mipslice)
{
	Format = static_cast<DXGI_FORMAT>(format);
	Texture2D.MipSlice = mipslice;
	ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;

	return true;
}