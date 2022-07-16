#include "Quad.h"
#include "GUIEditor.h"

float a = 45;

float r = 900.0, l = 0.0, b = 0.0,t = 900.0, f = 100, n = 0.1, fov = 45, v = -2;

void Quad::Render(float time)
{
	float sc = tan(fov * 3.14 / 180) * n;
	r = sc;
	l = -r;
	t = sc;
	b = -t;
	float p[16] =
	{
		2 * n/(r-l),		  0,	  r+l,	     	0,
				   0, 2*n/(t-b),	   0,	 		0,
		0,				  0,	   (-f - n)/(f-n),	0,
		0,				  0,				   -1,	1
	};
	float view[16] =
	{
		1,	0,	0,	0,
		0,	1,	0,	0,
		0,	0,  v, 0,
		0,  0,	0,	1
	};
	ImGui::Begin("Perspective Projection:");
	ImGui::SliderFloat("fov", &fov, 0, 180);
	ImGui::SliderFloat("f", &f, 0, 100);
	ImGui::SliderFloat("n", &n, 0, 0.6);
	ImGui::SliderFloat("r", &r, 0, 900);
	ImGui::SliderFloat("l", &l, 0, 900);
	ImGui::SliderFloat("t", &t, 0, 900);
	ImGui::SliderFloat("b", &b, 0, 900);
	ImGui::SliderFloat("a", &a, 0, 10);
	ImGui::SliderFloat("view", &v, 0, 10);

	float mat[16] =
	{
		1,		0,		 0, 0,
		0, cos(a), -sin(a),0,
		0, sin(a),  cos(a),0,
		0,  0, 0,			1
	};
	ImGui::End();
	glUseProgram(_shader);
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glUniformMatrix4fv(glGetUniformLocation(_shader, "model"), 1, GL_FALSE, mat);
	glUniformMatrix4fv(glGetUniformLocation(_shader, "perspective"), 1, GL_FALSE, p);
	glUniformMatrix4fv(glGetUniformLocation(_shader, "view"), 1, GL_FALSE, view);
	glUniform1f(glGetUniformLocation(_shader, "u_time"), time);
	glUniform2f(glGetUniformLocation(_shader, "u_resolution"), 300, 300);
}
