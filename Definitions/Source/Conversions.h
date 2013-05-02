#pragma once
//========================================================================
// Graphics.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "Types.h"
#include "Conventions.h"
#include "Casting.h"

namespace Anubis
{
	///////////////////////////////////////////
	//Methods one may need for cross-platform
	///////////////////////////////////////////

	AINLINE	AUINT16 swap16( AUINT16 n )
	{
		return ((n & 0x00FF) << 8) |
			((n & 0xFF00) >> 8);
	}

	AINLINE	AUINT32	swap32( AUINT32 n )
	{
		return ((n & 0x000000FF) << 24) |
			((n & 0x0000FF00) << 8)	|
			((n & 0x00FF0000) >> 8) |
			((n & 0xFF000000) >> 24);
	}

	//AINLINE AREAL32 swapReal32( AREAL32 f )
	//{
	//	AUINT32 i = safe_cast(f, AUINT32);
	//	i = swap32(i);

	//	f = safe_cast(i, AREAL32);
	//	return f;
	//}
}; //Anubis