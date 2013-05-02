#pragma once
//========================================================================
// Interpolation.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

namespace Anubis
{
	//	============================
	//		Linear Interpolation
	//	============================
	AINLINE Vec		LERP( Vec & v1, Vec & v2, AREAL factor)
	{
		return (1-factor) * v1 + factor * v2;
	}

	AINLINE Mat4x4	LERP( Mat4x4 & m1, Mat4x4 & m2, AREAL factor)
	{
		Mat4x4 res;

		res.rows[0] = LERP(m1.rows[0], m2.rows[0], factor);
		res.rows[1] = LERP(m1.rows[1], m2.rows[1], factor);
		res.rows[2] = LERP(m1.rows[2], m2.rows[2], factor);
		res.rows[3] = LERP(m1.rows[3], m2.rows[3], factor);

		return res;
	}

	//	===============================
	//		Spherical Interpolation
	//	===============================
	AINLINE Mat4x4	SLERP(Mat4x4 & m1, Mat4x4 & m2, AREAL factor);
};