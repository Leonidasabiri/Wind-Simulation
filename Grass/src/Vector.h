#pragma once
#include "Vector.h"

template<typename T>
class Vector3
{
private:
public:
	T	_x, _y, _z;
	Vector3(T x = 0, T y = 0, T z = 0)
	{
		_x = x;
		_y = y;
		_z = z;
	}
	Vector3 operator + (Vector3 const& vec);
	Vector3 operator - (Vector3 const& vec);
	//Vector3 operator * (Vector3 const& vec1, Vector3 const& vec2);
	//Vector3 operator / ();
};

template<typename T>
class Vector4
{
private:
public:
	T	_x, _y, _z, _w;
	Vector4(T x = 0, T y = 0, T z = 0, T w = 0)
	{
		_x = x;
		_y = y;
		_z = z;
		_w = w;
	}
	Vector4 operator + (Vector4 const& vec);
	Vector4 operator - (Vector4 const& vec);
	//Vector3 operator * (Vector3 const& vec1, Vector3 const& vec2);
	//Vector3 operator / ();
};

template<typename T>
class Vector2
{
private:
public:
	T	_x, _y;
	Vector2(T x = 0, T y = 0)
	{
		_x = x;
		_y = y;
	}
	Vector2 operator + (Vector2 const& vec);
	Vector2 operator - (Vector2 const& vec);
	/*Vector2 operator * (Vector2 const& vec1, Vector2 const& vec2);
	Vector2 operator / ();*/
};

template<typename T>
Vector3<T> Vector3<T>::operator+(Vector3<T> const& vec)
{
	Vector3<T> res;

	res._x = vec.x + _x;
	res._y = vec.y + _y;
	res._z = vec.z + _z;
	
	return res;
}

template<typename T>
Vector3<T> Vector3<T>::operator-(Vector3<T> const& vec)
{
	Vector3<T> res;

	res._x = vec.x - _x;
	res._y = vec.y - _y;
	res._z = vec.z - _z;
	return res;
}

template<typename T>
Vector2<T> Vector2<T>::operator+(Vector2<T> const& vec)
{
	Vector2<T> res;
	
	res._x = vec.x +_x;
	res._y = vec.y + _y;
	return res;
}

template<typename T>
Vector2<T> Vector2<T>::operator-(Vector2<T> const& vec)
{
	Vector2<T> res;

	res._x = vec.x - _x;
	res._y = vec.y - _y;
	return res;
}

//template<typename T>
//Vector3<T> Vector3<T>::operator * (Vector3<T> const& vec1, Vector3<T> const& vec2)
//{
//	return vec1;
//}