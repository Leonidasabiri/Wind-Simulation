#pragma once
#include <glad/glad.h>

typedef struct Vector2
{
	float	w, h;
}Vec2;

class Quad
{
public:
	unsigned int VAO, VBO, EBO;
	int		_w = 0, _h = 0;
	Quad(int w, int h)
	{
		_w = w, _h = h;
		float	vertices[12] =
		{
			-static_cast<float>(_w),  static_cast<float>(_h), 0.0f,
			 static_cast<float>(_w),  static_cast<float>(_h), 0.0f,
			-static_cast<float>(_w), -static_cast<float>(_h), 0.0f,
			 static_cast<float>(_w), -static_cast<float>(_h), 0.0f
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
	void	Render(unsigned int shaderID, Vec2 res, float time);
private:

};
