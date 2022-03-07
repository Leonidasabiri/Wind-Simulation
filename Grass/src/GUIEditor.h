#pragma once
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "windowcontext.h"

//class GUIEditor
//{
//public:
//	//GUIEditor(Window wind);
//	void	createGUIContext();
//	void	createNewGuiWindow(const char* name);
//	void	Render();
//	~GUIEditor();
//private:
//
//};
//
////GUIEditor::GUIEditor(Window wind)
////{
////	ImGui::CreateContext();
////	ImGuiIO& io = ImGui::GetIO();
////	ImGui_ImplOpenGL3_Init("#version 330");
////	ImGui_ImplGlfw_InitForOpenGL(wind.window, true);
////	ImGui::StyleColorsDark();
//}
//
//GUIEditor::~GUIEditor()
//{
//	ImGui::DestroyContext();
//}
//
//void	GUIEditor::createGUIContext()
//{
//	ImGui_ImplOpenGL3_NewFrame();
//	ImGui_ImplGlfw_NewFrame();
//	ImGui::NewFrame();
//}
//
//void	GUIEditor::createNewGuiWindow(const char* name)
//{
//	ImGui::Begin(name);
//	ImGui::End();
//}
//
//void	GUIEditor::Render()
//{
//	ImGui::Render();
//	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
//}
