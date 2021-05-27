#pragma once

struct GLFWwindow;

namespace Deerfox
{
	class GLFWDF
	{
	public:
		static GLFWwindow* Setup();
		static void Update(GLFWwindow* wdw);
	};
}
