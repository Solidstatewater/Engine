#include "Math_pch.h"
#include "Math.h"

using namespace Anubis;

/*************************************
			Trigonometry
*************************************/

/**************
	== IMPORTANT~ ==
	Later on should be replaced with self implemented Tailor series calculations...
	==
***************/

AREAL32 Anubis::CosR32( AREAL32 angleInRadians ) { return cosf(angleInRadians); }
AREAL64 Anubis::CosR64( AREAL64 angleInRadians ) { return cos(angleInRadians); }
AREAL64 Anubis::Cos	  ( AREAL64 angleInRadians ) { return cos(angleInRadians); }

AREAL32 Anubis::SinR32( AREAL32 angleInRadians ) { return sinf(angleInRadians); }
AREAL64 Anubis::SinR64( AREAL64 angleInRadians ) { return sin(angleInRadians); }
AREAL64 Anubis::Sin	  ( AREAL64 angleInRadians ) { return sin(angleInRadians); }

AREAL32 Anubis::TgR32 ( AREAL32 angleInRadians ) { return tanf(angleInRadians); }
AREAL64 Anubis::TgR64 ( AREAL64 angleInRadians ) { return tan(angleInRadians); }
AREAL64 Anubis::Tg	  ( AREAL64 angleInRadians ) { return tan(angleInRadians); }

AREAL32 Anubis::CtgR32( AREAL32 angleInRadians ) { return atanf(angleInRadians); }
AREAL64 Anubis::CtgR64( AREAL64 angleInRadians ) { return atan(angleInRadians); }
AREAL64 Anubis::Ctg	  ( AREAL64 angleInRadians ) { return atan(angleInRadians); }

AREAL32 Anubis::Atan2R32( AREAL32 y, AREAL32 x ) { return atan2f(y, x); }
AREAL64 Anubis::Atan2R64( AREAL64 y, AREAL32 x ) { return atan2(y, x); }
AREAL64 Anubis::Atan2	( AREAL64 y, AREAL64 x ) { return atan2(y, x); }

AREAL32 Anubis::SqrtR32 (AREAL32 x) { return sqrtf(x); }
AREAL64 Anubis::SqrtR64 (AREAL64 x) { return sqrt(x); }
AREAL64 Anubis::Sqrt	(AREAL64 x) { return sqrt(x); }

/* ======================================
					Vectors
	========================================= */
AREAL Anubis::Dot(const Vec& v1, const Vec& v2)
{
	Vec res = _mm_mul_ps(v1, v2);
	Vec x = _mm_replicate_x_ps(res);
	Vec y = _mm_replicate_y_ps(res);
	Vec z = _mm_replicate_z_ps(res);
	Vec w = _mm_replicate_w_ps(res);

	return getx(_mm_add_ps(w, _mm_add_ps(_mm_add_ps(z, y), x)));
}

Vec Anubis::Normalize(const Vec& v)
{
	Vec res;

	__asm
	{
		mov	eax, v
		movaps	xmm0,	[eax]
		movaps	xmm2,	xmm0
		mulps	xmm0,	xmm0
		movaps	xmm1,	xmm0
		shufps	xmm0,	xmm0,	_MM_SHUFFLE (2, 1, 0, 3)
		addps	xmm1,	xmm0
		movaps	xmm0,	xmm1
		shufps	xmm1,	xmm1,	_MM_SHUFFLE (1, 0, 3, 2)
		addps	xmm0,	xmm1
		rsqrtps	xmm0,	xmm0
		mulps	xmm0,	xmm2
		movaps	[eax],	xmm0	
		mov	res, eax
	};
}

/* ======================================
					Matrices
	========================================= */
Mat4x4 Anubis::CreateViewMatrixLH(const Vec & pos, const Vec & lookAt, const Vec & up)
{
	Mat4x4 mat;

	Vec & zaxis = Normalize(lookAt - pos);
	Vec & xaxis = Normalize(cross(up, zaxis));
	Vec & yaxis = cross(zaxis, xaxis);

	mat.Init(	Vector( getx(xaxis), getx(yaxis), getx(zaxis), 0),
				Vector( gety(xaxis), gety(yaxis), gety(zaxis), 0),
				Vector( getz(xaxis), getz(yaxis), getz(zaxis), 0),
				Vector( -Dot(xaxis, pos), -Dot(yaxis, pos), -Dot(zaxis, pos), 1) );

	return mat;
}

Mat4x4 Anubis::CreatePerspectiveProjectionLH(	const AREAL fov,   const AREAL aspect,
												const AREAL nearZ, const AREAL farZ )
{
	Mat4x4 mat;

	AREAL yscale = CtgR32(fov / 2);
	AREAL xscale = yscale / aspect;

	mat.Init(	Vector(xscale, 0, 0, 0),
				Vector(0, yscale, 0, 0),
				Vector(0, 0, farZ/(farZ-nearZ), 1),
				Vector(0, 0, -nearZ*farZ/(farZ-nearZ), 0) );

	return mat;
}

Mat4x4 Anubis::CreateOrthoProjectionLH(	const AREAL width, const AREAL height,
										const AREAL nearZ,	const AREAL farZ)
{
	Mat4x4 mat;

	mat.Init(	Vector( 2.0f / width,			0,					0,					 0),
				Vector( 0,				 2.0f / height,				0,					 0),
				Vector( 0,						0,			1.0f / (farZ - nearZ),		 0),
				Vector( 0,						0,			nearZ / (nearZ - farZ),		 1) );

	return mat;
}