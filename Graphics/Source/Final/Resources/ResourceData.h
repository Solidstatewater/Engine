#pragma once
//========================================================================
// Graphics.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "../../DX11/Resources/ResourceDX11.h"
#include "../../DX11/Resources/ResourceDataDX11.h"

namespace Anubis
{
	class Box : public
		#ifdef ADX11_API
			BoxDX11
		#endif
	{
	};
	
	struct SubresourceData : public
		#ifdef ADX11_API
			SubresourceDataDX11
		#endif
	{
		AVOID SetData(const void* pData, AUINT32 sysMemPitch = 0, AUINT32 sysMemSlicePitch = 0);
	};
};