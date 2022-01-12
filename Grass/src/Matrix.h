#pragma once
#include <utility>

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