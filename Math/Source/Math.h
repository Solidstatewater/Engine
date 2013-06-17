#pragma once
//========================================================================
// Math.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include <math.h>
#include "Mat4x4.h"

namespace Anubis
{
	/*************************************
				Trigonometry
	*************************************/
	AREAL32 CosR32( AREAL32 angleInRadians );
	AREAL64 CosR64( AREAL64 angleInRadians );
	AREAL64 Cos	  ( AREAL64 angleInRadians );

	AREAL32 SinR32( AREAL32 angleInRadians );
	AREAL64 SinR64( AREAL64 angleInRadians );
	AREAL64 Sin	  ( AREAL64 angleInRadians );

	AREAL32 TgR32 ( AREAL32 angleInRadians );
	AREAL64 TgR64 ( AREAL64 angleInRadians );
	AREAL64 Tg	  ( AREAL64 angleInRadians );

	AREAL32 CtgR32( AREAL32 angleInRadians );
	AREAL64 CtgR64( AREAL64 angleInRadians );
	AREAL64 Ctg	  ( AREAL64 angleInRadians );

	AREAL32 Atan2R32( AREAL32 y, AREAL32 x );
	AREAL64 Atan2R64( AREAL64 y, AREAL32 x );
	AREAL64 Atan2	( AREAL64 y, AREAL64 x );

	//AREAL64 Dot(Vec v1, Vec v2) { 
	AREAL32 SqrtR32(AREAL32 x);
	AREAL64 SqrtR64(AREAL64 x);
	AREAL64 Sqrt(AREAL64 x);

	/* ======================================
					Vectors
	========================================= */
	AREAL Dot(const Vec& v1, const Vec& v2);
	AREAL Length(const Vec & v);
	Vec Normalize(const Vec & v);

	/* ======================================
					Matrices
	========================================= */
	Mat4x4 CreateViewMatrixLH(const Vec & pos, const Vec & lookAt, const Vec & up);
	Mat4x4 CreatePerspectiveProjectionLH(	const AREAL fov,	const AREAL aspect,
											const AREAL nearZ,	const AREAL farZ );
	Mat4x4 CreateOrthoProjectionLH(	const AREAL width,	const AREAL height,
									const AREAL nearZ,	const AREAL farZ);
};