#include "Quad.h"

void Quad::Render(unsigned int shaderID, Vec2 res, float time)
{
	glUseProgram(shaderID);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glUniform1f(glGetUniformLocation(shaderID, "u_time"), time);
	glUniform2f(glGetUniformLocation(shaderID, "u_resolution"), res.w, res.h);
}