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
	typedef __m128 Vec;

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
		float3(AREAL _x, AREAL _y, AREAL _z)
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

		float4 operator=(Vec v)
		{
			_mm_store_ps(xyzw, v);
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
		return _mm_load_ps(f);
	};

	AINLINE	Vec Vector(float4 const * const f4)
	{
		return _mm_load_ps(f4->xyzw);
	};

	AINLINE	Vec Vector(const AREAL x, const AREAL y, const AREAL z, const AREAL w)
	{
		return _mm_set_ps(w, z, y, x);
	};

	//----------------------------------------------------
	//Operators
	//----------------------------------------------------
	AINLINE	Vec operator+(const Vec & v1, const Vec & v2)
	{
		return _mm_add_ps(v1, v2);
	}

	Vec operator*(const Vec & v, const AREAL32 s);
	Vec operator*(const AREAL32 s, const Vec & v);
	//Vec operator*(const Vec & v, const AREAL64 s);

	AINLINE Vec operator*(const Vec & v1, const Vec & v2)
	{
		return _mm_mul_ps(v1, v2);
	}
	
	AINLINE Vec operator-(Vec & v)
	{
		return v * AREAL32(-1);
	}

	AINLINE Vec operator-(const Vec & v1, const Vec & v2)
	{
		return _mm_sub_ps(v1, v2);
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
		return _mm_sub_ps(
			_mm_mul_ps(_mm_shuffle_ps(v1, v1, _MM_SHUFFLE(3, 0, 2, 1)), _mm_shuffle_ps(v2, v2, _MM_SHUFFLE(3, 1, 0, 2))),
			_mm_mul_ps(_mm_shuffle_ps(v1, v1, _MM_SHUFFLE(3, 1, 0, 2)), _mm_shuffle_ps(v2, v2, _MM_SHUFFLE(3, 0, 2, 1)))
			);
	}
	//AINLINE Vec ACALL normalize(Vec & v)
	//{


	//----------------------------------------------------
	//Accessors
	//----------------------------------------------------
	AINLINE AREAL ACALL getx(Vec & v)
	{
		float4 res;
		_mm_store_ps(res.xyzw, v);

		return res.x;
	}

	AINLINE AREAL ACALL getr(Vec & v)
	{
		float4 res;
		_mm_store_ps(res.xyzw, v);

		return res.x;
	}

	AINLINE AREAL ACALL gety(Vec & v)
	{
		float4 res;
		_mm_store_ps(res.xyzw, v);

		return res.y;
	}

	AINLINE AREAL ACALL getg(Vec & v)
	{
		float4 res;
		_mm_store_ps(res.xyzw, v);

		return res.y;
	}

	AINLINE AREAL ACALL getz(Vec & v)
	{
		float4 res;
		_mm_store_ps(res.xyzw, v);

		return res.z;
	}

	AINLINE AREAL ACALL getb(Vec & v)
	{
		float4 res;
		_mm_store_ps(res.xyzw, v);

		return res.z;
	}

	AINLINE AREAL ACALL getw(Vec & v)
	{
		float4 res;
		_mm_store_ps(res.xyzw, v);

		return res.w;
	}

	AINLINE AREAL ACALL geta(Vec & v)
	{
		float4 res;
		_mm_store_ps(res.xyzw, v);

		return res.w;
	}

	AINLINE AREAL ACALL getx(Vec const * const v)
	{
		float4 res;
		_mm_store_ps(res.xyzw, *v);

		return res.x;
	}

	AINLINE AREAL ACALL getr(Vec const * const v)
	{
		float4 res;
		_mm_store_ps(res.xyzw, *v);

		return res.x;
	}

	AINLINE AREAL ACALL gety(Vec const * const v)
	{
		float4 res;
		_mm_store_ps(res.xyzw, *v);

		return res.y;
	}

	AINLINE AREAL ACALL getg(Vec const * const v)
	{
		float4 res;
		_mm_store_ps(res.xyzw, *v);

		return res.y;
	}

	AINLINE AREAL ACALL getz(Vec const * const v)
	{
		float4 res;
		_mm_store_ps(res.xyzw, *v);

		return res.z;
	}

	AINLINE AREAL ACALL getb(Vec const * const v)
	{
		float4 res;
		_mm_store_ps(res.xyzw, *v);

		return res.z;
	}

	AINLINE AREAL ACALL getw(Vec const * const v)
	{
		float4 res;
		_mm_store_ps(res.xyzw, *v);

		return res.w;
	}

	AINLINE AREAL ACALL geta(Vec const * const v)
	{
		float4 res;
		_mm_store_ps(res.xyzw, *v);

		return res.w;
	}

	AINLINE ABOOL operator!=(const Vec & v1, const Vec & v2)
	{
		Vec temp = _mm_cmpeq_ps(v1, v2);

		return (getx(temp) && gety(temp) && getz(temp) && getw(temp)) ? false : true;
	}

	AINLINE ABOOL operator==(const Vec & v1, const Vec & v2)
	{
		Vec temp = _mm_cmpeq_ps(v1, v2);

		return (getx(temp) && gety(temp) && getz(temp) && getw(temp)) ? true : false;
	}

}; //Anubis