#include "Graphics_pch.h"
#include "BufferParams.h"

using namespace Anubis;

ABOOL BufferParams::FillVertexBufferParams( AUINT32 vertexSize, AUINT32 count,
											ABOOL gpuWrite, ABOOL cpuRead, ABOOL cpuWrite, ABOOL stream)
{
	ZeroMemory(this, sizeof(D3D11_BUFFER_DESC));
	ByteWidth = vertexSize * count;
	
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

	if (stream)
		BindFlags = D3D11_BIND_VERTEX_BUFFER | D3D11_BIND_STREAM_OUTPUT;
	else
		BindFlags = D3D11_BIND_VERTEX_BUFFER;

	return true;
}

ABOOL BufferParams::FillIndexBufferParams(AUINT32 indexSize, AUINT32 count,
										 ABOOL gpuWrite, ABOOL cpuRead, ABOOL cpuWrite, ABOOL stream)
{
	ZeroMemory(this, sizeof(D3D11_BUFFER_DESC));
	ByteWidth = indexSize * count;
	
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

	if (stream)
		BindFlags = D3D11_BIND_INDEX_BUFFER | D3D11_BIND_STREAM_OUTPUT;
	else
		BindFlags = D3D11_BIND_INDEX_BUFFER;

	return true;
}

ABOOL BufferParams::FillConstantBufferParams(AUINT32 size,
					ABOOL gpuWrite, ABOOL cpuRead, ABOOL cpuWrite)
{
	ZeroMemory(this, sizeof(D3D11_BUFFER_DESC));
	ByteWidth = size;
	
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

	BindFlags = D3D11_BIND_CONSTANT_BUFFER;

	return true;
}