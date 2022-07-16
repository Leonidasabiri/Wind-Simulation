#include "GrassBlade.h"
#include "Matrix.h"
#include "Wind.h"

GrassBlade::GrassBlade(unsigned int shaderID, float size, float x, float y)
{
	//this->angle = static_cast<float>(rand())/static_cast<float>(RAND_MAX / 10.8f);
	this->angle = 20.0f;
	this->_size = size;
	this->_x = x;
	this->_y = y;

	float	vertices[27] =
	{
		 width * size - 0.02f, -height * size,	 0.0f,
		 width * size - 0.02f,  height * size,	 0.0f,
		-width * size + 0.02f, -height * size,	 0.0f,
		-width * size + 0.02f,	height * size,	 0.0f,
		 width * size - 0.027f, height * size * 3, 0.0f,
		-width * size + 0.027f, height * size * 3, 0.0f,
		 width * size - 0.03f,  height * size * 5, 0.0f,
		-width * size + 0.03f,  height * size * 5, 0.0f,
		 0.0f  * size,			height * size * 9, 0.0f
	};
	int		indecies[21] =
	{
		0, 2, 1,
		1, 3, 2,
		1, 3, 4,
		3, 4, 5,
		4, 5, 6,
		5, 6, 7,
		6, 7, 8
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

	//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)(sizeof(float) * 3));
	//	glEnableVertexAttribArray(1);
}

Segement	GrassBlade::segementrotater(float x1, float y1, float x2, float y2, float velocity)
{
	Matrix2x2<float>	mat2x2;
	Segement	newsegment =
	{
		mat2x2.rotation(x1, y1, velocity + angle).first,
		mat2x2.rotation(x1, y1, velocity + angle).second,
		mat2x2.rotation(x2, y2, velocity + angle).first,
		mat2x2.rotation(x2, y2, velocity + angle).second,
	};
	return newsegment;
}

void	GrassBlade::grassSway(float time)
{
	Wind				wind(1.0f);

	wind.applyingNoise(0, 0);

	double r = rand() % 5;
	wind.velocity *= sin(time);

	Segement		headSegm = segementrotater(0.05f, height * 9.0f, 0.0f, 0.0f, wind.velocity/10.0f)
	,
	segment1 = segementrotater(width / 1.9f, height * 5.0f, -width / 1.9f, height * 5.0f,
		wind.velocity / 20.0f)
	,
	segment2 = segementrotater(width / 1.77f, height * 3.0f, -width / 1.77f, height * 3.0f, 
		wind.velocity / 40.0f)
	,
	segment3 = segementrotater(width / 1.65f, height, -width / 1.65f, height, 
		wind.velocity /80.0f);
	
	float	vertices[27] =
	{
			segment3.x1 * _size,	segment3.y2 * _size, 0.0f,
			segment3.x1 * _size,	segment3.y1 * _size, 0.0f,
			segment3.x2 * _size,	segment3.y2 * _size, 0.0f,
			segment3.x2 * _size,	segment3.y1 * _size, 0.0f,
			segment2.x1 * _size,	segment2.y1 * _size, 0.0f,
			segment2.x2 * _size,	segment2.y2 * _size, 0.0f,
			segment1.x1 * _size,	segment1.y1 * _size, 0.0f,
			segment1.x2 * _size,	segment1.y2 * _size, 0.0f,
			headSegm.x1 * _size,	headSegm.y1 * _size, 0.0f
	};
	int		indecies[21] =
	{
		0, 2, 1,
		1, 3, 2,
		1, 3, 4,
		3, 4, 5,
		4, 5, 6,
		5, 6, 7,
		6, 7, 8
	};

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indecies), indecies, GL_DYNAMIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, nullptr);
	glEnableVertexAttribArray(0);
}

void	GrassBlade::renderblade(unsigned int shaderID, float time)
{
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	ImGui::Begin("Grass Parameters");
	ImGui::SliderFloat("Size:", &_size, -0.09f, 1.5f);
	ImGui::End();
	glUniform2f(glGetUniformLocation(shaderID, "u_resolution"), 500, 500);
	glUniform1f(glGetUniformLocation(shaderID, "angle"), angle);
	glUniform1f(glGetUniformLocation(shaderID, "u_time"), time * 2);
	glUseProgram(shaderID);
	glBindVertexArray(VAO);
	glDrawElementsInstanced(GL_TRIANGLES, 21, GL_UNSIGNED_INT, 0, 3600);
	grassSway(time);
}
