#include "TypedefsINeed.h"

#include "ImGui/ImGui.h"
#include "GLFW/GLFW.h"

i32 main()
{
	GLFWwindow* OsWindow = Deerfox::GLFW::Setup();

	Deerfox::ImGuiDF::Setup(OsWindow);
	while (true)
	{
		Deerfox::ImGuiDF::Begin();
		{
			ImGui::Begin("Ah, hello, Gordon!");
			ImGui::Text("Another day, another dollar!");
			ImGui::End();

			ImGui::Begin("H E L L O G O R D O N");
			ImGui::Text("I have unleashed,\nthe power of\nall 300 clones!");
			ImGui::End();
		}
		Deerfox::ImGuiDF::End();

		Deerfox::GLFW::Update(OsWindow);
	}
	Deerfox::ImGuiDF::Shutdown();

	return EXIT_SUCCESS;
}
