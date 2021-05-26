#include "GLFW.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Deerfox
{
	GLFWwindow* GLFW::Setup()
	{
		glfwInit();
		GLFWwindow* wdw = glfwCreateWindow(1, 1, "", nullptr, nullptr);
		glfwHideWindow(wdw);
		glfwMakeContextCurrent(wdw);
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		glfwSwapInterval(1);

		return wdw;
	}

	void GLFW::Update(GLFWwindow* wdw)
	{
		glfwSwapBuffers(wdw);
		glfwPollEvents();
	}
}
