#include "ShaderCodeParser.h"

ShaderParser::ShaderParser(const char* vertex_shader_path, const char* frage_shader_path)
{
	std::string vs_shader_line;
	std::stringstream vs_str;
	std::ifstream shaderfile;
	shaderfile.open(vertex_shader_path);

	if (!shaderfile)
	{
		std::cerr << "Path invalid !\n";
		return;
	}

	while (std::getline(shaderfile, vs_shader_line))
		vs_str << vs_shader_line << '\n';
	std::string vs = vs_str.str();
	vs_source = vs.c_str();
	shaderfile.close();

	std::string			fs_shader_line;
	std::stringstream	fs_str;

	shaderfile.open(frage_shader_path);

	if (!shaderfile)
	{
		std::cerr << "Path invalid !\n";
		return;
	}

	while (std::getline(shaderfile, fs_shader_line))
		fs_str << fs_shader_line << '\n';
	std::string fs = fs_str.str();
	fs_source = fs.c_str();
	shaderfile.close();

	vert_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vert_shader, 1, &vs_source, NULL);
	glCompileShader(vert_shader);

	int	success;
	char info[512];

	std::cout << vs_source;
	std::cout << fs_source;

	glGetShaderiv(vert_shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vert_shader, 512, NULL, info);
		std::cerr << "Error: " << info;
	}

	frag_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(frag_shader, 1, &fs_source, NULL);
	glCompileShader(frag_shader);

	glGetShaderiv(frag_shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(frag_shader, 512, NULL, info);
		std::cerr << "Error: " << info;
	}

	shader_program = glCreateProgram();
	glAttachShader(shader_program, vert_shader);
	glAttachShader(shader_program, frag_shader);
	glLinkProgram(shader_program);

	glDeleteShader(vert_shader);
	glDeleteShader(frag_shader);
}

unsigned int ShaderParser::ShaderID()
{
	return shader_program;
}