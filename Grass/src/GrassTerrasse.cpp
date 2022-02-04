#include "GrassTerrasse.h"

GrassTerrasse::GrassTerrasse(int grassbladesnumber, int shaderID)
{
	_grassbladesnumber	= grassbladesnumber;
	_shaderID			= shaderID;

	grassblades = new GrassBlade*[grassbladesnumber];
	for (size_t i = 0; i < 400; i++)
		grassblades[i] = new GrassBlade(shaderID, 0.1f, -1.2f + (i / 100.0f), -0.7f);
}

void	GrassTerrasse::renderterrasse(float time)
{
	for (size_t i = 0; i < 400; i++)
		grassblades[i]->renderblade(_shaderID, time);
}
