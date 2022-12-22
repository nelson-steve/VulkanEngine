#pragma once

#include "VulkanDevice.h"

namespace VulkanEngine {

	struct PipelineConfigInfo 
	{
	};

	class Pipeline
	{
	public:
		Pipeline(
			VulkanDevice& device,
			const std::string& vertFilePath, 
			const std::string& fragFilePath, 
			const PipelineConfigInfo configInfo
		);
		~Pipeline() {}

		Pipeline(const Pipeline&) = delete;
		void operator=(const Pipeline&) = delete;

		static PipelineConfigInfo DefaultConfigInfo(uint32_t width, uint32_t height);
	private:
		static std::vector<char> readFile(const std::string& filePath);

		void CreateGraphicsPipeline(
			const std::string& vertFilePath, 
			const std::string& fragFilePath, 
			const PipelineConfigInfo configInfo
		);

		void CreateShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);

		VulkanDevice& m_Device;
		VkPipeline m_GraphicsPipeline;
		VkShaderModule m_VertexShaderModule;
		VkShaderModule m_FragmentShaderModule;
	};

}