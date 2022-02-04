#pragma once
#include "GrassBlade.h"

class GrassTerrasse
{
private:
	int					_shaderID;
	int					_grassbladesnumber = 0;
	GrassBlade**		grassblades;
public:
	GrassTerrasse(int grassbladesnumber, int shaderID);
	void	renderterrasse(float time);
	//~GrassTerrasse();
};