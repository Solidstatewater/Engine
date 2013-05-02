#pragma once
//========================================================================
// BufferParams.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "../../../Graphics_pch.h"

namespace Anubis
{
	class BufferParams : public
		#ifdef ADX11_API
			D3D11_BUFFER_DESC
		#endif
	{
	public:
		ABOOL FillVertexBufferParams( AUINT32 vertexSize, AUINT32 count,
										ABOOL gpuWrite, ABOOL cpuRead, ABOOL cpuWrite, ABOOL stream);

		ABOOL FillIndexBufferParams(AUINT32 indexSize, AUINT32 count,
										ABOOL gpuWrite, ABOOL cpuRead, ABOOL cpuWrite, ABOOL stream);

		ABOOL FillConstantBufferParams(AUINT32 size,
										ABOOL gpuWrite, ABOOL cpuRead, ABOOL cpuWrite);

		ABOOL FillStructredBufferParams();

		/** ================
			==	Mutators  ==
			================
							 **/
		AINLINE AVOID SetSize(AUINT32 size) { ByteWidth = size; }
	};
}; //Anubis