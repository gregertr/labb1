#pragma once
#include "Vector4D.h"
#include "Math.h"

class Matrix4D
{

private:
	float mxarr[4][4];

// constructors
Matrix4D()
{
	mxarr[0][0] = 1.0f;
	mxarr[0][1] = 0.0f;
	mxarr[0][2] = 0.0f;
	mxarr[0][3] = 0.0f;

	mxarr[1][0] = 0.0f;
	mxarr[1][1] = 1.0f;
	mxarr[1][2] = 0.0f;
	mxarr[1][3] = 0.0f;

	mxarr[2][0] = 0.0f;
	mxarr[2][1] = 0.0f;
	mxarr[2][2] = 1.0f;
	mxarr[2][3] = 0.0f;

	mxarr[3][0] = 0.0f;
	mxarr[3][1] = 0.0f;
	mxarr[3][2] = 0.0f;
	mxarr[3][3] = 1.0f;

}

Matrix4D(float f00, float f01, float f02, float f03, float f10, float f11, float f12, float f13, float f20, float f21, float f22, float f23, float f30, float f31, float f32, float f33)
{
	mxarr[0][0] = f00;
	mxarr[0][1] = f01;
	mxarr[0][2] = f02;
	mxarr[0][3] = f03;

	mxarr[1][0] = f10;
	mxarr[1][1] = f11;
	mxarr[1][2] = f12;
	mxarr[1][3] = f13;

	mxarr[2][0] = f20;
	mxarr[2][1] = f21;
	mxarr[2][2] = f22;
	mxarr[2][3] = f23;

	mxarr[3][0] = f30;
	mxarr[3][1] = f31;
	mxarr[3][2] = f32;
	mxarr[3][3] = f33;


}




Matrix4D(Matrix4D& m)
{


	mxarr[0][0] = m.mxarr[0][0];
	mxarr[0][1] = m.mxarr[0][1];
	mxarr[0][2] = m.mxarr[0][2];
	

	mxarr[1][0] = m.mxarr[1][0];
	mxarr[1][1] = m.mxarr[1][1];
	mxarr[1][2] = m.mxarr[1][2];

	mxarr[2][0] = m.mxarr[2][0];
	mxarr[2][1] = m.mxarr[2][1];
	mxarr[2][2] = m.mxarr[2][2];


}

//getters 
float x1() { return mxarr[0][0]; }
float x2() { return mxarr[1][0]; }
float x3() { return mxarr[2][0]; }
float y1() { return mxarr[0][1]; }
float y2() { return mxarr[1][1]; }
float y3() { return mxarr[2][2]; }

float getx()
{
	return mxarr[0][2];
}

float gety()
{
	return mxarr[1][2];
}

//setters
void setx1(float x) { mxarr[0][0] = x; }
void setx2(float x) { mxarr[1][0] = x; }
void sety1(float y) { mxarr[0][1] = y; }
void sety2(float y) { mxarr[1][1] = y; }

void setposxy(float x, float y)
{
	mxarr[0][2] = x;
	mxarr[1][2] = y;

}

void move(Vector4D vec)
{
	mxarr[0][2] += vec.getx();
	mxarr[1][2] += vec.gety();
}

void reset()
{
	mxarr[0][0] = 1.0;
	mxarr[0][1] = 0;

	mxarr[1][0] = 0;
	mxarr[1][1] = 1.0;

	mxarr[2][0] = 0;
	mxarr[2][1] = 0;
	mxarr[2][2] = 1.0;
}

Vector4D getpos()
{
	Vector4D pos(mxarr[0][2], mxarr[1][2], mxarr[2][2]);
	return pos;
}




//matrix multiplication overload
Matrix4D operator*(Matrix4D& m)
{
	Matrix4D newmx;
	newmx.mxarr[0][0] = (mxarr[0][0] * m.mxarr[0][0]) + (mxarr[0][1] * m.mxarr[1][0]) + (mxarr[0][2] * m.mxarr[2][0]);
	newmx.mxarr[1][0] = (mxarr[1][0] * m.mxarr[0][0]) + (mxarr[1][1] * m.mxarr[1][0]) + (mxarr[1][2] * m.mxarr[2][0]);
	newmx.mxarr[2][0] = (mxarr[2][0] * m.mxarr[0][0]) + (mxarr[2][1] * m.mxarr[1][0]) + (mxarr[2][2] * m.mxarr[2][0]);
	newmx.mxarr[0][1] = (mxarr[0][0] * m.mxarr[0][1]) + (mxarr[0][1] * m.mxarr[1][1]) + (mxarr[0][2] * m.mxarr[2][1]);
	newmx.mxarr[1][1] = (mxarr[1][0] * m.mxarr[0][1]) + (mxarr[1][1] * m.mxarr[1][1]) + (mxarr[1][2] * m.mxarr[2][1]);
	newmx.mxarr[2][1] = (mxarr[2][0] * m.mxarr[0][1]) + (mxarr[2][1] * m.mxarr[1][1]) + (mxarr[2][2] * m.mxarr[2][1]);
	newmx.mxarr[0][2] = (mxarr[0][0] * m.mxarr[0][2]) + (mxarr[0][1] * m.mxarr[1][2]) + (mxarr[0][2] * m.mxarr[2][2]);
	newmx.mxarr[1][2] = (mxarr[1][0] * m.mxarr[0][2]) + (mxarr[1][1] * m.mxarr[1][2]) + (mxarr[1][2] * m.mxarr[2][2]);
	newmx.mxarr[2][2] = (mxarr[2][0] * m.mxarr[0][2]) + (mxarr[2][1] * m.mxarr[1][2]) + (mxarr[2][2] * m.mxarr[2][2]);
	return newmx;
}

//matrix vector multiplication overload
Vector4D operator*(Vector4D& vector)
{
	float x = mxarr[0][0] * vector.getx() + mxarr[0][1] * vector.gety();
	float y = mxarr[1][0] * vector.getx() + mxarr[1][1] * vector.gety();
	Vector4D newVector(x, y);
	return newVector;
}

//assignment overload
void operator=(Matrix4D& m)
{
	mxarr[0][0] = m.mxarr[0][0];
	mxarr[0][1] = m.mxarr[0][1];
	mxarr[0][2] = m.mxarr[0][2];

	mxarr[1][0] = m.mxarr[1][0];
	mxarr[1][1] = m.mxarr[1][1];
	mxarr[1][2] = m.mxarr[1][2];

	mxarr[2][0] = m.mxarr[2][0];
	mxarr[2][1] = m.mxarr[2][1];
	mxarr[2][2] = m.mxarr[2][2];
}

//returns matrix transpose
Matrix4D transpose()
{
	Matrix4D newmx(mxarr[0][0], mxarr[1][0], mxarr[0][1], mxarr[1][1]);
	return newmx;
}

// returns rotation matrix
Matrix4D rotationmx(const float rad)
{
	Matrix4D newmx(cos(rad), -sin(rad), sin(rad), cos(rad));

	return newmx;
}

Matrix4D rot(const float rad)
{
	Matrix4D rotmat(cos(rad), -(sin(rad)), sin(rad), cos(rad));
	rotmat = rotmat * Matrix4D(1, 0, 0, 1);

	return rotmat;

}


Matrix4D translationMatrix(Vector4D v)
{
	Matrix4D transmx(1.0f, 0.0f, v.getx(), 0.0f, 1.0f, v.gety(), 0.0f, 0.0f, 1.0f);

	return transmx;
}



~Matrix4D()
{
}
