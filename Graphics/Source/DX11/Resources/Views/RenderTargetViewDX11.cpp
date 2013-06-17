#include "Graphics_pch.h"
#include "../../../Final/General.h"
#include "RenderTargetViewDX11.h"

using namespace Anubis;

/** ==
	RenderTargetViewParamsDX11
== **/
ABOOL RenderTargetViewParamsDX11::InitForTexture2D(	AUINT8 format,
													AUINT16 mipslice)
{
	Format = static_cast<DXGI_FORMAT>(format);
	Texture2D.MipSlice = mipslice;
	ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;

	return true;
}

/** ==
	RenderTargetViewDX11
== **/
AVOID RenderTargetViewDX11::Set(const DepthStencilViewDX11 & depthview) const
{
	D3D11DeviceContext()->OMSetRenderTargets(1, &m_pView, depthview.m_pView);
}

AVOID RenderTargetViewDX11::Set() const
{
	D3D11DeviceContext()->OMSetRenderTargets(1, &m_pView, NULL);
}

AVOID RenderTargetViewDX11::Clear(const AREAL * bgColor)
{
	D3D11DeviceContext()->ClearRenderTargetView(m_pView, bgColor);
}

AVOID RenderTargetViewDX11::Clear()
{
	const AREAL color[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
	D3D11DeviceContext()->ClearRenderTargetView(m_pView, color);
}

/** ==
	RenderTargetViewListDX11
== **/
RenderTargetViewListDX11::RenderTargetViewListDX11(AUINT8 numViews)
	: m_numViews(numViews)
{
	//Initialze array of pointers to shader resource views
	m_ppViews = new ID3D11RenderTargetView*[numViews];
}

RenderTargetViewListDX11::~RenderTargetViewListDX11()
{
	AUINT8 i;
	for (i = (m_numViews - 1); i > 0; i--)
		SAFE_RELEASE(m_ppViews[i]);

	SAFE_DELETE_ARRAY(m_ppViews);
}

ID3D11RenderTargetView** RenderTargetViewListDX11::GetView(AUINT8 index) const
{
	return &m_ppViews[index];
}

AVOID RenderTargetViewListDX11::Set() const
{
	D3D11DeviceContext()->OMSetRenderTargets(m_numViews, m_ppViews, NULL);
}

AVOID RenderTargetViewListDX11::Clear(const AREAL * bgColor)
{
	AUINT8 i;
	for (i = (m_numViews - 1); i > 0; i--)
		D3D11DeviceContext()->ClearRenderTargetView(m_ppViews[i], bgColor);
}

AVOID RenderTargetViewListDX11::Clear()
{
	const AREAL color[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
	AUINT8 i;

	for (i = (m_numViews - 1); i > 0; i--)
		D3D11DeviceContext()->ClearRenderTargetView(m_ppViews[i], color);
}