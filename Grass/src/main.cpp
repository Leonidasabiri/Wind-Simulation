#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "windowcontext.h"
#include "ShaderCodeParser.h"
#include "GrassBlade.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

int main()
{
	Window	win("Grass", 600, 600);

	ShaderParser	grassShader("shaders/grass_v.shader", "shaders/grass_f.shader");
	GrassBlade		*grassblades[100];
	//GrassBlade		grassblade(grassShader.ShaderID(),0.3f, 0.0f, -0.7f);	

	for (size_t i = 0; i < 100; i++)
	{
		grassblades[i] = new GrassBlade(grassShader.ShaderID(), 0.3f, -1.2f + (i / 25.0f), -0.7);
	}

	float width = 0.04f, height = 0.08f;
	double ftime = glfwGetTime();
	int		frames = 0;
	// Render Loop
	while (!glfwWindowShouldClose(win.window))
	{
		double time = glfwGetTime();
		frames++;
		if (time - ftime >= 1.0f)
		{
			std::cout << frames << "fps\n";
			frames = 0;
			ftime = time;
		}
		double x, y;
		glfwGetCursorPos(win.window, &x, &y);
		glClearColor(0.1f, 0.01f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
				
		//glUniform1f(glGetUniformLocation(grassShader.ShaderID(), "offsety"), -0.9f);
		
		for (size_t i = 0; i < 100; i++)
		{
			grassblades[i] -> renderblade(grassShader.ShaderID(), sin(static_cast<float>(time)));
		}
		glfwSwapBuffers(win.window);
		glfwPollEvents();
	}
}