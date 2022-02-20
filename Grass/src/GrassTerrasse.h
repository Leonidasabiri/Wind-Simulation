#pragma once
#include "GrassBlade.h"
#include "Math.h"

class GrassTerrasse
{
private:
	int					_shaderID;
	int					_grassbladesnumber = 0;
	Vector2<float>		vec[4800];
	GrassBlade			*grassblades;
public:
	GrassTerrasse();
	GrassTerrasse(int grassbladesnumber, int shaderID);
	void	renderterrasse(float time);
	//~GrassTerrasse();
};