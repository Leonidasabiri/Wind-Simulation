#pragma once
#include "GrassBlade.h"
#include "Math.h"

class GrassTerrasse
{
private:
	unsigned int		instanceVBO = 0;
	int					_shaderID;
	int					_grassbladesnumber = 0;
	Vector2<float>		*vec = new Vector2<float>[400000];
	Matrix2x2<float>	*rot= new Matrix2x2<float>[400000];
	GrassBlade			*grassblades;
public:
	GrassTerrasse();
	GrassTerrasse(int grassbladesnumber, int shaderID);
	void	renderterrasse(float time);
	//~GrassTerrasse();
};