#pragma once

typedef struct velocity
{
	float	x, y, z;
}V;

class Wind
{
public:
	float	velocity = 0.0f;
	
	Wind(float _velocity);
};