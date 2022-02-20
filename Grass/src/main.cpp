#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "windowcontext.h"
#include "ShaderCodeParser.h"
#include "GrassTerrasse.h"
#include "GUIEditor.h"
#include "Quad.h"
#include "Math.h"

int main()
{
	int	h = 900;
	int	w = 900;

	Window	win("Grass", w, h);
	ShaderParser	grassShader("shaders/grass_v.shader", "shaders/grass_f.shader");
	ShaderParser	noiseShader("shaders/noise_v.shader", "shaders/noise_f.shader");
	Quad			quad(Vector2<float>(3, 3));
	GrassTerrasse	grassterrasse(100, grassShader.ShaderID());
	
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
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		quad.Render(noiseShader.ShaderID(), Vector2<float>(3, 3), 20);
		//grassterrasse.renderterrasse(static_cast<float>(time));
		glfwSwapBuffers(win.window);
		glfwPollEvents();
	}
}
