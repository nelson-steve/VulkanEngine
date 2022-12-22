#pragma once

#include <vulkan/vulkan.hpp>
#include <GLFW/glfw3.h>

namespace VulkanEngine {

	class Window 
	{
	public:
		Window(uint32_t width = 800, uint32_t height = 600, const std::string& windowName = "Vulkan");
		~Window();

		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;

		bool WindowShouldClose() { return glfwWindowShouldClose(m_Window); }
		void CreateWindowSurface(VkInstance instance, VkSurfaceKHR* surface);
		void CreateWindow();
	private:
		GLFWwindow* m_Window;

		std::string m_WindowName;
		const uint32_t m_Width;
		const uint32_t m_Height;

	};

}