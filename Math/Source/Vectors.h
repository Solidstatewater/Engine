#pragma once

////////////////////////////////////////////////
//Include files
////////////////////////////////////////////////

namespace Anubis
{

	/*** 
	========================================
		Vector definition
	========================================
										***/
#ifdef SIMD_MATH_ENABLED
	typedef __m128 Vec;
#else
	typedef struct Vec
	{
		union
		{
			AREAL xyzw[4];
			struct
			{
				AREAL x;
				AREAL y;
				AREAL z;
				AREAL w;
			};
		};

		Vec()
		{
			x = 0;
			y = 0;
			z = 0;
			w = 0;
		}

		Vec(const AREAL _x, const AREAL _y, const AREAL _z, const AREAL _w)
		{
			memcpy(&x, &_x, sizeof(AREAL));
			memcpy(&y, &_y, sizeof(AREAL));
			memcpy(&z, &_z, sizeof(AREAL));
			memcpy(&w, &_w, sizeof(AREAL));
		};

		Vec operator=(const Vec & v)
		{
			memcpy(xyzw, v.xyzw, 4 * sizeof(AREAL));
			return *this;
		};
	};
#endif

	/***
		Define vector2 structure
	***/
	typedef struct float2
	{
		union
		{
			AREAL xy[2];
			struct 
			{
				AREAL x;
				AREAL y;
			};
		};

		//default constructor
		float2()
		{
			memset(xy, 0, sizeof(AREAL)*2);
		}

		//constructor
		float2(AREAL _x, AREAL _y)
		{
			memcpy(&x, &_x, sizeof(AREAL));
			memcpy(&y, &_y, sizeof(AREAL));
		};
	} float2, *pfloat2;

	/***
		Define vector3 structure
	***/
	typedef struct float3 
	{
		union
		{
			AREAL xyz[3];
			struct 
			{
				AREAL x;
				AREAL y;
				AREAL z;
			};
		};

		//default constructor
		float3()
		{
			memset(xyz, 0, sizeof(AREAL)*3);
		}

		//constructor
		float3(const AREAL _x, const AREAL _y, const AREAL _z)
		{
			memcpy(&x, &_x, sizeof(AREAL));
			memcpy(&y, &_y, sizeof(AREAL));
			memcpy(&z, &_z, sizeof(AREAL));
		};

	} float3, *pfloat3;

	/***
		Define vector4 structure
	***/
	typedef struct ALIGN16 float4
	{
	public:
		union
		{
			AREAL xyzw[4];
			struct 
			{
				AREAL x;
				AREAL y;
				AREAL z;
				AREAL w;
			};
		};

	public:

		//default constructor
		float4()
		{
			memset(xyzw, 0, sizeof(AREAL)*4);
		};

		float4(const AREAL _x, const AREAL _y, const AREAL _z, const AREAL _w)
		{
			memcpy(&x, &_x, sizeof(AREAL));
			memcpy(&y, &_y, sizeof(AREAL));
			memcpy(&z, &_z, sizeof(AREAL));
			memcpy(&w, &_w, sizeof(AREAL));
		};

		float4 operator=(Vec v)
		{
			#ifdef SIMD_MATH_ENABLED
				_mm_store_ps(xyzw, v);
			#else
				x = v.x;
				y = v.y;
				z = v.z;
				w = v.w;
			#endif
		};

	} float4, *pfloat4;

	/************************************************************************************
	//						METHODS
	************************************************************************************/

	//----------------------------------------------------
	//Initializers
	//----------------------------------------------------
	AINLINE	Vec Vector(const AREAL * const f)
	{
		#ifdef SIMD_MATH_ENABLED
			return _mm_load_ps(f);
		#else
			return Vec(f[0], f[1], f[2], f[3]);
		#endif
	};

	AINLINE	Vec Vector(float4 const * const f4)
	{
		#ifdef SIMD_MATH_ENABLED
			return _mm_load_ps(f4->xyzw);
		#else
			return Vec(f4->x, f4->y, f4->z, f4->w);
		#endif
	};

