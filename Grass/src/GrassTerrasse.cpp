#include "GrassTerrasse.h"
#include <string>

GrassTerrasse::GrassTerrasse(int grassbladesnumber, int shaderID)
{
	grassblades = new GrassBlade(shaderID, -0.2f, 0.0f, 0.0f);
	_grassbladesnumber	= grassbladesnumber;
	_shaderID			= shaderID;
}

void	GrassTerrasse::renderterrasse(float time)
{
	size_t	ind = 0;
	for (size_t i = 1; i < 60; i++)
	{
		for (size_t j = 1; j < 60; j++)
		{
			Vector2<float>	pos;
			pos._x = -1.0 + i / 20.0f;
			pos._y = -1.0 + j / 20.0f;
			vec[ind++] = pos;
		}
	}
	for (size_t i = 0; i < 2000; i++)
	{
		std::string t("offsets["+std::to_string(i) + "]");
		glUniform2f(glGetUniformLocation(_shaderID, t.c_str()), vec[i]._x, vec[i]._y);
	}
	grassblades->renderblade(_shaderID, time);
}
