#pragma once
#include "Vector.h"

template<typename T>
class Vector3
{
private:
	float	_x, _y, _z;
public:
	Vector3(float x, float y, float z)
	{
		_x = x;
		_y = y;
		_z = z;
	}
	Vector3 operator + (Vector3 const& vec);
	Vector3 operator - (Vector3 const& vec);
	Vector3 operator * (Vector3 const& vec1, Vector3 const& vec2);
	Vector3 operator / ();
};

template<typename T>
class Vector2
{
private:
	float	_x, _y;
public:
	Vector2(float x, float y)
	{
		_x = x;
		_y = y;
	}
	Vector2 operator + (Vector2 const& vec);
	Vector2 operator - (Vector2 const& vec);
	Vector2 operator * (Vector2 const& vec1, Vector2 const& vec2);
	Vector2 operator / ();
};

template<typename T>
Vector3<T> Vector3<T>::operator+(Vector3<T> const& vec)
{
	vec._x += _x;
	vec._y += _y;
	vec._z += _z;
	return vec;
}

template<typename T>
Vector3<T> Vector3<T>::operator-(Vector3<T> const& vec)
{
	vec._x -= _x;
	vec._y -= _y;
	vec._z -= _z;
	return vec;
}

template<typename T>
Vector2<T> Vector2<T>::operator+(Vector2<T> const& vec)
{
	vec._x += _x;
	vec._y += _y;
	return vec;
}

template<typename T>
Vector2<T> Vector2<T>::operator-(Vector2<T> const& vec)
{
	vec._x -= _x;
	vec._y -= _y;
	return vec;
}

//template<typename T>
//Vector3<T> Vector3<T>::operator * (Vector3<T> const& vec1, Vector3<T> const& vec2)
//{
//	return vec1;
//}