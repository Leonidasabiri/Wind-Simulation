<h1 align="center"> Wind-Simulation </h1>

# Still Under developement
## To do:
	- Implement perspective projection matrix
	- Add blending and depth testing
	- Add multitherading for rendering
	- Add compute shader for parallel cpu/gpu computing
	- Cubemaps for skybox after transforming stuff to 3D 
## [-About the project](#about-the-project)
## [-The approach](#the-approach)

# about-the-project

This is a grass simulation written with c++ and based on the opengl API, it contains grass blades with segments that gets affected by gravity and wind force.

# the-approach

The first thing to do is to create a single grass blade with segments that can rotate using a simple rotation matrix, having that single grass blade work kinda made the rest of the process on how to code this simulation clear enough to experiment some ideas, .. to make things simple and keep track of what i will be doing i went with 2D first.

- The segements where made and updated with the following array of vertices (the number of vertices isn't set yet to add more details to the grass blade) and indecies:
```c++
	float	vertices[27] =
	{
			segment3.x1 * _size,	segment3.y2 * _size, 0.0f,
			segment3.x1 * _size,	segment3.y1 * _size, 0.0f,
			segment3.x2 * _size,	segment3.y2 * _size, 0.0f,
			segment3.x2 * _size,	segment3.y1 * _size, 0.0f,
			segment2.x1 * _size,	segment2.y1 * _size, 0.0f,
			segment2.x2 * _size,	segment2.y2 * _size, 0.0f,
			segment1.x1 * _size,	segment1.y1 * _size, 0.0f,
			segment1.x2 * _size,	segment1.y2 * _size, 0.0f,
			headSegm.x1 * _size,	headSegm.y1 * _size, 0.0f
	};
	int		indecies[21] =
	{
		0, 2, 1,
		1, 3, 2,
		1, 3, 4,
		3, 4, 5,
		4, 5, 6,
		5, 6, 7,
		6, 7, 8
	};
```
- Here i set the struct of the segement to have more flexibility over the rotation and deformation:
```c++
	typedef struct Segement
	{
		float	x1;
		float	y1;
		float	x2;
		float	y2;
		float	density;
	}Seg;
```
- And i used the following rotation matrix implementation in Matrix.h header file:
```c++
template <typename T>
std::pair<T, T>	Matrix2x2<T>::rotation(T x, T y, T angle)
{
	return std::make_pair  ( (x * cos(angle)) - (y * sin(angle)) ,
							 (x * sin(angle)) + (y * cos(angle)) );
}
```
- Applying the rotation on the segments:
```c++
Segement	GrassBlade::segementrotater(float x1, float y1, float x2, float y2, float velocity)
{
	Matrix2x2<float>	mat2x2;
	Segement	newsegment =
	{
		mat2x2.rotation(x1, y1, velocity + angle).first,
		mat2x2.rotation(x1, y1, velocity + angle).second,
		mat2x2.rotation(x2, y2, velocity + angle).first,
		mat2x2.rotation(x2, y2, velocity + angle).second,
	};
	return newsegment;
}
```

## The segment at the start
<img src="https://user-images.githubusercontent.com/54768823/149226084-12adf85c-8411-4d1d-9c7b-5dfa3c8a30ca.gif" width=250>

## Using noise for winds
To make the grass swaying look like it's been affected by actual wind, using generated shader noise is perfect approach for that, i tried getting the x and y value from the noise to affect each grass blade on it's own, the grass terrass is rendered using GPU instancing to save memory and to hold performance even if the grass blades are more than 200000 blade.

-the noise shader works as the following, first we make the infamouse random function method implementation.
```glsl
float random(vec2 uv)
{
	return fract(sin(dot(uv.xy, vec2(12.9898, 78.233))) * 43758.5453123);
}
```
-then we use this function to modify the x, y cooridnates pixels
```glsl
float noise(in vec2 uv)
{
	vec2 x = floor(uv);
	vec2 y = fract(uv);
	
	float a = random(x);
	float b	= random(x + vec2(1.0, 0.0));
	float c	= random(x + vec2(0.0, 1.0));
	float d = random(x + vec2(1.0, 1.0));

	vec2 u = y * y * (2. - 1. * y);
	float result = mix(a, b, u.x) + (c - a) * u.y * (1.0 - u.x) + (d - b) * u.x * u.y;

	return result;
}
```
-then we use fractal brownian motion for more diversity in the noise pattern
```glsl
#define NUM_OCTAVES 100

mat2	rotate(float angle)
{
	return	mat2(cos(angle), sin(angle),
				-sin(angle), cos(angle));
}

float fbm(in vec2 st, float angle)
{
	float v = 0.0;
	float a = 0.5;
	vec2 shift = vec2(150.0);
	
	mat2 rot =  rotate(3.0);
	for (int i = 0; i < NUM_OCTAVES; ++i)
	{
		v += a * noise(st);
		st = rot * st * 2.0 + shift;
		a *= 0.5;
	}
	return v;
}
```
(Thanks to the book of shaders i knew how to make the noise.)
- A note about the approach of writing the noise in shader :
	. Maybe i should make the noise in the cpu so i can rotate the segements of each blade , but the thing is i should keep the gpu instancing.
