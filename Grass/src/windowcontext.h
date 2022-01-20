#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Window
{
public:
	GLFWwindow* window;
	int	_w, _h;
	Window(const char *title, int width , int height)
	{
		_w = width;
		_h = height;
		glfwInit();
		window = glfwCreateWindow(_w, _h, title, NULL, NULL);
		glfwMakeContextCurrent(window);
		int	gladload = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		if (!gladload)
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			return ;
		}
	}
	~Window()
	{
		glfwTerminate();
		glfwDestroyWindow(window);
	}
};
