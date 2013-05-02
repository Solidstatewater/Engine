#include "Graphics_pch.h"
#include "General.h"

#include "../../../DXUT/DXUT.h"
#include "../../../DXUT/DXUTDevice11.h"

using namespace Anubis;

/**
	// Global methods Implementation
**/
ABOOL Anubis::InitializeGraphics(HWND hwnd, AUINT32 width, AUINT32 height)
{
#ifdef ADX11_API

	//=============================
	// Describe back buffer structure
	DXGI_MODE_DESC bufferDesc;
	ZeroMemory(&bufferDesc, sizeof(DXGI_MODE_DESC)); //zero memory for the structure

	bufferDesc.Width = width;
	bufferDesc.Height = height;
	bufferDesc.RefreshRate.Numerator = 60;
	bufferDesc.RefreshRate.Denominator = 1;
	bufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	//bufferDesc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	bufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	bufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

	//=============================
	//Describe SwapChain structure
	DXGI_SWAP_CHAIN_DESC swapChainDesc; 
	ZeroMemory(&swapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC)); //zero memory for the structure

	swapChainDesc.BufferDesc = bufferDesc; //set created back buffer
	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.SampleDesc.Quality = 0;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT; //use back buffer as render target
	swapChainDesc.BufferCount = 1;
	swapChainDesc.OutputWindow = hwnd; 
	swapChainDesc.Windowed = TRUE; 
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;


	//=============================
	//Create swap chain
	D3D_FEATURE_LEVEL pLevel = D3D_FEATURE_LEVEL_11_0; //set feature desired feature level
	HRESULT hr = D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, D3D11_CREATE_DEVICE_DEBUG, &pLevel, 1,
		D3D11_SDK_VERSION, &swapChainDesc, &g_SwapChain, &g_d3d11Device, NULL, &g_d3d11DeviceContext);

	//Get BackBuffer texture
	ID3D11Texture2D* BackBuffer;
	hr = g_SwapChain->GetBuffer( 0, __uuidof( ID3D11Texture2D ), (void**)&BackBuffer );

	//Create Render Target
	ID3D11RenderTargetView* pRenderTargetView;
	hr = g_d3d11Device->CreateRenderTargetView( BackBuffer, NULL, &pRenderTargetView );
	BackBuffer->Release();

	//Initialize global render target pointer
	g_pRenderTargetView = new RenderTargetView(pRenderTargetView);

	//Set Render Target
	g_d3d11DeviceContext->OMSetRenderTargets( 1, &pRenderTargetView, NULL );

	//Initialize and set viewport
	g_pViewport = new Viewport();
	g_pViewport->Init(0, 0, 1280, 720);
	g_pViewport->Set();

	return true;
#endif //if defined ADX11_API
}

AVOID Anubis::ClearRenderTargetView(const AREAL32 * color, RenderTargetView * pView)
{
	if (!pView)
		D3D11DeviceContext()->ClearRenderTargetView(GetRenderTargetView()->m_pView, color);
	else
		D3D11DeviceContext()->ClearRenderTargetView(pView->m_pView, color);
}

AVOID Anubis::ClearDepthStencilView(ABOOL depth, ABOOL stencil, AREAL32 depthValue, 
		AUINT8 stencilValue, DepthStencilView * pView)
{
	//if (!pView)
	//	D3D11DeviceContext()->ClearDepthStencilView(GetDepthStencilView()->m_pView, 
}

AVOID Anubis::UnbindShaderResourceViews(AUINT16 slot, AUINT8 numviews, ShaderType shadertype)
{
#ifdef ADX11_API
	ID3D11ShaderResourceView* pNullSRV = NULL;

	switch (shadertype)
	{
	case ST_Vertex:
		for (int i = 0; i < numviews; i++)
			D3D11DeviceContext()->VSSetShaderResources(slot+i, 1, &pNullSRV);
		break;
	case ST_Domain:
		for (int i = 0; i < numviews; i++)
			D3D11DeviceContext()->DSSetShaderResources(slot+i, 1, &pNullSRV);
		break;
	case ST_Geometry:
		for (int i = 0; i < numviews; i++)
			D3D11DeviceContext()->VSSetShaderResources(slot+i, 1, &pNullSRV);
		break;
	case ST_Pixel:
		for (int i = 0; i < numviews; i++)
			D3D11DeviceContext()->VSSetShaderResources(slot+i, 1, &pNullSRV);
		break;
	default:
		ASSERT(0);
		break;
	};
#endif
}

