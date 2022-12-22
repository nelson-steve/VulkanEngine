#include "VKPreCompiledHeader.h"

#include "pipeline.h"

namespace VulkanEngine {

    Pipeline::Pipeline(
        VulkanDevice& device,
        const std::string& vertFilePath,
        const std::string& fragFilePath,
        const PipelineConfigInfo configInfo
    ):m_Device(device) {
        CreateGraphicsPipeline(vertFilePath, fragFilePath, configInfo);
    }

    std::vector<char> Pipeline::readFile(const std::string& filePath)
    {
        
        std::ifstream file(filePath, std::ios::ate, std::ios::binary);
        if (!file.is_open())
        {
            throw std::runtime_error("Failed to open file." + filePath);
        }

        size_t fileSize = static_cast<size_t>(file.tellg());
        std::vector<char> buffer(fileSize);

        file.seekg(0);
        file.read(buffer.data(), fileSize);

        file.close();
        return buffer;
    }

    void Pipeline::CreateGraphicsPipeline(
        const std::string& vertFilePath, 
        const std::string& fragFilePath, 
        const PipelineConfigInfo configInfo
    ) {
        auto vertCode = readFile(vertFilePath);
        auto fragCode = readFile(fragFilePath);

        std::cout << "Vertex Shader code size: " << vertCode.size() << std::endl;
        std::cout << "Fragment Shader code size: " << fragCode.size() << std::endl;
    }

    void Pipeline::CreateShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule)
    {
        VkShaderModuleCreateInfo createInfo;
        createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
        createInfo.codeSize = code.size();
        createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

        if (vkCreateShaderModule(m_Device.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS)
        {
            throw std::runtime_error("Failed to create shader module");
        }
    }

    PipelineConfigInfo Pipeline::DefaultConfigInfo(uint32_t width, uint32_t height)
    {
        PipelineConfigInfo configInfo;

        return configInfo;
    }
}