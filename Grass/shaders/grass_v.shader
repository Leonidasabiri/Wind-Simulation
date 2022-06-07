#version 330 core

layout (location = 0) in vec2 pos;
layout (location = 1) in vec3 col;
layout (location = 2) in vec2 Offset;

out vec3 color;

uniform	vec2	u_resolution;

uniform mat4	model;
uniform mat4	view;
uniform mat4	projection;

uniform float	angle;
uniform float	u_time;
uniform float	u_mouse;

float rand(vec2 uv)
{
	return fract(sin(dot(uv.xy, vec2(12.9898, 78.233))) * 43758.5453123);
}

mat2	rotate(float angle)
{
	return	mat2(cos(angle), sin(angle),
		-sin(angle), cos(angle));
}

float noise(in vec2 uv)
{
	vec2 x = floor(uv);
	vec2 y = fract(uv);

	float a = rand(x);
	float b = rand(x + vec2(1.0, 0.0));
	float c = rand(x + vec2(0.0, 1.0));
	float d = rand(x + vec2(1.0, 1.0));

	vec2 u = y * y * (2. - 1. * y);
	float result = mix(a, b, u.x) + (c - a)
		* u.y * (1.0 - u.x) + (d - b)
		* u.x * u.y;
	return result;
}

#define NUM_OCTAVES 3

float fbm(in vec2 st, float angle)
{
	float v = 0.0;
	float a = 0.5;
	vec2 shift = vec2(1.0);

	mat2 rot = rotate(3.0);
	for (int i = 0; i < NUM_OCTAVES; ++i)
	{
		v += a * noise(st);
		st = rot * st * 2.0 + shift;
		a *= 0.5;
	}
	return v;
}

void	main()
{
	vec2 Pos = pos;
	vec2 st = (vec2(100.0, 100.0) * rand(pos)).xy;
	st.xy *= u_resolution.x / u_resolution.y;
	float noise1 = noise(st * gl_InstanceID * (u_time / 100.));
	float fractal = fbm(st, 0.0);
//	Pos += gl_InstanceID;
	gl_Position =  vec4(Pos * rotate(90.0) * noise1 + Offset, 0.0,1.0);
}
