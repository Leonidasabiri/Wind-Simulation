#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "windowcontext.h"
#include "ShaderCodeParser.h"
#include "GrassBlade.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "Quad.h"

int main()
{
	int	h = 900;
	int	w = 900;

	Window	win("Grass", w, h);

	ShaderParser	grassShader("shaders/grass_v.shader", "shaders/grass_f.shader");
	ShaderParser	noiseShader("shaders/noise_v.shader", "shaders/noise_f.shader");
	GrassBlade		*grassblades[700][700];
	Quad			quad(w, h);

	for (size_t i = 0; i < 200; i++)
		for (size_t j = 0; j < 20; j++)
			grassblades[i][j] = new GrassBlade(grassShader.ShaderID(), 0.1f, -1.2f + (j / 100.0f), -0.7 + ( i / 10.0f));

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
			std::cout << frames << " fps\n";
			frames = 0;
			ftime = time;
		}
		double x, y;
		glfwGetCursorPos(win.window, &x, &y);
		glClearColor(0.1f, 0.01f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//quad.Render(noiseShader.ShaderID(), {static_cast<float>(h), static_cast<float>(w)}, time);
		//glUniform1f(glGetUniformLocation(grassShader.ShaderID(), "offsety"), -0.9f);		
		for (size_t i = 0; i < 200; i++)
			for (size_t j = 0; j < 20; j++)
				grassblades[i][j]->renderblade(grassShader.ShaderID(), sin(static_cast<float>(time)));
		//quad.Render(noiseShader.ShaderID(), {static_cast<float>(h),static_cast<float>(w)}, time);
		glfwSwapBuffers(win.window);
		glfwPollEvents();
	}
}