AVOID Anubis::UnbindRenderTargetViews(AUINT8 numviews)
{
#ifdef ADX11_API
	ID3D11RenderTargetView* pNullRTV = NULL;
	for (int i = 0; i < numviews; i++)
		D3D11DeviceContext()->OMSetRenderTargets(1, &pNullRTV, NULL);
#endif
}

#ifdef ADX11_API
/**
	//Global getters Implementation
**/
ID3D11Device* Anubis::D3D11Device()
{
#ifdef DXUT11_FW
	return DXUTGetD3D11Device();
#else
	return g_d3d11Device;
#endif
}

ID3D11DeviceContext* Anubis::D3D11DeviceContext()
{
#ifdef DXUT11_FW
	return DXUTGetD3D11DeviceContext();
#else
	return g_d3d11DeviceContext;
#endif
}

ID3D11DeviceContext* Anubis::D3D11DevCon()
{
#ifdef DXUT11_FW
	return DXUTGetD3D11DeviceContext();
#else
	return g_d3d11DeviceContext;
#endif
}

#endif

/**
	//Global getters implementation
**/
RenderTargetView * Anubis::GetRenderTargetView()
{
#ifdef ADX11_API
	#ifdef DXUT11_FW
		return DXUTGetD3D11RenderTargetView();
	#else
		return g_pRenderTargetView;
	#endif
#endif
}

AVOID Anubis::SetRenderTargetView()
{
#ifdef ADX11_API
	#ifdef DXUT11_FW
		DXUTGetD3D11DeviceContext()->OMSetRenderTargets( 1, DXUTGetD3D11RenderTargetView(), NULL );
	#else
		g_d3d11DeviceContext->OMSetRenderTargets( 1, &g_pRenderTargetView->m_pView, NULL );
	#endif
#endif
}


/**
	//Dispatch and drawing methods implementation
**/
AVOID Anubis::Dispatch(AUINT32 groupCountX, AUINT32 groupCountY, AUINT32 groupCountZ)
{
#ifdef ADX11_API
	#ifdef DXUT11_FW
		D3D11DeviceContext()->Dispatch(groupCountX, groupCountY, groupCountZ);
	#else
		g_d3d11DeviceContext->Dispatch(groupCountX, groupCountY, groupCountZ);
	#endif
#endif
}

AVOID Anubis::Draw(AUINT32 vertexCount, AUINT32 startVertexLocation)
{
#ifdef ADX11_API
	#ifdef DXUT11_FW
		D3D11DeviceContext()->Draw(vertexCount, startVertexLocation);
	#else
		g_d3d11DeviceContext->Draw(vertexCount, startVertexLocation);
	#endif
#endif
}

AVOID Anubis::DrawIndexed(AUINT32 indexCount, AUINT32 startIndexLocation, AINT32 baseVertexLocation)
{
#ifdef ADX11_API
	#ifdef DXUT11_FW
		D3D11DeviceContext()->DrawIndexed(indexCount, startIndexLocation, baseVertexLocation);
	#else
		g_d3d11DeviceContext->DrawIndexed(indexCount, startIndexLocation, baseVertexLocation);
	#endif
#endif
}

/**
	// Presenting Back Buffer
**/
AVOID Anubis::PresentBackBuffer()
{
	g_SwapChain->Present(0, 0);
}

/**
		// Clean up methods
**/
AVOID Anubis::CleanUpGraphics()
{
#ifdef ADX11_API
	SAFE_RELEASE(g_d3d11Device);	
	SAFE_RELEASE(g_d3d11DeviceContext);
	SAFE_RELEASE(g_SwapChain);
#endif
}