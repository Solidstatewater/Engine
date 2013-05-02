#pragma once
//========================================================================
// Plane.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "../Vectors.h"
#include "../Math.h"

namespace Anubis
{
	class Plane
	{
	private:
		//Coefficients of the plane equation
		Vec	m_coeff;

	public:
		//Constructor
		Plane() { m_coeff = Vector(0.0f, 0.0f, 0.0f, 0.0f); }

		/**
			Methods	
					**/
		AVOID Normalize() //normalize
		{
			AREAL mag; //magnitude

			//get coefficients
			AREAL a = getx(m_coeff), b = gety(m_coeff), c = getz(m_coeff), d = getw(m_coeff);

			//calculate magnitude
			mag = SqrtR32(a*a + b*b + c*c);

			m_coeff = Vector(a / mag, b / mag, c / mag, d / mag);
		}

		//check whether point is inside the plane
		ABOOL Inside(const Vec & point) const;
		ABOOL Inside(const Vec & point, const AREAL32 radius) const;

		/**
			Initializers
							**/
		//!!!! normal faces away from you if you send in verts in counter clockwise order !!!!//
		AVOID InitFromPoints(const Vec & p1, const Vec & p2, const Vec & p3)
		{ 
			//calculate vectors
			Vec v21 = p2 - p1;
			Vec v31 = p3 - p1;

			//calculate normal
			Vec normal = cross(v21, v31);
			AREAL D = Dot(-normal, p1);

			//assign coefficients and normalize
			m_coeff = Vector(getx(normal), gety(normal), getz(normal), D);
			Normalize();
		}

		/**
				Getters
							**/
		AINLINE Vec Normal() const;
		AINLINE AREAL32 D()  const;

	};
}; //Anubis