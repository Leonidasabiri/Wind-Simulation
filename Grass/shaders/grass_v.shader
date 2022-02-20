#version 330 core

layout (location = 0) in vec2 pos;
layout (location = 1) in vec3 col;
layout (location = 2) in vec2 Offset;

out vec3 color;

uniform mat4	model;
uniform mat4	view;
uniform mat4	projection;

uniform float	u_time;
uniform float	u_mouse;

void	main()
{
	gl_Position =  vec4(pos + Offset, 0.0,1.0);
	color = vec3(0.0f, 1.0f, 0.0f);
}