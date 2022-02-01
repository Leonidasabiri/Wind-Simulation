#pragma once
#include <utility>
#include "Vector.h"

template<typename T>
class Matrix3x3
{
public:
	Matrix3x3 operator + (const &Matrix mat1, const& Matrix mat2);
	Matrix3x3 operator * (const &Matrix mat1, const& Matrix mat2);
	// Projection
	// Model
	// View
	// Scaling matrix
	// Rotation
	//std::tuple<T, T, T> rotation(T x, T y, T z, T angle);
};

template <typename T>
class Matrix2x2
{
public:
	std::pair<T, T>	rotation(T x, T y, T angle);
};

template <typename T>
std::pair<T, T>	Matrix2x2<T>::rotation(T x, T y, T angle)
{
	return std::make_pair  ( (x * cos(angle)) - (y * sin(angle)) ,
							 (x * sin(angle)) + (y * cos(angle)) );
}
