#pragma once
#include <glad/glad.h>
#include <iostream>
#include "Vector.h"

class Quad
{
public:
	unsigned int VAO, VBO, EBO;
	unsigned int _shader;
	Quad(Vector2<float> vec, unsigned int shader)
	{
		this->_shader = shader;
		float	vertices[12] =
		{
			-vec._x / 10.0f,  vec._y / 10.0f, 0.0f,
			 vec._x / 10.0f,  vec._y / 10.0f, 0.0f,
			-vec._x / 10.0f, -vec._y / 10.0f, 0.0f,
			 vec._x / 10.0f, -vec._y / 10.0f, 0.0f
		};
		int		indecies[6] =
		{
			0, 1, 2,
			1, 3, 2
		};
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);

		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indecies), indecies, GL_DYNAMIC_DRAW);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, nullptr);
		glEnableVertexAttribArray(0);
	}
	void	Render(float time);
};
