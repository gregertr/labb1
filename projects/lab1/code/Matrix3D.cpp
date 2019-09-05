#include <iostream>
#include "Matrix3D.h"


// constructors
Matrix3D::Matrix3D()
{
	mxarr[0][0] = 1.0f;
	mxarr[0][1] = 0.0f;
	mxarr[0][2] = 0.0f;

	mxarr[1][0] = 0.0f;
	mxarr[1][1] = 1.0f;
	mxarr[1][2] = 0.0f;

	mxarr[2][0] = 0.0f;
	mxarr[2][1] = 0.0f;
	mxarr[2][2] = 1.0f;
}

Matrix3D::Matrix3D(float f00, float f01, float f10, float f11)
{
	mxarr[0][0] = f00;
	mxarr[0][1] = f01;
	mxarr[0][2] = 0;

	mxarr[1][0] = f10;
	mxarr[1][1] = f11;
	mxarr[1][2] = 0;

	mxarr[2][0] = 0;
	mxarr[2][1] = 0;
	mxarr[2][2] = 1;


}

Matrix3D::Matrix3D(float f00, float f01, float f02, float f10, float f11, float f12, float f20, float f21, float f22)
{
	mxarr[0][0] = f00;
	mxarr[0][1] = f01;
	mxarr[0][2] = f02;

	mxarr[1][0] = f10;
	mxarr[1][1] = f11;
	mxarr[1][2] = f12;

	mxarr[2][0] = f20;
	mxarr[2][1] = f21;
	mxarr[2][2] = f22;

}




Matrix3D::Matrix3D(Matrix3D& m)
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
float Matrix3D::x1() { return mxarr[0][0]; }
float Matrix3D::x2() { return mxarr[1][0]; }
float Matrix3D::x3() { return mxarr[2][0]; }
float Matrix3D::y1() { return mxarr[0][1]; }
float Matrix3D::y2() { return mxarr[1][1]; }
float Matrix3D::y3() { return mxarr[2][2]; }

float Matrix3D::getx()
{
	return mxarr[0][2];
}

float Matrix3D::gety()
{
	return mxarr[1][2];
}

//setters
void Matrix3D::setx1(float x) { mxarr[0][0] = x; }
void Matrix3D::setx2(float x) { mxarr[1][0] = x; }
void Matrix3D::sety1(float y) { mxarr[0][1] = y; }
void Matrix3D::sety2(float y) { mxarr[1][1] = y; }

void Matrix3D::setposxy(float x, float y)
{
	mxarr[0][2] = x;
	mxarr[1][2] = y;

}

void Matrix3D::move(Vector4D vec)
{
	mxarr[0][2] += vec.getx();
	mxarr[1][2] += vec.gety();
}

void Matrix3D::reset()
{
	mxarr[0][0] = 1.0;
	mxarr[0][1] = 0;

	mxarr[1][0] = 0;
	mxarr[1][1] = 1.0;

	mxarr[2][0] = 0;
	mxarr[2][1] = 0;
	mxarr[2][2] = 1.0;
}

Vector4D Matrix3D::getpos()
{
	Vector4D pos(mxarr[0][2], mxarr[1][2], mxarr[2][2]);
	return pos;
}

//printers
void Matrix3D::printx1() { std::cout << "x1: " << x1() << std::endl; }
void Matrix3D::printx2() { std::cout << "x2: " << x2() << std::endl; }
void Matrix3D::printy1() { std::cout << "y1: " << y1() << std::endl; }
void Matrix3D::printy2() { std::cout << "y2: " << y2() << std::endl; }


//matrix multiplication overload
Matrix3D Matrix3D::operator*(Matrix3D& m)
{
	Matrix3D newmx;
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
Vector4D Matrix3D::operator*(Vector4D& vector)
{
	float x = mxarr[0][0] * vector.getx() + mxarr[0][1] * vector.gety();
	float y = mxarr[1][0] * vector.getx() + mxarr[1][1] * vector.gety();
	Vector4D newVector(x, y);
	return newVector;
}

//assignment overload
void Matrix3D::operator=(Matrix3D& m)
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
Matrix3D Matrix3D::transpose()
{
	Matrix3D newmx(mxarr[0][0], mxarr[1][0], mxarr[0][1], mxarr[1][1]);
	return newmx;
}

// returns rotation matrix
Matrix3D Matrix3D::rotationmx(const float rad)
{
	Matrix3D newmx(cos(rad), -sin(rad), sin(rad), cos(rad));

	return newmx;
}

Matrix3D Matrix3D::rot(const float rad)
{
	Matrix3D rotmat(cos(rad), -(sin(rad)), sin(rad), cos(rad));
	rotmat = rotmat * Matrix3D(1, 0, 0, 1);

	return rotmat;

}


Matrix3D Matrix3D::translationMatrix(Vector4D v)
{
	Matrix3D transmx(1.0f, 0.0f, v.getx(), 0.0f, 1.0f, v.gety(), 0.0f, 0.0f, 1.0f);

	return transmx;
}



Matrix3D::~Matrix3D()
{
}
