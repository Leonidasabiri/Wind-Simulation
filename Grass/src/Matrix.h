#pragma once
#include <utility>
#include "Vector.h"

template<typename T>
class Matrix3x3
{
private:
	Vector3<T> _vec3[3];
public:
	Matrix3x3(Vector3<T> vec3[3]);
	void	operator + (Matrix3x3 const& mat);
	void	operator - (Matrix3x3 const& mat);
	void	operator * (Matrix3x3 const& mat);
	void	scalarproduct(T scale);
	// Projection
	// Model
	// View
	// Scaling matrix
	// Rotation
};


typedef struct ResultingVector
{
	int	x, y, z, w;
};

template<typename T>
class Matrix4x4
{
public:
	ResultingVector	vector;
	T	diagonalvalue;
	T	identitymatrix[4][4] =
	{
		{ diagonalvalue, 0, 0, 0 },
		{ 0, diagonalvalue, 0, 0 },
		{ 0, 0, diagonalvalue, 0 },
		{ 0, 0, 0, diagonalvalue }
	};
	T	scalingmatrix[4][4];
	T	transformmatrix[4][4];
	Matrix4x4<T>(T diagonalvalue)
	{
		this->diagonalvalue = diagonalvalue;
	}
	// Identity Matrix
	void	IdentityMatrixMultiplication(Vector3<T> vec3)
	{
		vec3._x *= identitymatrix[0][0];
		vec3._y *= identitymatrix[1][1];
		vec3._z *= identitymatrix[2][2];
		vector = 
		{
				vec3._x,
				vec3._y,
				vec3._z,
				1
		};
	}
	// Scaling
	void	ScalingMatrixMultiplication(Vector3<T> vec3)
	{
		vec3._x *= vector.x;
		vec3._y *= vector.y;
		vec3._z *= vector.z;
		vector =
		{
			vec3._x,
			vec3._y,
			vec3._z,
			1
		};
	}
	// Translation
	void	TranslationMatrixMultiplication(Vector3<T> vec3)
	{
		vector.x += vec3._x;
		vector.y += vec3._y;
		vector.z += vec3._z;
	}
};

template <typename T>
class Matrix2x2
{
public:
	std::pair<T, T>	rotation(T x, T y, T angle);
};

template <typename T>
Matrix3x3<T>::Matrix3x3(Vector3<T> vec3[3])
{
	for (size_t i = 0; i < 3; i++)
	{
		_vec3[i]._x = vec3[i]._x;
		_vec3[i]._y = vec3[i]._y;
		_vec3[i]._z = vec3[i]._z;
	}
}

template<typename T>
void	Matrix3x3<T>::operator + (Matrix3x3<T> const &mat1)
{
	Vector3<T>	vec3;

	for (size_t i = 0; i < 3; i++)
	{
		vec3[i].x = _vec3[i]._x + mat1._vec3[i].x;
		vec3[i].y = _vec3[i]._y + mat1._vec3[i].y;
		vec3[i].z = _vec3[i]._z + mat1._vec3[i].z;
	}
}

template<typename T>
void	Matrix3x3<T>::operator - (Matrix3x3<T> const& mat1)
{
	Vector3<T>	vec3;

	for (size_t i = 0; i < 3; i++)
	{
		vec3[i].x = _vec3[i]._x - mat1._vec3[i].x;
		vec3[i].y = _vec3[i]._y - mat1._vec3[i].y;
		vec3[i].z = _vec3[i]._z - mat1._vec3[i].z;
	}
}

// Finish this
template<typename T>
void	Matrix3x3<T>::operator * (Matrix3x3<T> const& mat1)
{
	Vector3<T>	vec3;

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			vec3[i].x = _vec3[j]._x * mat1[j]._vec3[j].x + _vec3[j]._y *
						mat1[j]._vec3[j].y + _vec3[j]._z * mat1[j]._vec3[j].z;

			vec3[i].y = _vec3[j]._x * mat1[j]._vec3[j].x + _vec3[j]._y * 
						mat1[j]._vec3[j].y + _vec3[j]._z * mat1[j]._vec3[j].z;
			
			vec3[i].z = _vec3[j]._x * mat1[j]._vec3[j].x + _vec3[j]._y * 
						mat1[j]._vec3[j].y + _vec3[j]._z * mat1[j]._vec3[j].z;
		}
	}
}

template<typename T>
void	Matrix3x3<T>::scalarproduct(T scale)
{
	for (size_t i = 0; i < 3; i++)
	{
		_vec3[i].x *= scale;
		_vec3[i].y *= scale;
		_vec3[i].z *= scale;
	}
}

template <typename T>
std::pair<T, T>	Matrix2x2<T>::rotation(T x, T y, T angle)
{
	return std::make_pair  ( (x * cos(angle)) - (y * sin(angle)) ,
							 (x * sin(angle)) + (y * cos(angle)) );
}
