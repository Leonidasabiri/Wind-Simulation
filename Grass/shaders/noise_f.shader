#version 330 core

#define NUM_OCTAVES 100

uniform	vec2	u_resolution;
uniform float	u_time;

float random(vec2 uv)
{
	return fract(sin(dot(uv.xy, vec2(12.9898, 78.233))) * 43758.5453123);
}

float noise(in vec2 uv)
{
	vec2 x = floor(uv);
	vec2 y = fract(uv);
	
	float a = random(x);
	float b	= random(x + vec2(1.0, 0.0));
	float c	= random(x + vec2(0.0, 1.0));
	float d = random(x + vec2(1.0, 1.0));

	vec2 u = y * y * (2. - 1. * y);
	float result = mix(a, b, u.x) + (c - a)
				* u.y * (1.0 - u.x) + (d - b)
				* u.x * u.y;
	return result;
}

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

void main()
{
	vec2 st = gl_FragCoord.xy/u_resolution.xy;
	st.x *= u_resolution.x / u_resolution.y;
	vec3 color = vec3(0.0);
	float noise = noise(st * 6.0 + u_time);
	float fractal = fbm(st * 6.0 + u_time, 0.5);
	color = vec3(mix(noise, fractal, abs(sin(5.0))));
	gl_FragColor = vec4(color, 1.0);
}
