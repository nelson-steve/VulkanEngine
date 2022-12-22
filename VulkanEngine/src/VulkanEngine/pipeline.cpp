#include "VKPreCompiledHeader.h"

#include "pipeline.h"

namespace VulkanEngine {

    Pipeline::Pipeline(const std::string& vertFilePath, const std::string& fragFilePath)
    {
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

    void Pipeline::CreateGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath)
    {
        auto vertCode = readFile(vertFilePath);
        auto fragCode = readFile(fragFilePath);

        std::cout << "Vertex Shader code size: " << vertCode.size() << std::endl;
        std::cout << "Fragment Shader code size: " << fragCode.size() << std::endl;
    }
}