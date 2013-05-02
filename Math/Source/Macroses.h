#pragma once
//========================================================================
// Graphics.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include <xmmintrin.h>

////////////////////////////////////////////////
//Constants
////////////////////////////////////////////////
#define Pi 3.14

////////////////////////////////////////////////
//Macros
////////////////////////////////////////////////
#define SHUFFLE_PARAM(x, y, z, w) \
	((x) | ((y) << 2) | ((z) << 4) | ((w) << 6))

/**
	//Replicate X component across the vector value
**/
#define _mm_replicate_x_ps(v) \
	_mm_shuffle_ps((v), (v), SHUFFLE_PARAM(0, 0, 0, 0))

/**
	//Replicate Y component across the vector value
**/
#define _mm_replicate_y_ps(v) \
	_mm_shuffle_ps((v), (v), SHUFFLE_PARAM(1, 1, 1, 1))

/**
	//Replicate Z component across the vector value
**/
#define _mm_replicate_z_ps(v) \
	_mm_shuffle_ps((v), (v), SHUFFLE_PARAM(2, 2, 2, 2))

/**
	//Replicate W component across the vector value
**/
#define _mm_replicate_w_ps(v) \
	_mm_shuffle_ps((v), (v), SHUFFLE_PARAM(3, 3, 3, 3))

/******
	Multiply A and B and then add to C
								******/
#define _mm_madd_ps(a, b, c) \
	_mm_add_ps(_mm_mul_ps((a), (b)), (c))

/******
	Other useful macroses
						******/
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

/******
	Operations with angles
						******/
#define RADIANS_TO_DEGREES(x) ((x) * 180.0f / Pi)
#define DEGREES_TO_RADIANS(x) ((x) * Pi / 180.0f)