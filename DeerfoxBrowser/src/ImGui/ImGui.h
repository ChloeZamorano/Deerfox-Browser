#pragma once

#include <imgui.h>
// TEMP
#include <examples/imgui_impl_glfw.h>
#include <examples/imgui_impl_opengl3.h>

namespace Deerfox
{
	class ImGuiDF
	{
	public:
		static void Setup(GLFWwindow* wdw);
		static void Shutdown();

		static void Begin();
		static void End();
	};
}
