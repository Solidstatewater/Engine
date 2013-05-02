#include "Graphics_pch.h"
#include "../../../Final/General.h"
#include "TexturesDX11.h"


using namespace Anubis;

////////////////////////////////////////
//Texture1D Implementation
////////////////////////////////////////
ABOOL Texture1DDX11::CreateShaderResourceView(ShaderResourceViewDX11 & view, 
			const ShaderResourceViewParamsDX11 * params)	const
{
	HRESULT hr = D3D11Device()->CreateShaderResourceView(m_pTexture, params, &view.m_pView);

	VALID(hr);
}

ABOOL Texture1DDX11::CreateShaderResourceView(ID3D11ShaderResourceView** ppView, 
			const ShaderResourceViewParamsDX11 * params)	const
{
	HRESULT hr = D3D11Device()->CreateShaderResourceView(m_pTexture, params, ppView);

	VALID(hr);
}

ABOOL Texture1DDX11::CreateUnorderedAccessView(UnorderedAccessViewDX11 & view,
			const UnorderedAccessViewParamsDX11 * params)	const
{
	HRESULT hr = D3D11Device()->CreateUnorderedAccessView(m_pTexture, params, &view.m_pView);

	VALID(hr);
}

ABOOL Texture1DDX11::CreateUnorderedAccessView(ID3D11UnorderedAccessView** ppView,
			const UnorderedAccessViewParamsDX11 * params)	const
{
	HRESULT hr = D3D11Device()->CreateUnorderedAccessView(m_pTexture, params, ppView);

	VALID(hr);
}

ABOOL Texture1DDX11::CreateRenderTargetView(RenderTargetViewDX11 & view, 
			const RenderTargetViewParamsDX11 * params)		const
{
	HRESULT hr = D3D11Device()->CreateRenderTargetView(m_pTexture, params, &view.m_pView);
	 
	VALID(hr);
}

ABOOL Texture1DDX11::CreateRenderTargetView(ID3D11RenderTargetView** ppView, 
			const RenderTargetViewParamsDX11 * params)		const
{
	HRESULT hr = D3D11Device()->CreateRenderTargetView(m_pTexture, params, ppView);
	 
	VALID(hr);
}

ABOOL Texture1DDX11::CreateDepthStencilView(DepthStencilViewDX11 & view, 
			const DepthStencilViewParamsDX11 * params)		const
{
	HRESULT hr = D3D11Device()->CreateDepthStencilView(m_pTexture, params, &view.m_pView);

	VALID(hr);
}

ABOOL Texture1DDX11::CreateDepthStencilView(ID3D11DepthStencilView** ppView, 
			const DepthStencilViewParamsDX11 * params)		const
{
	HRESULT hr = D3D11Device()->CreateDepthStencilView(m_pTexture, params, ppView);

	VALID(hr);
}

ABOOL Texture1DDX11::Create(const D3D11_TEXTURE1D_DESC* pParams)
{
	HRESULT hr = D3D11Device()->CreateTexture1D(pParams, NULL, &m_pTexture);
	
	VALID(hr);
}

////////////////////////////////////////
//Texture2D Implementation
////////////////////////////////////////
ABOOL Anubis::Texture2DDX11::CreateShaderResourceView(ShaderResourceViewDX11 & view, 
			const ShaderResourceViewParamsDX11 * params)	const
{
	HRESULT hr = D3D11Device()->CreateShaderResourceView(m_pTexture, params, &view.m_pView);

	VALID(hr);
}
ABOOL Anubis::Texture2DDX11::CreateShaderResourceView(ID3D11ShaderResourceView** ppView, 
			const ShaderResourceViewParamsDX11 * params)	const
{
	HRESULT hr = D3D11Device()->CreateShaderResourceView(m_pTexture, params, ppView);

	VALID(hr);
}


ABOOL Texture2DDX11::CreateUnorderedAccessView(UnorderedAccessViewDX11 & view,
			const UnorderedAccessViewParamsDX11 * params)	const
{
	HRESULT hr = D3D11Device()->CreateUnorderedAccessView(m_pTexture, params, &view.m_pView);

	VALID(hr);
}
ABOOL Texture2DDX11::CreateUnorderedAccessView(ID3D11UnorderedAccessView** ppView,
			const UnorderedAccessViewParamsDX11 * params)	const
{
	HRESULT hr = D3D11Device()->CreateUnorderedAccessView(m_pTexture, params, ppView);

	VALID(hr);
}


