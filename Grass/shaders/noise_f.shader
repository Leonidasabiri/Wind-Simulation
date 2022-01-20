#version 330 core

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

	vec2 u = y * y * (3.0 - 2.0 * y);
	float result = mix(a, b, u.x) + (c - a) * u.y * (1.0 - u.x) + (d - b) * u.x * u.y;

	return result;
}

#define NUM_OCTAVES 100
float fbm(in vec2 st) {
	float v = 0.0;
	float a = 0.5;
	vec2 shift = vec2(100.0);
	// Rotate to reduce axial bias
	mat2 rot = mat2(cos(0.5), sin(0.5),
		-sin(0.5), cos(0.50));
	for (int i = 0; i < NUM_OCTAVES; ++i) {
		v += a * noise(st);
		st = rot * st * 2.0 + shift;
		a *= 0.5;
	}
	return v;
}

void main()
{
	float p = 0.0;
	vec2 st = gl_FragCoord.xy / u_resolution.xy;
	st.x *= u_resolution.x / u_resolution.y;
	vec3 color = vec3(0.0);
	p += u_time;
	float noise = noise(st * 12.0);
	float fractal = fbm(st * 12.0 + p);
	color = vec3(mix(noise, fractal, abs(sin(20))));
	gl_FragColor = vec4(color, 1.0);
}
