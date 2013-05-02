#include "Graphics_pch.h"
#include "../../../Final/General.h"
#include "ShaderResourceViewDX11.h"

using namespace Anubis;

/******************************************
	//// ShaderResourceViewParamsDX11 ////
******************************************/
ABOOL ShaderResourceViewParamsDX11::InitForTexture2D(	AUINT8 format,
														AUINT16 miplevels, 
														AUINT16 mostdetailedmip	)
{
	Format = static_cast<DXGI_FORMAT>(format);
	Texture2D.MipLevels = 1;
	Texture2D.MostDetailedMip = 0;
	ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;

	return true;
}

ABOOL ShaderResourceViewDX11::CreateFromFile(LPCWSTR fileName)
{
	HRESULT hr = D3DX11CreateShaderResourceViewFromFile(D3D11Device(), fileName, nullptr, nullptr, &m_pView, nullptr);
	if (hr != S_OK)
	{
		CheckHR(hr);
		return false;
	}

	return true;
}

/******************************************
	//// ShaderResourceViewDX11 ////
******************************************/
AVOID ShaderResourceViewDX11::Set(AUINT16 slot, ShaderType type) const
{
	switch (type)
	{
	case ST_Vertex:
		D3D11DeviceContext()->VSSetShaderResources(slot, 1, &m_pView);
		break;
	case ST_Domain:
		D3D11DeviceContext()->DSSetShaderResources(slot, 1, &m_pView);
		break;
	case ST_Geometry:
		D3D11DeviceContext()->VSSetShaderResources(slot, 1, &m_pView);
		break;
	case ST_Pixel:
		D3D11DeviceContext()->VSSetShaderResources(slot, 1, &m_pView);
		break;
	default:
		ASSERT(0);
		break;
	};
}

/******************************************
	//// ShaderResourceViewListDX11 ////
******************************************/
ShaderResourceViewListDX11::ShaderResourceViewListDX11(AUINT8 numViews)
	: m_numViews(numViews)
{
	//Initialze array of pointers to shader resource views
	m_ppViews = new ID3D11ShaderResourceView*[numViews];
}

ShaderResourceViewListDX11::~ShaderResourceViewListDX11()
{
	AUINT8 i;
	for (i = (m_numViews - 1); i > 0; i--)
		SAFE_RELEASE(m_ppViews[i]);

	SAFE_DELETE_ARRAY(m_ppViews);
}

ID3D11ShaderResourceView** ShaderResourceViewListDX11::GetView(AUINT8 index) const
{
	return &m_ppViews[index];
}

AVOID ShaderResourceViewListDX11::Set(AUINT16 slot, ShaderType type) const
{
	switch (type)
	{
	case ST_Vertex:
		D3D11DeviceContext()->VSSetShaderResources(slot, m_numViews, m_ppViews);
		break;
	case ST_Domain:
		D3D11DeviceContext()->DSSetShaderResources(slot, m_numViews, m_ppViews);
		break;
	case ST_Geometry:
		D3D11DeviceContext()->VSSetShaderResources(slot, m_numViews, m_ppViews);
		break;
	case ST_Pixel:
		D3D11DeviceContext()->VSSetShaderResources(slot, m_numViews, m_ppViews);
		break;
	default:
		ASSERT(0);
		break;
	};
}