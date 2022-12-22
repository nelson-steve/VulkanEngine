#include "VKPreCompiledHeader.h"

#include "Window.h"

namespace VulkanEngine {

	Window::Window(uint32_t width, uint32_t height, const std::string& windowName)
		:m_Width(width),m_Height(height),m_WindowName(windowName) {
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		m_Window = glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);

		uint32_t extensionCount = 0;
		vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

		std::cout << extensionCount << " extensions supported\n";
	}

	Window::~Window()
	{
		glfwDestroyWindow(m_Window);
	}

	void Window::CreateWindow()
	{
		while (!glfwWindowShouldClose(m_Window)) {
			glfwPollEvents();
		}
	}

}