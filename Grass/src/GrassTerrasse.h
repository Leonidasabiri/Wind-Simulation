#pragma once
#include "GrassBlade.h"
#include "Math.h"

class GrassTerrasse
{
private:
	unsigned int		instanceVBO = 0;
	int					_shaderID;
	int					_grassbladesnumber = 0;
	Vector2<float>		vec[20000];
	GrassBlade			*grassblades;
public:
	GrassTerrasse();
	GrassTerrasse(int grassbladesnumber, int shaderID);
	void	renderterrasse(float time);
	//~GrassTerrasse();
};