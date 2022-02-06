#include "GrassTerrasse.h"

GrassTerrasse::GrassTerrasse(int grassbladesnumber, int shaderID)
{
	_grassbladesnumber	= grassbladesnumber;
	_shaderID			= shaderID;

	grassblades = new GrassBlade*[grassbladesnumber];
	for (size_t i = 0; i < grassbladesnumber; i++)
		grassblades[i] = new GrassBlade(shaderID, 0.1f, -0.5f + (i / 100.0f), -0.7f);
}

void	GrassTerrasse::renderterrasse(float time)
{
	for (size_t i = 0; i < _grassbladesnumber; i++)
		grassblades[i]->renderblade(_shaderID, time);
}