	AINLINE	Vec Vector(const AREAL x, const AREAL y, const AREAL z, const AREAL w)
	{
		#ifdef SIMD_MATH_ENABLED
			return _mm_set_ps(w, z, y, x);
		#else
			return Vec(x, y, z, w);
		#endif
	};

	//----------------------------------------------------
	//Operators
	//----------------------------------------------------
	AINLINE	Vec operator+(const Vec & v1, const Vec & v2)
	{
		#ifdef SIMD_MATH_ENABLED
			return _mm_add_ps(v1, v2);
		#else
			return Vec(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w);
		#endif
	}

	Vec operator*(const Vec & v, const AREAL32 s);
	Vec operator*(const AREAL32 s, const Vec & v);
	Vec operator/(const Vec & v, const AREAL32 s);

	AINLINE Vec operator*(const Vec & v1, const Vec & v2)
	{
		#ifdef SIMD_MATH_ENABLED
			return _mm_mul_ps(v1, v2);
		#else
			return Vec(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w);
		#endif
	}
	
	AINLINE Vec operator-(Vec & v)
	{
		return v * AREAL32(-1);
	}

	AINLINE Vec operator-(const Vec & v1, const Vec & v2)
	{
		#ifdef SIMD_MATH_ENABLED
			return _mm_sub_ps(v1, v2);
		#else
			return Vec(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w);
		#endif
	}

	AINLINE float3 operator+(const float3 & f1, const float3 & f2)
	{
		float3 res;
		res.x = f1.x + f2.x;
		res.y = f1.y + f2.y;
		res.z = f1.z + f2.z;

		return res;
	}

	AINLINE float3 operator-(const float3 & f1, const float3 & f2)
	{
		float3 res;
		res.x = f1.x - f2.x;
		res.y = f1.y - f2.y;
		res.z = f1.z - f2.z;

		return res;
	}

	//----------------------------------------------------
	//Methods
	//----------------------------------------------------
	AINLINE Vec ACALL cross(Vec v1, Vec & v2)
	{
		#ifdef SIMD_MATH_ENABLED
			return _mm_sub_ps(
				_mm_mul_ps(_mm_shuffle_ps(v1, v1, _MM_SHUFFLE(3, 0, 2, 1)), _mm_shuffle_ps(v2, v2, _MM_SHUFFLE(3, 1, 0, 2))),
				_mm_mul_ps(_mm_shuffle_ps(v1, v1, _MM_SHUFFLE(3, 1, 0, 2)), _mm_shuffle_ps(v2, v2, _MM_SHUFFLE(3, 0, 2, 1)))
				);
		#else
			return Vec(	v1.y*v2.z - v1.z*v2.y,
						v1.z*v2.x - v1.x*v2.z,
						v1.x*v2.y - v1.y*v2.x,
						0.0f);
		#endif
	}
	//AINLINE Vec ACALL normalize(Vec & v)
	//{


	//----------------------------------------------------
	//Accessors
	//----------------------------------------------------
	AINLINE AREAL ACALL getx(Vec & v)
	{
		#ifdef SIMD_MATH_ENABLED
			float4 res;
			_mm_store_ps(res.xyzw, v);

			return res.x;
		#else
			return v.x;
		#endif
	}

	AINLINE AREAL ACALL getr(Vec & v)
	{
		#ifdef SIMD_MATH_ENABLED
			float4 res;
			_mm_store_ps(res.xyzw, v);

			return res.x;
		#else
			return v.x;
		#endif	
	}

	AINLINE AREAL ACALL gety(Vec & v)
	{
		#ifdef SIMD_MATH_ENABLED
			float4 res;
			_mm_store_ps(res.xyzw, v);

			return res.y;
		#else
			return v.y;
		#endif
	}

	AINLINE AREAL ACALL getg(Vec & v)
	{
		#ifdef SIMD_MATH_ENABLED
			float4 res;
			_mm_store_ps(res.xyzw, v);

			return res.y;
		#else
			return v.y;
		#endif
	}

