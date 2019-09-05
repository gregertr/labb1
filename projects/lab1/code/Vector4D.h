#pragma once
#include <Math.h>
#define POW2(x) ((x)*(x))


class Vector4D
{
private:
	float vecarray[4];

public:
	// constructors
	Vector4D() {
		vecarray[0] = 0.0f;
		vecarray[1] = 0.0f;
		vecarray[2] = 0.0f;
		vecarray[3] = 1.0f;
	}

	Vector4D(float x, float y) {
		vecarray[0] = x;
		vecarray[1] = y;
		vecarray[2] = 0.0f;
		vecarray[3] = 1.0f;
	}

	Vector4D(float x, float y, float z) {
		vecarray[0] = x;
		vecarray[1] = y;
		vecarray[2] = z;
		vecarray[3] = 1.0f;
	}
	Vector4D(float x, float y, float z, float w) {
		vecarray[0] = x;
		vecarray[1] = y;
		vecarray[2] = z;
		vecarray[3] = w;
	}

	Vector4D(const Vector4D& v) {
		vecarray[0] = v.vecarray[0];
		vecarray[1] = v.vecarray[1];
		vecarray[2] = v.vecarray[2];
		vecarray[3] = v.vecarray[3];
	}


	//getters
	float  getx() { return vecarray[0]; }
	float  gety() { return vecarray[1]; }
	float  getz() { return vecarray[2]; }
	float  getw() { return vecarray[3]; }

	//setters
	void set(int i, float x)
	{
		vecarray[i] = x;

	}

	void setxy(float x, float y) {
		vecarray[0] = x;
		vecarray[1] = y;

	}

	void setxyz(float x, float y, float z) {
		vecarray[0] = x;
		vecarray[1] = y;
		vecarray[2] = z;

	}

	void setxyzw(float x, float y, float z, float w) {
		vecarray[0] = x;
		vecarray[1] = y;
		vecarray[2] = z;
		vecarray[3] = w;
	}
	// operator overloads
	Vector4D operator+(const Vector4D& v) {
		Vector4D newvec;
		newvec.vecarray[0] = vecarray[0] + v.vecarray[0];
		newvec.vecarray[1] = vecarray[1] + v.vecarray[1];
		newvec.vecarray[2] = vecarray[2] + v.vecarray[2];
		newvec.vecarray[3] = vecarray[3] + v.vecarray[3];
		return newvec;
	}

	Vector4D operator-(const Vector4D& v) {
		Vector4D newvec;
		newvec.vecarray[0] = vecarray[0] - v.vecarray[0];
		newvec.vecarray[1] = vecarray[1] - v.vecarray[1];
		newvec.vecarray[2] = vecarray[2] - v.vecarray[2];
		newvec.vecarray[3] = vecarray[3] - v.vecarray[3];
		return newvec;
	}

	Vector4D operator*(const float& scalar) {
		Vector4D newvec;
		newvec.vecarray[0] = scalar * vecarray[0];
		newvec.vecarray[1] = scalar * vecarray[1];
		newvec.vecarray[2] = scalar * vecarray[2];
		newvec.vecarray[3] = scalar * vecarray[3];
		return newvec;
	}

	Vector4D operator=(const Vector4D& v) {
		this->vecarray[0] = v.vecarray[0];
		this->vecarray[1] = v.vecarray[1];
		this->vecarray[2] = v.vecarray[2];
		return *this;
	}
	float length(Vector4D v) {
		float sum = POW2(v.vecarray[0]) + POW2(v.vecarray[1]) + POW2(v.vecarray[2]) + POW2(v.vecarray[3]);
		float length = sqrt(sum);
		

	}


	float operator*(const Vector4D& v) {
		float scalar = (vecarray[0] * v.vecarray[0] + vecarray[1] * v.vecarray[1] + vecarray[2] * v.vecarray[2] + vecarray[3] * v.vecarray[3]);
		return scalar;
	}

	// returns dot product
	float dot(const Vector4D& a, const Vector4D& b) {
		return((a.vecarray[0] * b.vecarray[0]) + (a.vecarray[1] * b.vecarray[1]) + (a.vecarray[2] * b.vecarray[2]) + (a.vecarray[3] * b.vecarray[3]));
	}

	Vector4D cross(const Vector4D& a, const Vector4D& b) {
		Vector4D cross;
		cross.set(0, a.vecarray[1] * b.vecarray[2] - a.vecarray[2] * b.vecarray[1]);
		cross.set(1, a.vecarray[2] * b.vecarray[0] - a.vecarray[0] * b.vecarray[2]);
		cross.set(2, a.vecarray[0] * b.vecarray[1] - a.vecarray[1] * b.vecarray[0]);
		return cross;
	}

	// return vector norm
	Vector4D norm() {
		Vector4D normvec;
		float length = POW2(vecarray[0]) + POW2(vecarray[1]) + POW2(vecarray[2]) + POW2(vecarray[3]);
		float norm = sqrt(length);
		normvec.vecarray[0] = (this->vecarray[0] / norm);
		normvec.vecarray[1] = (this->vecarray[1] / norm);
		normvec.vecarray[2] = (this->vecarray[2] / norm);
		normvec.vecarray[3] = (this->vecarray[3] / norm);
		return normvec;
	}

	
};

