#pragma once

#include <glad/glad.h>
#include <iostream>
#include <sstream>
#include <fstream>

class ShaderParser
{
public:
	unsigned int	frag_shader = 0, vert_shader = 0, shader_program = 0;
	const	char	*vs_source = nullptr;
	const	char	*fs_source = nullptr;

	ShaderParser(const char* vertex_shader_path, const char* frage_shader_path);

	unsigned int	ShaderID();
	//~ShaderParser();
};

