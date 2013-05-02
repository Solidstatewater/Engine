#include "Math_pch.h"
#include "Mat4x4.h"

using namespace Anubis;

///////////////////////////////////////////
//Mat4x4 definition
///////////////////////////////////////////
//Vec Mat4x4::Transform(Vec v)
//{
	/*Vec row1 = _mm_mul_ps(_mm_replicate_x_ps(v), rows[0]);
	Vec row2 = _mm_mul_ps(_mm_replicate_y_ps(v), rows[1]);
	Vec row3 = _mm_mul_ps(_mm_replicate_z_ps(v), rows[2]);
	Vec row4 = _mm_mul_ps(_mm_replicate_w_ps(v), rows[3]);

	Vec res = _mm_add_ps(row1, row2);
	res = _mm_add_ps(res, row3);
	res = _mm_add_ps(res, row4); */

//	Vec res = _mm_mul_ps(_mm_replicate_x_ps(v), rows[0]);
//	res = _mm_madd_ps(_mm_replicate_y_ps(v), rows[1], res);
//	res = _mm_madd_ps(_mm_replicate_z_ps(v), rows[2], res);
//	res = _mm_madd_ps(_mm_replicate_w_ps(v), rows[3], res);

//	return res;
//}

///////////////////////////////////////////
//Constructors and Initializers
///////////////////////////////////////////
/*Mat4x4::Mat4x4()
{
	rows[0] = _mm_set_ps(1, 0, 0, 0);
	rows[1] = _mm_set_ps(0, 1, 0, 0);
	rows[2] = _mm_set_ps(0, 0, 1, 0);
	rows[3] = _mm_set_ps(0, 0, 0, 1);
} */

/*ABOOL Mat4x4::Init(	Vec & v0,
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
*/
///////////////////////////////////////////
//Static methods
///////////////////////////////////////////
/*Mat4x4 Mat4x4::Identity()
{
	Mat4x4 mat;
	mat.Init(	Vector(1, 0, 0, 0),
				Vector(0, 1, 0, 0),
				Vector(0, 0, 1, 0),
				Vector(0, 0, 0, 1)	); //create identity matrix

	return mat;
} */

Mat4x4 Mat4x4::CreateTranslation(Vec & vec)
{
	rows[0] = Vector(1, 0, 0, 0);
	rows[1] = Vector(0, 1, 0, 0);
	rows[2] = Vector(0, 0, 1, 0);
	rows[3] = vec;
	
	return *this;
}

Mat4x4 Mat4x4::CreateRotationX(AREAL angleInRadians)
{
	rows[0] = Vector(1, 0, 0, 0);
	rows[1] = Vector(0, Cos(angleInRadians), Sin(angleInRadians), 0);
	rows[2] = Vector(0, -Sin(angleInRadians), Cos(angleInRadians), 0);
	rows[3] = Vector(0, 0, 0, 1);
	
	return *this;
}

Mat4x4 Mat4x4::CreateRotationY(AREAL angleInRadians)
{
	rows[0] = Vector(Cos(angleInRadians), 0, -Sin(angleInRadians), 0);
	rows[1] = Vector(0, 1, 0, 0);
	rows[2] = Vector(Sin(angleInRadians), 0, Cos(angleInRadians), 0);
	rows[3] = Vector(0, 0, 0, 1);
	
	return *this;
}

Mat4x4 Mat4x4::CreateRotationZ(AREAL angleInRadians)
{
	rows[0] = Vector(Cos(angleInRadians), Sin(angleInRadians), 0, 0);
	rows[1] = Vector(-Sin(angleInRadians), Cos(angleInRadians), 0, 0);
	rows[2] = Vector(0, 0, 1, 0);
	rows[3] = Vector(0, 0, 0, 1);
	
	return *this;
}

Mat4x4 Mat4x4::CreateScaling(Vec & scale)
{
	rows[0] = Vector(getx(scale), 0, 0, 0);
	rows[1] = Vector(0, gety(scale), 0, 0);
	rows[2] = Vector(0, 0, getz(scale), 0);
	rows[3] = Vector(0, 0, 0, 1);

	return *this;
}

Mat4x4 Mat4x4::CreateRollPitchYaw(AREAL rollInRadians, AREAL pitchInRadians, AREAL yawInRadians)
{
	return CreateRotationZ(rollInRadians) * CreateRotationX(pitchInRadians) * CreateRotationY(yawInRadians);
}

///////////////////////////////////////////
//Operations on matrices
///////////////////////////////////////////
AVOID Mat4x4::Transpose()
{
	//Calculate new rows values
	Vec r0 = Vector(getx(rows[0]), getx(rows[1]), getx(rows[2]), getx(rows[3]));
	Vec r1 = Vector(gety(rows[0]), gety(rows[1]), gety(rows[2]), gety(rows[3]));
	Vec r2 = Vector(getz(rows[0]), getz(rows[1]), getz(rows[2]), getz(rows[3]));
	Vec r3 = Vector(getw(rows[0]), getw(rows[1]), getw(rows[2]), getw(rows[3]));

	//Assign values to the matrix array
	rows[0] = r0;
	rows[1] = r1;
	rows[2] = r2;
	rows[3] = r3;
}
AVOID Mat4x4::Inverse()
{
}

///////////////////////////////////////////
//Operators
///////////////////////////////////////////

Mat4x4 Mat4x4::operator+(const Mat4x4 & M) const
{
	Mat4x4 mat;
	mat.rows[0] = rows[0] + M.rows[0];
	mat.rows[1] = rows[1] + M.rows[1];
	mat.rows[2] = rows[2] + M.rows[2];
	mat.rows[3] = rows[3] + M.rows[3];

	return mat;
}

Mat4x4 Mat4x4::operator*(const Mat4x4 & M) const
{
	Mat4x4 mat;
	mat.rows[0] = rows[0] * M;
	mat.rows[1] = rows[1] * M;
	mat.rows[2] = rows[2] * M;
	mat.rows[3] = rows[3] * M;

	return mat;
}

/*************	Matrix Stack Implementation	 *************/
MatrixStack::MatrixStack()
{
	m_matrices.push_back(Mat4x4::Identity());
	m_count = 1;
}

MatrixStack::~MatrixStack()
{
	//clear the stack
	while (Pop());
}

ABOOL MatrixStack::Pop()
{
	if (m_count)
	{
		m_matrices.pop_back();
		m_count--;
		
		return true;
	}

	//no matrices in the stack!
	return false;
}

AVOID MatrixStack::PushTransform(const Mat4x4 & mat)
{
	m_matrices.push_back(m_matrices.back() * mat);
	m_count++;
}