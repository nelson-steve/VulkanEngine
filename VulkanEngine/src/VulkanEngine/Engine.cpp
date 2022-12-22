#include "VKPreCompiledHeader.h"

#include "Engine.h"
#include "instance.h"

using namespace VulkanEngine;

Engine::Engine()
{
	if (m_DebugMode);

	window = new Window();
	window->CreateWindow();

	
	Make_Instance();
}

Engine::~Engine()
{
	m_Instance.destroy();
	glfwTerminate();
	delete window;
}

void Engine::Make_Instance()
{
	m_Instance = vkInit::makeInstance(m_DebugMode, "Vulkan Application");
}

void Engine::CreateWindow()
{
	//glfwInit();
	//
	//glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	//glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	//
	//if (m_Window = glfwCreateWindow(m_Width, m_Height, "Vulkan Window", nullptr, nullptr))
	//{
	//	std::cout << "Successfully created a window"<<std::endl;
	//}
}