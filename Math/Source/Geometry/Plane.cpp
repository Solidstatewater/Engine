#include "Math_pch.h"
#include "Plane.h"

using namespace Anubis;

/*
AVOID Plane::Normalize()
{
	AREAL mag; //magnitude

	//get coefficients
	AREAL a = getx(m_coeff), b = gety(m_coeff), c = getz(m_coeff), d = getw(m_coeff);

	//calculate magnitude
	mag = Sqrt(a*a + b*b + c*c);

	m_coeff = Vector(a / mag, b / mag, c / mag, d / mag);
} */
/*
AVOID Plane::InitFromPoints(const Vec & p1, const Vec & p2, const Vec & p3)
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
*/
bool Plane::Inside(const Vec & point) const
{
	AREAL dist = Dot(Normal(), point) + D();
	return (dist >= 0.0f);
}

bool Plane::Inside(const Vec & point, const AREAL radius) const
{
	float dist = Dot(Normal(), point) + D();	

	// if this distance is < -radius, we are outside
	return (dist >= -radius);
}

Vec Plane::Normal() const { return Vector(getx(&m_coeff), gety(&m_coeff), getz(&m_coeff), 0); }

AREAL32 Plane::D()  const { return getw(&m_coeff); }