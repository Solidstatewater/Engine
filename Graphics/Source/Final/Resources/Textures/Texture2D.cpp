#include "Graphics_pch.h"
#include "Texture2D.h"

using namespace Anubis;

ABOOL Texture2DParams::Init(AUINT32 width,
							AUINT32 height,
							AUINT16 arraySize,
							AUINT8  format,
							ABOOL	shaderResource,
							ABOOL	unorderedAccess,
							ABOOL	renderTarget,
							ABOOL   depthStencil,
							AUINT16 sampleCount,
							AUINT16 sampleQuality,
							AUINT16 miplevels,
							ABOOL	gpuWrite,
							ABOOL	cpuRead,
							ABOOL	cpuWrite)
{
#ifdef ADX11_API
	Width = width;
	Height = height;
	ArraySize = arraySize;
	Format = (DXGI_FORMAT)format;
	SampleDesc.Count = sampleCount;
	SampleDesc.Quality = sampleQuality;
	MipLevels = miplevels;

	//set level of accessebility by CPU and GPU
	if (cpuRead && cpuWrite && gpuWrite)
	{
		Usage = D3D11_USAGE_STAGING;
		CPUAccessFlags = D3D11_CPU_ACCESS_READ | D3D11_CPU_ACCESS_WRITE;
	}
	else if (gpuWrite && !cpuRead && !cpuWrite)
	{
		Usage = D3D11_USAGE_DEFAULT;
	}
	else if (cpuWrite && !cpuRead && !gpuWrite)
	{
		Usage = D3D11_USAGE_DYNAMIC;
		CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	}
	else
	{
		Usage = D3D11_USAGE_IMMUTABLE;
	}

	//Set resource binding types
	if (shaderResource)
		BindFlags |= D3D11_BIND_SHADER_RESOURCE;
	if (renderTarget)
		BindFlags |= D3D11_BIND_RENDER_TARGET;
	if (unorderedAccess)
		BindFlags |= D3D11_BIND_UNORDERED_ACCESS;
	if (depthStencil)
		BindFlags |= D3D11_BIND_DEPTH_STENCIL;
#endif

	return true;
} 