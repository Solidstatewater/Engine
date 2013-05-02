#pragma once
//========================================================================
// Graphics.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "../../../Base/Resources/Textures/TexturesBase.h"
#include "../Views/ShaderResourceViewDX11.h"
#include "../Views/UnorderedAccessViewDX11.h"
#include "../Views/RenderTargetViewDX11.h"
#include "../Views/DepthStencilViewDX11.h"

#include "../ResourceDX11.h"

namespace Anubis
{
	class TextureDX11 : public ResourceDX11
	{
	public:
		/****
			==========================================
				Shader Resource View Creation
			==========================================
													 ****/
		AVIRTUAL ABOOL CreateShaderResourceView(ShaderResourceViewDX11 & view, 
			const ShaderResourceViewParamsDX11 * params)	const = 0;

		AVIRTUAL ABOOL CreateShaderResourceView(ID3D11ShaderResourceView** ppView, 
			const ShaderResourceViewParamsDX11 * params)	const = 0;

		/****
			==========================================
				Unordered Access View Creation
			==========================================
													 ****/

		AVIRTUAL ABOOL CreateUnorderedAccessView(UnorderedAccessViewDX11 & view,
			const UnorderedAccessViewParamsDX11 * params)	const = 0;

		AVIRTUAL ABOOL CreateUnorderedAccessView(ID3D11UnorderedAccessView** ppView,
			const UnorderedAccessViewParamsDX11 * params)	const = 0;

		/****
			==========================================
				Render Target View Creation
			==========================================
													 ****/

		AVIRTUAL ABOOL CreateRenderTargetView(RenderTargetViewDX11 & view, 
			const RenderTargetViewParamsDX11 * params)		const = 0;

		AVIRTUAL ABOOL CreateRenderTargetView(ID3D11RenderTargetView** ppView, 
			const RenderTargetViewParamsDX11 * params)		const = 0;

		/****
			==========================================
				Depth Stencil View Creation
			==========================================
													 ****/

		AVIRTUAL ABOOL CreateDepthStencilView(DepthStencilViewDX11 & view, 
			const DepthStencilViewParamsDX11 * params)		const = 0;

		AVIRTUAL ABOOL CreateDepthStencilView(ID3D11DepthStencilView** ppView, 
			const DepthStencilViewParamsDX11 * params)		const = 0;
	};

	class Texture1DDX11 : public TextureDX11
	{
	public :

		//constructor
		Texture1DDX11() : TextureDX11()
		{
			m_pTexture = NULL;
		}

		AVIRTUAL ABOOL Create(const D3D11_TEXTURE1D_DESC* pParams);

		//TextureDX11 Implementation

		/****
			==========================================
				Shader Resource View Creation
			==========================================
													 ****/
		AVIRTUAL ABOOL CreateShaderResourceView(ShaderResourceViewDX11 & view, 
			const ShaderResourceViewParamsDX11 * params)	const;

		AVIRTUAL ABOOL CreateShaderResourceView(ID3D11ShaderResourceView** ppView, 
			const ShaderResourceViewParamsDX11 * params)	const;

		/****
			==========================================
				Unordered Access View Creation
			==========================================
													 ****/

		AVIRTUAL ABOOL CreateUnorderedAccessView(UnorderedAccessViewDX11 & view,
			const UnorderedAccessViewParamsDX11 * params)	const;

		AVIRTUAL ABOOL CreateUnorderedAccessView(ID3D11UnorderedAccessView** ppView,
			const UnorderedAccessViewParamsDX11 * params)	const;

		/****
			==========================================
				Render Target View Creation
			==========================================
													 ****/

		AVIRTUAL ABOOL CreateRenderTargetView(RenderTargetViewDX11 & view, 
			const RenderTargetViewParamsDX11 * params)		const;

		AVIRTUAL ABOOL CreateRenderTargetView(ID3D11RenderTargetView** ppView, 
			const RenderTargetViewParamsDX11 * params)		const;

		/****
			==========================================
				Depth Stencil View Creation
			==========================================
													 ****/

		AVIRTUAL ABOOL CreateDepthStencilView(DepthStencilViewDX11 & view, 
			const DepthStencilViewParamsDX11 * params)		const;

		AVIRTUAL ABOOL CreateDepthStencilView(ID3D11DepthStencilView** ppView, 
			const DepthStencilViewParamsDX11 * params)		const;

		//ResourceDX11 Implementation
		AVIRTUAL ID3D11Resource* GetResourcePointer() const { return m_pTexture; }

	protected:
		ID3D11Texture1D*	m_pTexture;
	};

