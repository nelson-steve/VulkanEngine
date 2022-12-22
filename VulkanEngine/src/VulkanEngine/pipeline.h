#pragma once

namespace VulkanEngine {

	class Pipeline
	{
	public:
		Pipeline(const std::string& vertFilePath, const std::string& fragFilePath);
	private:
		static std::vector<char> readFile(const std::string& filePath);

		void CreateGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath);
	};

}