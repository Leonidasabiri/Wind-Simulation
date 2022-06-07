#include "Quad.h"

void Quad::Render(float time)
{
	glUseProgram(_shader);
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glUniform1f(glGetUniformLocation(_shader, "u_time"), time);
	glUniform2f(glGetUniformLocation(_shader, "u_resolution"), 300, 300);
}
