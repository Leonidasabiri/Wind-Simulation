#include "Quad.h"

void Quad::Render(unsigned int shaderID, Vector2<float> res, float time)
{
	glUseProgram(shaderID);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glUniform1f(glGetUniformLocation(shaderID, "u_time"), time);
	glUniform2f(glGetUniformLocation(shaderID, "u_resolution"), 500, 500);
}