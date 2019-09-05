#pragma once
#include "Vector4D.h"
#include "Math.h"

class Matrix3D
{

private:
	float mxarr[3][3];


public:

	Matrix3D();
	Matrix3D(float f00, float f01, float f10, float f11);
	Matrix3D(float f00, float f01, float f02, float f10, float f11, float f12, float f20, float f21, float f22);
	Matrix3D(Matrix3D& m);

	//getters 
	float x1();
	float x2();
	float x3();
	float y1();
	float y2();
	float y3();

	float getx();
	float gety();

	//setters
	void setx1(float x);
	void setx2(float x);
	void sety1(float y);
	void sety2(float y);

	void setposxy(float x, float y);

	void move(Vector4D vec);

	void reset();

	Vector4D getpos();

	//printers
	void printx1();
	void printx2();
	void printy1();
	void printy2();

	//matrix multiplication overload
	Matrix3D operator*(Matrix3D& m);

	//matrix vetor multiplication overload
	Vector4D operator*(Vector4D& v);

	//assignment overload
	void operator=(Matrix3D& m);

	//returns matrix transpose
	Matrix3D transpose();

	// returns rotation matrix
	Matrix3D rotationmx(const float rad);

	Matrix3D rot(const float rad);

	Matrix3D translationMatrix(Vector4D v);
	
	~Matrix3D();
};

