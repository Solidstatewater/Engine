#include "Math_pch.h"
#include "Vectors.h"

using namespace Anubis;

Vec Anubis::operator*(const Vec & v, const AREAL32 s)
{
	const Vec scalar = _mm_set1_ps(s);
	return _mm_mul_ps(v, scalar);
}

Vec Anubis::operator*(const AREAL32 s, const Vec & v)
{
	const Vec scalar = _mm_set1_ps(s);
	return _mm_mul_ps(v, scalar);
}

/*Vec Anubis::operator*(const Vec & v, const AREAL64 s)
{
	const Vec scalar = _mm_set1_ps(s);
	return _mm_mul_ps(v, scalar);
} */