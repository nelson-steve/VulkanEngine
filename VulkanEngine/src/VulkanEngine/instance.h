#pragma once

#include "config.h"
#include <iostream>

#define VK_KHR_portability_enumeration 1;
#define VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR 1;
namespace vkInit {

	vk::Instance makeInstance(bool debug, const char* applicationName)
	{
		uint32_t version = 0;
		vkEnumerateInstanceVersion(&version);
		if (debug)
		{
			std::cout << "Variant: " << VK_API_VERSION_VARIANT(version)
				<< "Major: " << VK_API_VERSION_MAJOR(version)
				<< "Minor: " << VK_API_VERSION_MINOR(version)
				<< "Patch: " << VK_API_VERSION_PATCH(version);
		}

		version &= ~(0xFFFU);

		version = VK_MAKE_API_VERSION(0, 1, 0, 0);

		vk::ApplicationInfo appInfo = vk::ApplicationInfo(
			applicationName,
			version,
			"Vulkan Application",
			version,
			version
		);

		uint32_t glfwExtensionCount = 0;
		const char** glfwExtensions;
		glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

		std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

		if (debug)
		{
			std::cout << "Extensions to be requestes: "<< glfwExtensionCount << std::endl;

			for (const char* extensionName : extensions)
			{
				std::cout << "\t" << extensionName << std::endl;
			}
		}
		//extensions.push_back(VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME);
		//extensions.push_back(VK_KHR_PORTABILITY_SUBSET_EXTENSION_NAME);
		//extensions.push_back(VK_KHR_portability_enumeration);
		//extensions.push_back(VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR);
		//extensions.push_back(VK_KHR_portability_subset);


		vk::InstanceCreateInfo createInfo = vk::InstanceCreateInfo(
			vk::InstanceCreateFlags(),
			&appInfo,
			0,
			nullptr,
			static_cast<uint32_t>(extensions.size()),
			extensions.data()
		);
		//createInfo.flags = VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;
		//
		//createInfo.enabledExtensionCount = static_cast<uint32_t>(extNames.size());
		//
		//createInfo.ppEnabledExtensionNames = extensions.data();

		//std::vector<const char*>
		//
		//	extNames.push_back(VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME);
		//
		//extNames.push_back(VK_KHR_PORTABILITY_SUBSET_EXTENSION_NAME);
		//
		//
		//VKInstanceCreateInfo inst_info = {};
		//
		//ins_info.flags = VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;
		//
		//inst_info.enabledExtensionCount = static_cast<uint32_t>(extNames.size());
		//
		//inst_info.ppEnabledExtensionNames = extNames.data();

		try
		{
			return vk::createInstance(createInfo);
		}
		catch (vk::SystemError err)
		{
			if (debug)
			{
				std::cout << err.what() << std::endl;
				std::cout << "Failed to create instance" << std::endl;
			}
			return nullptr;
		}
	}

}