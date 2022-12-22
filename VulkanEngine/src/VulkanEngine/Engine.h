#pragma once

#include "Window.h"
#include "pipeline.h"

class Engine
{
public:
	Engine();
	~Engine();
private:
	bool m_DebugMode = true;

	uint32_t m_Width = 640;
	uint32_t m_Height = 480;
	std::string m_WindowName;

	vk::Instance m_Instance = nullptr;

	void CreateWindow();
	void Make_Instance();

	VulkanEngine::Window* window;
	VulkanEngine::Pipeline pipeline{ "Shaders/Shader.vert", "Shaders/Shader.frag" };
};