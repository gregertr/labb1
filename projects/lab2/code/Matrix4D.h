#pragma once
#include "Vector4D.h"
#include "Math.h"
#include <iostream>
///
///\copyright{
///This file is part of Lab 1.
///
///Lab 1 is free software : you can redistribute itand /or modify
///it under the terms of the GNU General Public License as published by
///the Free Software Foundation, either version 3 of the License, or
///(at your option) any later version.
///
///Lab 1 is distributed in the hope that it will be useful,
///but WITHOUT ANY WARRANTY; without even the implied warranty of
///MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
///GNU General Public License for more details.
///
///You should have received a copy of the GNU General Public License
///along with Lab 1.If not, see < https://www.gnu.org/licenses/>.}

class Matrix4D
{

public:
	Vector4D mxarr[4];

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
		mxarr[0][3] = m.mxarr[0][3];

		mxarr[1][0] = m.mxarr[1][0];
		mxarr[1][1] = m.mxarr[1][1];
		mxarr[1][2] = m.mxarr[1][2];
		mxarr[1][3] = m.mxarr[1][3];

		mxarr[2][0] = m.mxarr[2][0];
		mxarr[2][1] = m.mxarr[2][1];
		mxarr[2][2] = m.mxarr[2][2];

		mxarr[3][0] = m.mxarr[3][0];
		mxarr[3][1] = m.mxarr[3][1];
		mxarr[3][2] = m.mxarr[3][2];
		mxarr[3][3] = m.mxarr[3][3];


	}

	///
	///getters 
	///
	float get(int i, int j) {
		if (i >= 4 || j >= 4) {
			throw std::out_of_range("Index out of range");
		}
		return mxarr[i][j];
	}

	float x() {
		return mxarr[0][3];
	}
	float y() {
		return mxarr[1][3];
	}
	float z() {
		return mxarr[2][3];
	}

	///
	///setters
	///
	void set(int i, int j, float val) {
		if (i >= 4 || j >= 4) {
			throw std::out_of_range("Index out of range");
		}
		mxarr[i][j] = val;
	}


	void reset()
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

	///
	///Printing function
	///
	void print() {
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
			{
				std::cout << " " << mxarr[i][j];
				if (j == 3)
					std::cout << "\n" << "\n";
			}
	}






	///
	///matrix multiplication overload
	///
	Matrix4D operator*(Matrix4D& m)
	{
		Matrix4D newmx;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				newmx.mxarr[i][j] = 0;
				for (int k = 0; k < 4; ++k) {
					newmx.mxarr[i][j] += this->mxarr[i][k] * m.mxarr[k][j];
				}
			}
		}

		return newmx;
	}

	///
	///matrix vector multiplication overload
	///
	Vector4D operator*(Vector4D& vector)
	{
		float x = mxarr[0][0] * vector.x() + mxarr[0][1] * vector.y() + mxarr[0][2] * vector.z() + mxarr[0][3] * vector.w();
		float y = mxarr[1][0] * vector.x() + mxarr[1][1] * vector.y() + mxarr[1][2] * vector.z() + mxarr[1][3] * vector.w();
		float z = mxarr[2][0] * vector.x() + mxarr[2][1] * vector.y() + mxarr[2][2] * vector.z() + mxarr[2][3] * vector.w();
		float w = mxarr[3][0] * vector.x() + mxarr[3][1] * vector.y() + mxarr[3][2] * vector.z() + mxarr[3][3] * vector.w();
		Vector4D newVector(x, y, z, w);
		return newVector;
	}
	///
	///Array overload
	///
	Vector4D operator [] (int i) const {
		//return *(Vector4D*)(&mxarr[i]);
		//return Vector4D(mxarr[i][0], mxarr[i][1], mxarr[i][2], mxarr[i][3]);
		return mxarr[i];
	}
	Vector4D& operator [] (int i) {
		//return *(Vector4D*)(&mxarr[i]);
		//return vecarray[i];
		return mxarr[i];
	}

	///
	///assignment overload
	///
	void operator=(Matrix4D& m)
	{
		mxarr[0][0] = m.mxarr[0][0];
		mxarr[0][1] = m.mxarr[0][1];
		mxarr[0][2] = m.mxarr[0][2];
		mxarr[0][3] = m.mxarr[0][3];

		mxarr[1][0] = m.mxarr[1][0];
		mxarr[1][1] = m.mxarr[1][1];
		mxarr[1][2] = m.mxarr[1][2];
		mxarr[1][3] = m.mxarr[1][3];

		mxarr[2][0] = m.mxarr[2][0];
		mxarr[2][1] = m.mxarr[2][1];
		mxarr[2][2] = m.mxarr[2][2];
		mxarr[2][3] = m.mxarr[2][3];


		mxarr[3][0] = m.mxarr[3][0];
		mxarr[3][1] = m.mxarr[3][1];
		mxarr[3][2] = m.mxarr[3][2];
		mxarr[3][3] = m.mxarr[3][3];
	}

	///Creates temp matrix to store transpose 
	///Assigns the transpose to referenced matrix 
	///
	void transpose(Matrix4D& m)
	{
		Matrix4D transp;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				transp.mxarr[i][j] = m.mxarr[j][i];
			}
		}
		m = transp;
	}

	///Somewhat shamefully borrowed from
	///https://stackoverflow.com/questions/1148309/inverting-a-4x4-matrix
	///Inverts matrix, calculates determinant and assigns the inverse by reference
	///Throws an exception if determinant is 0
	void invert(Matrix4D& m) {
		Matrix4D inv;
		inv.mxarr[0][0] = m.mxarr[1][1] * m.mxarr[2][2] * m.mxarr[3][3] -
			m.mxarr[1][1] * m.mxarr[2][3] * m.mxarr[3][2] -
			m.mxarr[2][1] * m.mxarr[1][2] * m.mxarr[3][3] +
			m.mxarr[2][1] * m.mxarr[1][3] * m.mxarr[3][2] +
			m.mxarr[3][1] * m.mxarr[1][2] * m.mxarr[2][3] -
			m.mxarr[3][1] * m.mxarr[1][3] * m.mxarr[2][2];

		inv.mxarr[1][0] = -m.mxarr[1][0] * m.mxarr[2][2] * m.mxarr[3][3] +
			m.mxarr[1][0] * m.mxarr[2][3] * m.mxarr[3][2] +
			m.mxarr[2][0] * m.mxarr[1][2] * m.mxarr[3][3] -
			m.mxarr[2][0] * m.mxarr[1][3] * m.mxarr[3][2] -
			m.mxarr[3][3] * m.mxarr[1][2] * m.mxarr[2][3] +
			m.mxarr[3][0] * m.mxarr[1][3] * m.mxarr[2][2];

		inv.mxarr[2][0] = m.mxarr[1][0] * m.mxarr[2][1] * m.mxarr[3][3] -
			m.mxarr[1][0] * m.mxarr[2][3] * m.mxarr[3][1] -
			m.mxarr[2][0] * m.mxarr[1][1] * m.mxarr[3][3] +
			m.mxarr[2][0] * m.mxarr[1][3] * m.mxarr[3][1] +
			m.mxarr[3][0] * m.mxarr[1][1] * m.mxarr[2][3] -
			m.mxarr[3][0] * m.mxarr[1][3] * m.mxarr[2][1];

		inv.mxarr[3][0] = -m.mxarr[1][0] * m.mxarr[2][1] * m.mxarr[3][2] +
			m.mxarr[1][0] * m.mxarr[2][2] * m.mxarr[3][1] +
			m.mxarr[2][0] * m.mxarr[1][1] * m.mxarr[3][2] -
			m.mxarr[2][0] * m.mxarr[1][2] * m.mxarr[3][1] -
			m.mxarr[3][0] * m.mxarr[1][1] * m.mxarr[2][2] +
			m.mxarr[3][0] * m.mxarr[1][2] * m.mxarr[2][1];

		inv.mxarr[0][1] = -m.mxarr[0][1] * m.mxarr[2][2] * m.mxarr[3][3] +
			m.mxarr[0][1] * m.mxarr[2][3] * m.mxarr[3][2] +
			m.mxarr[2][1] * m.mxarr[0][2] * m.mxarr[3][3] -
			m.mxarr[2][1] * m.mxarr[0][3] * m.mxarr[3][2] -
			m.mxarr[3][1] * m.mxarr[0][2] * m.mxarr[2][3] +
			m.mxarr[3][1] * m.mxarr[0][3] * m.mxarr[2][2];

		inv.mxarr[1][1] = m.mxarr[0][0] * m.mxarr[2][2] * m.mxarr[3][3] -
			m.mxarr[0][0] * m.mxarr[2][3] * m.mxarr[3][2] -
			m.mxarr[2][0] * m.mxarr[0][2] * m.mxarr[3][3] +
			m.mxarr[2][0] * m.mxarr[0][3] * m.mxarr[3][2] +
			m.mxarr[3][0] * m.mxarr[0][2] * m.mxarr[2][3] -
			m.mxarr[3][0] * m.mxarr[0][3] * m.mxarr[2][2];

		inv.mxarr[2][1] = -m.mxarr[0][0] * m.mxarr[2][1] * m.mxarr[3][3] +
			m.mxarr[0][0] * m.mxarr[2][3] * m.mxarr[3][1] +
			m.mxarr[2][0] * m.mxarr[0][1] * m.mxarr[3][3] -
			m.mxarr[2][0] * m.mxarr[0][3] * m.mxarr[3][1] -
			m.mxarr[3][0] * m.mxarr[0][1] * m.mxarr[2][3] +
			m.mxarr[3][0] * m.mxarr[0][3] * m.mxarr[2][1];

		inv.mxarr[3][1] = m.mxarr[0][0] * m.mxarr[2][1] * m.mxarr[3][2] -
			m.mxarr[0][0] * m.mxarr[2][2] * m.mxarr[3][1] -
			m.mxarr[2][0] * m.mxarr[0][1] * m.mxarr[3][2] +
			m.mxarr[2][0] * m.mxarr[0][2] * m.mxarr[3][1] +
			m.mxarr[3][0] * m.mxarr[0][1] * m.mxarr[2][2] -
			m.mxarr[3][0] * m.mxarr[0][2] * m.mxarr[2][1];

		inv.mxarr[0][2] = m.mxarr[0][1] * m.mxarr[1][2] * m.mxarr[3][3] -
			m.mxarr[0][1] * m.mxarr[1][3] * m.mxarr[3][2] -
			m.mxarr[1][1] * m.mxarr[0][2] * m.mxarr[3][3] +
			m.mxarr[1][1] * m.mxarr[0][3] * m.mxarr[3][2] +
			m.mxarr[3][1] * m.mxarr[0][2] * m.mxarr[1][3] -
			m.mxarr[3][1] * m.mxarr[0][3] * m.mxarr[1][2];

		inv.mxarr[1][2] = -m.mxarr[0][0] * m.mxarr[1][2] * m.mxarr[3][3] +
			m.mxarr[0][0] * m.mxarr[1][3] * m.mxarr[3][2] +
			m.mxarr[1][0] * m.mxarr[0][2] * m.mxarr[3][3] -
			m.mxarr[1][0] * m.mxarr[0][3] * m.mxarr[3][2] -
			m.mxarr[3][0] * m.mxarr[0][2] * m.mxarr[1][3] +
			m.mxarr[3][0] * m.mxarr[0][3] * m.mxarr[1][2];

		inv.mxarr[2][2] = m.mxarr[0][0] * m.mxarr[1][1] * m.mxarr[3][3] -
			m.mxarr[0][0] * m.mxarr[1][3] * m.mxarr[3][1] -
			m.mxarr[1][0] * m.mxarr[0][1] * m.mxarr[3][3] +
			m.mxarr[1][0] * m.mxarr[0][3] * m.mxarr[3][1] +
			m.mxarr[3][0] * m.mxarr[0][1] * m.mxarr[1][3] -
			m.mxarr[3][0] * m.mxarr[0][3] * m.mxarr[1][1];

		inv.mxarr[3][2] = -m.mxarr[0][0] * m.mxarr[1][1] * m.mxarr[3][2] +
			m.mxarr[0][0] * m.mxarr[1][2] * m.mxarr[3][1] +
			m.mxarr[1][0] * m.mxarr[0][1] * m.mxarr[3][2] -
			m.mxarr[1][0] * m.mxarr[0][2] * m.mxarr[3][1] -
			m.mxarr[3][0] * m.mxarr[0][1] * m.mxarr[1][2] +
			m.mxarr[3][0] * m.mxarr[0][2] * m.mxarr[1][1];

		inv.mxarr[0][3] = -m.mxarr[0][1] * m.mxarr[1][2] * m.mxarr[2][3] +
			m.mxarr[0][1] * m.mxarr[1][3] * m.mxarr[2][2] +
			m.mxarr[1][1] * m.mxarr[0][2] * m.mxarr[2][3] -
			m.mxarr[1][1] * m.mxarr[0][3] * m.mxarr[2][2] -
			m.mxarr[2][1] * m.mxarr[0][2] * m.mxarr[1][3] +
			m.mxarr[2][1] * m.mxarr[0][3] * m.mxarr[1][2];

		inv.mxarr[1][3] = m.mxarr[0][0] * m.mxarr[1][2] * m.mxarr[2][3] -
			m.mxarr[0][0] * m.mxarr[1][3] * m.mxarr[2][2] -
			m.mxarr[1][0] * m.mxarr[0][2] * m.mxarr[2][3] +
			m.mxarr[1][0] * m.mxarr[0][3] * m.mxarr[2][2] +
			m.mxarr[2][0] * m.mxarr[0][2] * m.mxarr[1][3] -
			m.mxarr[2][0] * m.mxarr[0][3] * m.mxarr[1][2];

		inv.mxarr[2][3] = -m.mxarr[0][0] * m.mxarr[1][1] * m.mxarr[2][3] +
			m.mxarr[0][0] * m.mxarr[1][3] * m.mxarr[2][1] +
			m.mxarr[1][0] * m.mxarr[0][1] * m.mxarr[2][3] -
			m.mxarr[1][0] * m.mxarr[0][3] * m.mxarr[2][1] -
			m.mxarr[2][0] * m.mxarr[0][1] * m.mxarr[1][3] +
			m.mxarr[2][0] * m.mxarr[0][3] * m.mxarr[1][1];

		inv.mxarr[3][3] = m.mxarr[0][0] * m.mxarr[1][1] * m.mxarr[2][2] -
			m.mxarr[0][0] * m.mxarr[1][2] * m.mxarr[2][1] -
			m.mxarr[1][0] * m.mxarr[0][1] * m.mxarr[2][2] +
			m.mxarr[1][0] * m.mxarr[0][2] * m.mxarr[2][1] +
			m.mxarr[2][0] * m.mxarr[0][1] * m.mxarr[1][2] -
			m.mxarr[2][0] * m.mxarr[0][2] * m.mxarr[1][1];

		float det = m.mxarr[0][0] * inv.mxarr[0][0] + m.mxarr[0][1] * inv.mxarr[1][0] + m.mxarr[0][2] * inv.mxarr[2][0] + m.mxarr[0][3] * inv.mxarr[3][0];

		if (det == 0) {
			throw("Determinant is 0");
		}
		else {
			det = 1.0f / det;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; i < 4; i++) {
					inv.mxarr[i][j] * det;
				}
			}
			m = inv;
		}
	}

	///
	/// Translate
	///
	Matrix4D translation(Vector4D v) {
		Matrix4D transmx(1.0f, 0.0f, 0.0f, v.x(),
				         0.0f, 1.0f, 0.0f, v.y(),
			             0.0f, 0.0f, 1.0f, v.z(),
			             0.0f, 0.0f, 0.0f, 1.0f);
		return transmx;
	}

	///
	///Rotation around x-axis
	///
	Matrix4D rotx(float d) {
		float cs = cos(d);
		float sn = sin(d);
		Matrix4D rot(1, 0, 0, 0, 
			         0, cs, -sn, 0,
			         0, sn, cs, 0,
			         0, 0, 0, 1);
		return rot;
	}

	///
	///Rotation around y-axis 
	///
	Matrix4D roty(float d) {
		float cs = cos(d);
		float sn = sin(d);
		Matrix4D rot(cs, 0, -sn, 0,
					 0, 1,  0,  0,
					 sn, 0, cs, 0,
					 0,  0,  0,  1);
		return rot;
	}

	///
	///Rotation around z-axis 
	///
	Matrix4D rotz(float d) {
		float cs = cos(d);
		float sn = sin(d);
		Matrix4D rot(
			cs, -sn, 0, 0,
			sn, cs, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1);
		return rot;
	}
	///
	///Rotation around Vector
	///
	Matrix4D rodriguesrotate(Vector4D vec, float d) {
		float cs = cos(d);
		float onedown = 1 - cos(d); 
		float sn = sin(d);

		float x = vec.x();
		float y = vec.y();
		float z = vec.z();

		Matrix4D rod(
			cos(d) + x * x * onedown, x * y * onedown - z * sn, y * sn + x * z * onedown,
			0, z * sn + x * y * onedown, cos(d) + y * y * onedown, -x * sn + y * z * onedown, 0,
			-y * sn + x * z * onedown, x * sn + y * z * onedown, cos(d) + z * z * onedown, 0,
			0, 0, 0, 1
		);
	}


};