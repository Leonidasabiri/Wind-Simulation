<p> align="center"
# Grass-Simulation
</p>

# [-The approach](#the-approach)

- About the project

This is grass simulation written with c++ and based on the opengl API, it contains grass blades with segments that gets affected by gravity and wind force.

# the-approach

The first thing to do is to create a single grass blade with segments that can rotate using a simple rotation matrix, having that single grass blade work kinda made the rest of the process on how to code this simulation clear enough to experiment some ideas, .. to make things simple and keep track of what i will be doing i went with 2D first.

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
	// Rotate to reduce axial bias
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
Thanks to the book of shaders i knew how to make this.
