#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "windowcontext.h"
#include "ShaderCodeParser.h"
#include "GrassTerrasse.h"
#include "Quad.h"
#include "Math.h"
#include "GUIEditor.h"
		
int main()
{		
	int	h = 900;
	int	w = 900;
		
	Window	win("Grass", w, h);
	ShaderParser	grassShader("shaders/grass_v.shader", "shaders/grass_f.shader");
	ShaderParser	noiseShader("shaders/noise_v.shader", "shaders/noise_f.shader");
	Quad			quad(Vector2<float>(13, 13), noiseShader.ShaderID());
	GrassTerrasse	grassterrasse(100, grassShader.ShaderID());

	float width = 0.04f, height = 0.08f;
	double ftime = glfwGetTime();
	int		frames = 0;

	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	ImGui_ImplOpenGL3_Init("#version 330");
	ImGui_ImplGlfw_InitForOpenGL(win.window, true);
	ImGui::StyleColorsDark();

	float timer = 3;
	int tmp = frames;
	// Render Loop	
	while (!glfwWindowShouldClose(win.window))
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		double time = glfwGetTime();
		frames++;
		if (timer > 0)
			timer -= 0.01;
		else if (timer <= 0)
			tmp = frames;
		if (time - ftime >= 1.0f)
		{
			frames = 0;
			ftime = time;
			timer = 3;
		}
		ImGui::Begin("FPS");
		ImGui::Text(std::string(std::to_string(tmp)).c_str());
		ImGui::End();

		double x, y;
		glfwGetCursorPos(win.window, &x, &y);

		static float t = 0;

		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		//quad.Render(time);
		grassterrasse.renderterrasse(static_cast<float>(time));
		
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		glfwGetCursorPos(win.window, &x, &y);
		glfwSwapBuffers(win.window);
		glfwPollEvents();
	}
}
