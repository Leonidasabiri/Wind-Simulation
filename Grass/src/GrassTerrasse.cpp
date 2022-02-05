#include "GrassTerrasse.h"

GrassTerrasse::GrassTerrasse(int grassbladesnumber, int shaderID)
{
	_grassbladesnumber	= grassbladesnumber;
	_shaderID			= shaderID;

	size_t k = 0;
	grassblades = new GrassBlade*[grassbladesnumber];
	for (size_t i = 0; i < 200; i++)
		grassblades[i] = new GrassBlade(shaderID, 0.1f, -0.5f + (i / 100.0f), -0.7f);
	for (size_t i = 200; i < 400; i++, k++)
		grassblades[i] = new GrassBlade(shaderID, 0.1f, -0.5f + (k / 100.0f), -0.75f);
	k = 0;
	for (size_t i = 400; i < 600; i++, k++)
		grassblades[i] = new GrassBlade(shaderID, 0.1f, -0.5f + (k / 100.0f), -0.8f);
	k = 0;
}

void	GrassTerrasse::renderterrasse(float time)
{
	for (size_t i = 0; i < 1200; i++)
		grassblades[i]->renderblade(_shaderID, time);
}