	class Texture2DDX11 : public TextureDX11
	{
	public:
		//Constructor
		Texture2DDX11() : TextureDX11() 
		{
			m_pTexture = NULL;
		}

		AVIRTUAL ABOOL Create(const D3D11_TEXTURE2D_DESC* pParams);

		//TextureDX11 Implementation

		/****
			==========================================
				Shader Resource View Creation
			==========================================
													 ****/
		AVIRTUAL ABOOL CreateShaderResourceView(ShaderResourceViewDX11 & view, 
			const ShaderResourceViewParamsDX11 * params)	const;

		AVIRTUAL ABOOL CreateShaderResourceView(ID3D11ShaderResourceView** ppView, 
			const ShaderResourceViewParamsDX11 * params)	const;

		/****
			==========================================
				Unordered Access View Creation
			==========================================
													 ****/

		AVIRTUAL ABOOL CreateUnorderedAccessView(UnorderedAccessViewDX11 & view,
			const UnorderedAccessViewParamsDX11 * params)	const;

		AVIRTUAL ABOOL CreateUnorderedAccessView(ID3D11UnorderedAccessView** ppView,
			const UnorderedAccessViewParamsDX11 * params)	const;

		/****
			==========================================
				Render Target View Creation
			==========================================
													 ****/

		AVIRTUAL ABOOL CreateRenderTargetView(RenderTargetViewDX11 & view, 
			const RenderTargetViewParamsDX11 * params)		const;

		AVIRTUAL ABOOL CreateRenderTargetView(ID3D11RenderTargetView** ppView, 
			const RenderTargetViewParamsDX11 * params)		const;

		/****
			==========================================
				Depth Stencil View Creation
			==========================================
													 ****/

		AVIRTUAL ABOOL CreateDepthStencilView(DepthStencilViewDX11 & view, 
			const DepthStencilViewParamsDX11 * params)		const;

		AVIRTUAL ABOOL CreateDepthStencilView(ID3D11DepthStencilView** ppView, 
			const DepthStencilViewParamsDX11 * params)		const;

		//ResourceDX11 Implementation
		AVIRTUAL ID3D11Resource* GetResourcePointer() const { return m_pTexture; }

	protected:
		ID3D11Texture2D*	m_pTexture;
	};

	class Texture3DDX11 : public TextureDX11
	{
	public:

		//constructor
		Texture3DDX11() : TextureDX11()
		{
			m_pTexture = NULL;
		}

		AVIRTUAL ABOOL Create(const D3D11_TEXTURE3D_DESC* pParams);

		//TextureDX11 Implementation

		/****
			==========================================
				Shader Resource View Creation
			==========================================
													 ****/
		AVIRTUAL ABOOL CreateShaderResourceView(ShaderResourceViewDX11 & view, 
			const ShaderResourceViewParamsDX11 * params)	const;

		AVIRTUAL ABOOL CreateShaderResourceView(ID3D11ShaderResourceView** ppView, 
			const ShaderResourceViewParamsDX11 * params)	const;

		/****
			==========================================
				Unordered Access View Creation
			==========================================
													 ****/

		AVIRTUAL ABOOL CreateUnorderedAccessView(UnorderedAccessViewDX11 & view,
			const UnorderedAccessViewParamsDX11 * params)	const;

		AVIRTUAL ABOOL CreateUnorderedAccessView(ID3D11UnorderedAccessView** ppView,
			const UnorderedAccessViewParamsDX11 * params)	const;

		/****
			==========================================
				Render Target View Creation
			==========================================
													 ****/

		AVIRTUAL ABOOL CreateRenderTargetView(RenderTargetViewDX11 & view, 
			const RenderTargetViewParamsDX11 * params)		const;

		AVIRTUAL ABOOL CreateRenderTargetView(ID3D11RenderTargetView** ppView, 
			const RenderTargetViewParamsDX11 * params)		const;

		/****
			==========================================
				Depth Stencil View Creation
			==========================================
													 ****/

		AVIRTUAL ABOOL CreateDepthStencilView(DepthStencilViewDX11 & view, 
			const DepthStencilViewParamsDX11 * params)		const;

		AVIRTUAL ABOOL CreateDepthStencilView(ID3D11DepthStencilView** ppView, 
			const DepthStencilViewParamsDX11 * params)		const;

		//ResourceDX11 Implementation
		AVIRTUAL ID3D11Resource* GetResourcePointer() const { return m_pTexture; }

	protected:
		ID3D11Texture3D*	m_pTexture;
	};

}; //Anubis