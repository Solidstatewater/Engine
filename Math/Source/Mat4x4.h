#pragma once
//========================================================================
// Graphics.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "Macroses.h"
#include "Vectors.h"

using namespace std;

namespace Anubis
{
	/***
		Define Matrix 4x4 structure
	***/
	typedef struct ALIGN16 Mat4x4 
	{
	public:
		Vec rows[4];

	public:
		/**								==
				Static methods
		==								**/
		ASTATIC Mat4x4 Identity()
		{
			Mat4x4 mat;
			mat.Init(	Vector(0, 0, 0, 1),
						Vector(0, 0, 1, 0),
						Vector(0, 1, 0, 0),
						Vector(1, 0, 0, 0)	); //create identity matrix
	
			return mat;
		}

		/**
			Costructors and Initializers
											**/
		Mat4x4()
		{
			rows[0] = _mm_set_ps(0, 0, 0, 1);
			rows[1] = _mm_set_ps(0, 0, 1, 0);
			rows[2] = _mm_set_ps(0, 1, 0, 0);
			rows[3] = _mm_set_ps(1, 0, 0, 0);
		}

		ABOOL Init(	Vec & v0,
					Vec & v1,
					Vec & v2,
					Vec & v3)
					{
						//Copy vector values
						rows[0] = v0;
						rows[1] = v1;
						rows[2] = v2;
						rows[3] = v3;

						return true;
					}

		//Create translation matrix
		Mat4x4 CreateTranslation(Vec & vec);

		//Create rotation matrix
		Mat4x4 CreateRotationX(AREAL angleInRadians);
		Mat4x4 CreateRotationY(AREAL angleInRadians);
		Mat4x4 CreateRotationZ(AREAL angleInRadians);

		Mat4x4 CreateRollPitchYaw(AREAL rollInRadians, AREAL pitchInRadians, AREAL yawInRadians);

		//create scaling matrix
		Mat4x4 CreateScaling(Vec & scale);
		Mat4x4 CreateScaling(AREAL x, AREAL y, AREAL z); //more effective

		/**
				Operations on matrices
											**/
		AVOID Inverse();
		AVOID Transpose();

		Mat4x4 operator+(const Mat4x4 & M) const;
		Mat4x4 operator*(const Mat4x4 & M) const;

	} Mat4x4, *pMat4x4;

	//define matrix list
	typedef vector<Mat4x4> Matrices;

	//----------------------------------------------------
	//Operators
	//----------------------------------------------------
	AINLINE Vec operator*(Vec v, const Mat4x4 & M)
	{
		Vec res;

		//calc first row
		res = _mm_mul_ps ( _mm_replicate_x_ps(v), M.rows[0]);
		//calc second row and add result
		res = _mm_madd_ps( _mm_replicate_y_ps(v), M.rows[1], res);
		//calc third row and add result
		res = _mm_madd_ps( _mm_replicate_z_ps(v), M.rows[2], res);
		//calc fourth row and add result
		res = _mm_madd_ps( _mm_replicate_w_ps(v), M.rows[3], res);

		return res;
} 

	AINLINE ABOOL operator==(const Mat4x4 & m1, const Mat4x4 & m2)
	{
		return (m1.rows[0] == m2.rows[0] &&
				m1.rows[1] == m2.rows[1] &&
				m1.rows[2] == m2.rows[2] &&
				m1.rows[3] == m2.rows[3] );
	}
	AINLINE ABOOL operator!=(const Mat4x4 & m1, const Mat4x4 & m2)
	{
		return (!(	m1.rows[0] == m2.rows[0] &&
					m1.rows[1] == m2.rows[1] &&
					m1.rows[2] == m2.rows[2] &&
					m1.rows[3] == m2.rows[3] ));
	}


	//Use this class for connectiing affine transformations
	class ALIGN16 MatrixStack
	{
	private:
		//matrix stack itself
		Matrices	m_matrices;
		AUINT8		m_count; //probably 256 matrices in the stack is more than enough

	public:
		//Constructor and Destructor
		MatrixStack();
		~MatrixStack();

		//Get top(current) matrix
		Mat4x4 Get() const { return m_matrices.back(); }

		//Get number of matrices in the stack
		AUINT8 Count() const { return m_count; }

		//remove current matrix
		ABOOL Pop();

		//Add transform to the current matrix and add new one
		AVOID PushTransform(const Mat4x4 & mat);
	};

}; //Anubis