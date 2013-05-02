#pragma once
//========================================================================
// Graphics.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "Defines.h"

namespace Anubis
{
	//typedef __m128	Quaternion;
	struct Quaternion
	{
		//data
		Vec	m_q;

		// ==================
		//	Operators
		// ==================
		Quaternion operator+(const Quaternion & q) const;
		Quaternion operator-(const Quaternion & q) const;
		Quaternion operator*(const Quaternion & q) const; 
		Quaternion operator*(const AREAL s) const;

		// ==================
		//  Methods
		// ==================
		Quaternion Conjugate() const;
		Quaternion Inverse() const;
		Quaternion Normalize();
		AREAL Norm() const;
		AREAL Dot(Quaternion & q) const;
	};

}; //Anubis