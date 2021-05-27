#include "DfPch.h"
#include "TypedefsINeed.h"

#include "ImGui/ImGui.h"
#include "GLFW/GLFW.h"
#include "Tab/TabStack.h"

i32 main()
{
	// Setup GLFW and the tab stack
	GLFWwindow* osWindow = Deerfox::GLFWDF::Setup();
	Deerfox::TabStack tabStack;

	tabStack.PushTab(new Deerfox::Tab("New tab", ""));
	// TEMP: Testing tabs
	tabStack.PushTab(new Deerfox::Tab("Ah, hello, Gordon!", "https://www.google.com/"));
	tabStack.PushTab(new Deerfox::Tab("H E L L O G O R D O N", "https://www.youtube.com/"));

	//Init ImGui
	Deerfox::ImGuiDF::Setup(osWindow);

	while (true)
	{
		Deerfox::ImGuiDF::Begin();
		{
			// Render all tabs with ImGui
			for (auto& tab : tabStack)
				tab->ImGuiRender();
		}
		Deerfox::ImGuiDF::End();

		// Update GL and GLFW
		Deerfox::GLFWDF::Update(osWindow);
	}

	// Shut ImGui down
	Deerfox::ImGuiDF::Shutdown();

	return EXIT_SUCCESS;
}
