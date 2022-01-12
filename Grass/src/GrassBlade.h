#pragma once
#include <glad/glad.h>
#include "ShaderCodeParser.h"

typedef struct Segement
{
	float	x1;
	float	y1;
	float	x2;
	float	y2;
	float	density;
}Seg;

class GrassBlade
{
public:
	float	angle = 0.0f;
	float	_size = 0.0f, _x = 0.0f, _y = 0.0f;
	float	width = 0.02f, height = 0.1f;
	unsigned int	VAO = 0, VBO = 0, EBO = 0;

	int		segement_numbers = 0;
	float	bladehead = 0.0f;

	// REMINDER 
	// THE GRASS SEGMENTS AREN'T GOING TO BE DONE LIKE THIS DUMB ASS !!!!!!!!!!!!!!!!!!!!!!!
	// YOU SHOULD CALCULATE THE GRAVITY FORCE APPLIED ON EACH GRASS SEGEMENT WITH STIFNESS COEFFICIENT !!!!!!!!
	// YOU SHOULD HANDLE ROTATIONS FOR EACH FUCKING GRASS SEGMENT !!!!!!!!!!!!!!!!!!!
	// AND HANDLE GRAVITY FORCE FOR EACH JOINT... USE YOUR FUCKING BRAIN !!!!!!!!!!!!!!!!!!!!!!
	
	GrassBlade();
	GrassBlade(unsigned int shaderID, float size, float x, float y);
	void	renderblade(unsigned int shaderID, float time);
	void	grassSway(float time);
	Segement	segementrotater(float x1, float y1, float x2, float y2, float velocity);
//	~GrassBlade();
};
