#pragma once

struct GLFWwindow;

namespace Deerfox
{
	class GLFW
	{
	public:
		static GLFWwindow* Setup();
		static void Update(GLFWwindow* wdw);
	};
}
