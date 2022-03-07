#include "GrassTerrasse.h"
#include <string>

GrassTerrasse::GrassTerrasse(int grassbladesnumber, int shaderID)
{	
	grassblades = new GrassBlade(shaderID, 0.09, 0.0f, 0.0f);
	_grassbladesnumber	= grassbladesnumber;
	_shaderID			= shaderID;
	
	size_t	ind = 0;
	for (size_t i = 1; i < 300; i++)
	{
		for (size_t j = 1; j < 60; j++)
		{
			Vector2<float>	pos;
			pos._x = -0.7 + i / 40.0f;
			pos._y = -0.7 + j / 40.0f;
			vec[ind++] = pos;
		}
	}
	glGenBuffers(1, &instanceVBO);
	glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vector2<float>) * 400000, &vec[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void	GrassTerrasse::renderterrasse(float time)
{
	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glVertexAttribDivisor(2, 1);
	grassblades->renderblade(_shaderID, time);
}