ABOOL Texture2DDX11::CreateRenderTargetView(RenderTargetViewDX11 & view, 
			const RenderTargetViewParamsDX11 * params)		const
{
	HRESULT hr = D3D11Device()->CreateRenderTargetView(m_pTexture, params, &view.m_pView);
	 
	VALID(hr);
}

ABOOL Texture2DDX11::CreateRenderTargetView(ID3D11RenderTargetView** ppView, 
			const RenderTargetViewParamsDX11 * params)		const
{
	HRESULT hr = D3D11Device()->CreateRenderTargetView(m_pTexture, params, ppView);
	 
	VALID(hr);
}

ABOOL Texture2DDX11::CreateDepthStencilView(DepthStencilViewDX11 & view, 
			const DepthStencilViewParamsDX11 * params)		const
{
	HRESULT hr = D3D11Device()->CreateDepthStencilView(m_pTexture, params, &view.m_pView);

	VALID(hr);
}

ABOOL Texture2DDX11::CreateDepthStencilView(ID3D11DepthStencilView** ppView, 
			const DepthStencilViewParamsDX11 * params)		const
{
	HRESULT hr = D3D11Device()->CreateDepthStencilView(m_pTexture, params, ppView);

	VALID(hr);
}

ABOOL Texture2DDX11::Create(const D3D11_TEXTURE2D_DESC* pParams)
{
	HRESULT hr = D3D11Device()->CreateTexture2D(pParams, NULL, &m_pTexture);
	
	VALID(hr);
}

////////////////////////////////////////
//Texture3D Implementation
////////////////////////////////////////
ABOOL Texture3DDX11::CreateShaderResourceView(ShaderResourceViewDX11 & view, 
			const ShaderResourceViewParamsDX11 * params)	const
{
	HRESULT hr = D3D11Device()->CreateShaderResourceView(m_pTexture, params, &view.m_pView);

	VALID(hr);
}

ABOOL Texture3DDX11::CreateShaderResourceView(ID3D11ShaderResourceView** ppView, 
			const ShaderResourceViewParamsDX11 * params)	const
{
	HRESULT hr = D3D11Device()->CreateShaderResourceView(m_pTexture, params, ppView);

	VALID(hr);
}

ABOOL Texture3DDX11::CreateUnorderedAccessView(UnorderedAccessViewDX11 & view,
			const UnorderedAccessViewParamsDX11 * params)	const
{
	HRESULT hr = D3D11Device()->CreateUnorderedAccessView(m_pTexture, params, &view.m_pView);

	VALID(hr);
}

ABOOL Texture3DDX11::CreateUnorderedAccessView(ID3D11UnorderedAccessView** ppView,
			const UnorderedAccessViewParamsDX11 * params)	const
{
	HRESULT hr = D3D11Device()->CreateUnorderedAccessView(m_pTexture, params, ppView);

	VALID(hr);
}

ABOOL Texture3DDX11::CreateRenderTargetView(RenderTargetViewDX11 & view, 
			const RenderTargetViewParamsDX11 * params)		const
{
	HRESULT hr = D3D11Device()->CreateRenderTargetView(m_pTexture, params, &view.m_pView);
	 
	VALID(hr);
}

ABOOL Texture3DDX11::CreateRenderTargetView(ID3D11RenderTargetView** ppView, 
			const RenderTargetViewParamsDX11 * params)		const
{
	HRESULT hr = D3D11Device()->CreateRenderTargetView(m_pTexture, params, ppView);
	 
	VALID(hr);
}

ABOOL Texture3DDX11::CreateDepthStencilView(DepthStencilViewDX11 & view, 
			const DepthStencilViewParamsDX11 * params)		const
{
	HRESULT hr = D3D11Device()->CreateDepthStencilView(m_pTexture, params, &view.m_pView);

	VALID(hr);
}

ABOOL Texture3DDX11::CreateDepthStencilView(ID3D11DepthStencilView** ppView, 
			const DepthStencilViewParamsDX11 * params)		const
{
	HRESULT hr = D3D11Device()->CreateDepthStencilView(m_pTexture, params, ppView);

	VALID(hr);
}

ABOOL Texture3DDX11::Create(const D3D11_TEXTURE3D_DESC* pParams)
{
	HRESULT hr = D3D11Device()->CreateTexture3D(pParams, NULL, &m_pTexture);
	
	VALID(hr);
}