	AINLINE AREAL ACALL getz(Vec & v)
	{
		#ifdef SIMD_MATH_ENABLED
			float4 res;
			_mm_store_ps(res.xyzw, v);

			return res.z;
		#else
			return v.z;
		#endif
	}

	AINLINE AREAL ACALL getb(Vec & v)
	{
		#ifdef SIMD_MATH_ENABLED
			float4 res;
			_mm_store_ps(res.xyzw, v);

			return res.z;
		#else
			return v.z;
		#endif
	}

	AINLINE AREAL ACALL getw(Vec & v)
	{
		#ifdef SIMD_MATH_ENABLED
			float4 res;
			_mm_store_ps(res.xyzw, v);

			return res.w;
		#else
			return v.w;
		#endif
	}

	AINLINE AREAL ACALL geta(Vec & v)
	{
		#ifdef SIMD_MATH_ENABLED
			float4 res;
			_mm_store_ps(res.xyzw, v);

			return res.w;
		#else
			return v.w;
		#endif
	}

	AINLINE AREAL ACALL getx(Vec const * const v)
	{
		#ifdef SIMD_MATH_ENABLED
			float4 res;
			_mm_store_ps(res.xyzw, *v);

			return res.x;
		#else
			return v->x;
		#endif
	}

	AINLINE AREAL ACALL getr(Vec const * const v)
	{
		#ifdef SIMD_MATH_ENABLED
			float4 res;
			_mm_store_ps(res.xyzw, *v);

			return res.x;
		#else
			return v->x;
		#endif
	}

	AINLINE AREAL ACALL gety(Vec const * const v)
	{
		#ifdef SIMD_MATH_ENABLED
			float4 res;
			_mm_store_ps(res.xyzw, *v);

			return res.y;
		#else
			return v->y;
		#endif
	}

	AINLINE AREAL ACALL getg(Vec const * const v)
	{
		#ifdef SIMD_MATH_ENABLED
			float4 res;
			_mm_store_ps(res.xyzw, *v);

			return res.y;
		#else
			return v->y;
		#endif
	}

	AINLINE AREAL ACALL getz(Vec const * const v)
	{
		#ifdef SIMD_MATH_ENABLED
			float4 res;
			_mm_store_ps(res.xyzw, *v);

			return res.z;
		#else
			return v->z;
		#endif
	}

	AINLINE AREAL ACALL getb(Vec const * const v)
	{
		#ifdef SIMD_MATH_ENABLED
			float4 res;
			_mm_store_ps(res.xyzw, *v);

			return res.z;
		#else
			return v->z;
		#endif
	}

	AINLINE AREAL ACALL getw(Vec const * const v)
	{
		#ifdef SIMD_MATH_ENABLED
			float4 res;
			_mm_store_ps(res.xyzw, *v);

			return res.w;
		#else
			return v->w;
		#endif
	}

	AINLINE AREAL ACALL geta(Vec const * const v)
	{
		#ifdef SIMD_MATH_ENABLED
			float4 res;
			_mm_store_ps(res.xyzw, *v);

			return res.w;
		#else
			return v->w;
		#endif
	}

	AINLINE ABOOL operator!=(const Vec & v1, const Vec & v2)
	{
		#ifdef SIMD_MATH_ENABLED
			Vec temp = _mm_cmpeq_ps(v1, v2);

			return (getx(temp) && gety(temp) && getz(temp) && getw(temp)) ? false : true;
		#else
			return (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z && v1.w == v2.w) ? false : true;
		#endif
	}

	AINLINE ABOOL operator==(const Vec & v1, const Vec & v2)
	{
		#ifdef SIMD_MATH_ENABLED
			Vec temp = _mm_cmpeq_ps(v1, v2);

			return (getx(temp) && gety(temp) && getz(temp) && getw(temp)) ? true : false;
		#else
			return (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z && v1.w == v2.w) ? true : false;
		#endif
	}

}; //Anubis