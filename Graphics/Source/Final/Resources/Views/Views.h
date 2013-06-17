#pragma once
//========================================================================
// Views.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "../../../Graphics_pch.h"
#include "../../../DX11/Resources/Views/ShaderResourceViewDX11.h"
#include "../../../DX11/Resources/Views/UnorderedAccessViewDX11.h"
#include "../../../DX11/Resources/Views/RenderTargetViewDX11.h"
#include "../../../DX11/Resources/Views/DepthStencilViewDX11.h"

namespace Anubis
{
	//=======================================//
		//	Params structures
	//=======================================//
	class ShaderResourceViewParams : public
		#ifdef ADX11_API
			ShaderResourceViewParamsDX11
		#endif
	{
	};

	class UnorderedAccessViewParams : public
		#ifdef ADX11_API
			UnorderedAccessViewParamsDX11
		#endif
	{
	};

	class RenderTargetViewParams : public
		#ifdef ADX11_API
			RenderTargetViewParamsDX11
		#endif
	{
	};

	class DepthStencilViewParams : public
		#ifdef ADX11_API
			DepthStencilViewParamsDX11
		#endif
	{
	};

	//=======================================//
		//	Views
	//=======================================//

	class ShaderResourceView : public
		#ifdef ADX11_API
			ShaderResourceViewDX11
		#endif
	{
	public:
		#ifdef ADX11_API
			ShaderResourceView() : ShaderResourceViewDX11() {}
		#endif
	};

	class UnorderedAccessView : public
		#ifdef ADX11_API
			UnorderedAccessViewDX11
		#endif
	{
	public:
		#ifdef ADX11_API
			UnorderedAccessView() : UnorderedAccessViewDX11() {}
		#endif
	};

	class RenderTargetView : public
		#ifdef ADX11_API
			RenderTargetViewDX11
		#endif
	{
	public:
		#ifdef ADX11_API
			RenderTargetView(ID3D11RenderTargetView * const pView)
				: RenderTargetViewDX11(pView) {}
			RenderTargetView() : RenderTargetViewDX11() {}
		#endif 
	};

	class DepthStencilView : public
		#ifdef ADX11_API
			DepthStencilViewDX11
		#endif
	{
	public:
		#ifdef ADX11_API
			DepthStencilView() : DepthStencilViewDX11() {}
		#endif
	};

	//=======================================//
		//	View Lists
	//=======================================//
	class ShaderResourceViewList : public
		#ifdef ADX11_API
			ShaderResourceViewListDX11
		#endif
	{
		//typedef Parent class
		#ifdef ADX11_API
			typedef ShaderResourceViewListDX11 Parent;
		#endif
			
	public:
		/*** Constructor accepts number of views in the list ***/
		ShaderResourceViewList(AUINT8 numviews) :
			Parent(numviews) {}
	};

	class RenderTargetViewList : public
		#ifdef ADX11_API
			RenderTargetViewListDX11
		#endif
	{
		//typedef Parent class
		#ifdef ADX11_API
			typedef RenderTargetViewListDX11 Parent;
		#endif
			
	public:
		/*** Constructor accepts number of views in the list ***/
		RenderTargetViewList(AUINT8 numviews) :
			Parent(numviews) {}
	};

	//typedefs
	typedef shared_ptr<ShaderResourceView>	ShaderResourceViewPtr;
	typedef shared_ptr<UnorderedAccessView>	UnorderedAccessViewPtr;
	typedef shared_ptr<DepthStencilView>	DepthStencilViewPtr;
	typedef shared_ptr<RenderTargetView>	RenderTargetViewPtr;
}; //Anubis