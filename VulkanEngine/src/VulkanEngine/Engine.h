#pragma once

#include "Window.h"
#include "pipeline.h"
#include "VulkanDevice.h"

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

	VulkanEngine::Window* window;///////////////////////////////////// Created window
	VulkanEngine::VulkanDevice device{*window};////////////////////////////////////// Created device
	VulkanEngine::Pipeline pipeline{
		device,
		"Shaders/Shader.vert",
		"Shaders/Shader.frag",
		VulkanEngine::Pipeline::DefaultConfigInfo(m_Width, m_Height)
	};////////////////// Created pipeline
};