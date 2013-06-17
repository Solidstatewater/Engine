#include "Math_pch.h"
#include "Vectors.h"

using namespace Anubis;

Vec Anubis::operator*(const Vec & v, const AREAL32 s)
{
	#ifdef SIMD_MATH_ENABLED
		const Vec scalar = _mm_set1_ps(s);
		return _mm_mul_ps(v, scalar);
	#else
		return Vec(v.x * s, v.y * s, v.z * s, v.w * s);
	#endif
}

Vec Anubis::operator*(const AREAL32 s, const Vec & v)
{
	#ifdef SIMD_MATH_ENABLED
		const Vec scalar = _mm_set1_ps(s);
		return _mm_mul_ps(v, scalar);
	#else
		return Vec(v.x * s, v.y * s, v.z * s, v.w * s);
	#endif
}

Vec Anubis::operator/(const Vec & v, const AREAL32 s)
{
	#ifdef SIMD_MATH_ENABLED
		const Vec scalar = _mm_set1_ps(1.0f / s);
		return _mm_mul_ps(v, scalar);
	#else
		return Vec(v.x / s, v.y / s, v.z / s, v.w / s);
	#endif
}

/*Vec Anubis::operator*(const Vec & v, const AREAL64 s)
{
	const Vec scalar = _mm_set1_ps(s);
	return _mm_mul_ps(v, scalar);
} */