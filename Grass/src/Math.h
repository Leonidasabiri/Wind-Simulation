#pragma once
#include "Vector.h"
#include "Matrix.h"

namespace Math
{
	template<typename T>
	Vector2<T>	vector2;
	template<typename T>
	Vector3<T>	vecto3;

	template<typename T>
	Matrix2x2<T>	matrix2;
	template<typename T>
	Matrix3x3<T>	matrix3;
	template<typename T>
	Matrix4x4<T>	matrix4;
}