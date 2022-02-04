#version 330 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 col;

out vec3 color;

uniform mat4	model;
uniform mat4	view;
uniform mat4	projection;

uniform float	u_time;
uniform float	u_mouse;
uniform float	offsetx;
uniform float	offsety;

void	main()
{
	gl_Position = vec4(pos.x + offsetx, pos.y + offsety, pos.z, 1.0);
	color = vec3(0.0f, 1.0f + offsetx, 0.0f);
}