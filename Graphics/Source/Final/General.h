#pragma once

#include "Resources\Views\Views.h"
#include "Other\Viewport.h"

namespace Anubis
{
	/**
		// Global methods
	**/

	//*** Initialize graphics API ***//
	//------------------------------------------
	//-- 1: Handle to the window
	//-- 2: Window width
	//-- 3: Window height
	//------------------------------------------
	ABOOL InitializeGraphics(HWND hwnd, AUINT32 width, AUINT32 height);

	//*** Fill render target with color ***//
	//------------------------------------------
	//-- 1: Color to fill with in float[4] format
	//-- 2*: Render target to fill
	//------------------------------------------
	AVOID ClearRenderTargetView(const AREAL32 * color, RenderTargetView * pView);

	//*** Fill render target with color ***//
	//------------------------------------------
	//-- 1: Set to true if we need to clean depth
	//-- 2: Set to true if we need to clean stencil
	//-- 3: Value to fill depth buffer
	//-- 4: Value to fill stencil buffer
	//-- 5*: Depth stencil view to fill
	//------------------------------------------
	AVOID ClearDepthStencilView(ABOOL depth, ABOOL stencil, AREAL32 depthValue, 
		AUINT8 stencilValue, DepthStencilView * pView);

	//*** Unbind shader resource views from the pipeline ***/
	//----------------------------------------------------------
	//-- 1: Slot to unbind
	//-- 2: Number of views
	//-- 3: Shader type to unbind from
	//----------------------------------------------------------
	AVOID UnbindShaderResourceViews(AUINT16 slot, AUINT8 numviews, ShaderType shadertype);

	//*** Unbind render target views from the pipeline ***/
	//--------------------------------------------------------
	//-- 1: Number of views
	//--------------------------------------------------------
	AVOID UnbindRenderTargetViews(AUINT8 numviews);

	/**
		// Global variables
	**/
	static RenderTargetView*			g_pRenderTargetView		= NULL; //back buffer render target
	static DepthStencilView*			g_pDepthStencilView		= NULL; //back buffer depth stencil

	static Viewport*					g_pViewport				= NULL; //main viewport

	#ifdef ADX11_API
		static ID3D11Device*			g_d3d11Device			= NULL;	//directx device pointer
		static ID3D11DeviceContext*		g_d3d11DeviceContext	= NULL; //directx device context pointer
		static IDXGISwapChain*			g_SwapChain				= NULL; //directx swap chain pointer
	#endif

	/**
		//Global getters
	*/
	RenderTargetView * GetRenderTargetView();
	AVOID SetRenderTargetView();

	#ifdef ADX11_API	//directX 11 specific
		ID3D11Device*			D3D11Device();
		ID3D11DeviceContext*	D3D11DeviceContext();
		ID3D11DeviceContext*	D3D11DevCon();
	#endif

	/**
		// Dispatch and drawing methods
	**/
	AVOID Dispatch(AUINT32 groupCountX, AUINT32 groupCountY, AUINT32 groupCountZ);
	AVOID Draw(AUINT32 vertexCount, AUINT32 startVertexLocation);
	AVOID DrawIndexed(AUINT32 indexCount, AUINT32 startIndexLocation, AINT32 baseVertexLocation);

	/**
		// Presenting Back Buffer
	**/
	AVOID PresentBackBuffer();

	/**
		// Clean up methods
	**/
	AVOID CleanUpGraphics();

}; //Anubis