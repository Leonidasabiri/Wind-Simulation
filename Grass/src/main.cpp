#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "windowcontext.h"
#include "ShaderCodeParser.h"
#include "GrassTerrasse.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "Quad.h"
#include "Math.h"

int main()
{
	int	h = 900;
	int	w = 900;

	Window	win("Grass", w, h);
	ShaderParser	grassShader("shaders/grass_v.shader", "shaders/grass_f.shader");
	ShaderParser	noiseShader("shaders/noise_v.shader", "shaders/noise_f.shader");
	Vector2<float>	vec(0.1, 0.1);
	Quad			quad(vec);
	GrassTerrasse	grassterrasse(2000, grassShader.ShaderID());

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

		grassterrasse.renderterrasse(static_cast<float>(time));
		//quad.Render(noiseShader.ShaderID(), vec, time);
		//glUniform1f(glGetUniformLocation(grassShader.ShaderID(), "offsety"), -0.9f);
		//quad.Render(noiseShader.ShaderID(), {static_cast<float>(h),static_cast<float>(w)}, time);
		glfwSwapBuffers(win.window);
		glfwPollEvents();
	}
}
