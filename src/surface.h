//
// Created by rmyho on 5/19/2020.
//

#ifndef PICOFRAMEWORK_SURFACE_H
#define PICOFRAMEWORK_SURFACE_H

#include <cstdint>
#include <vulkan/vulkan.h>
#include <vector>

#include "window/abs_window_manager.h"

struct SwapchainConfigurations
{
	VkPresentModeKHR presentMode;
	VkSurfaceFormatKHR surfaceFormat;
	VkExtent2D extent;
	VkSurfaceCapabilitiesKHR surfaceCapabilities;
};

class Surface
{
public:
	struct Properties
	{
		VkFormat format;
	};

	explicit Surface(const Surface::Properties& properties, VkInstance instance, AbsWindowManager* windowManagerPtr);

	void destroy();

	SwapchainConfigurations getSwapchainConfigurations(VkPhysicalDevice physicalDevice) const;

	VkSurfaceKHR getHandle() const;

private:
	VkSurfaceFormatKHR chooseSurfaceFormat(const std::vector<VkSurfaceFormatKHR> &surfaceFormats) const;

	static VkPresentModeKHR choosePresentMode(const std::vector<VkPresentModeKHR> &presentModes);

	static VkExtent2D chooseExtent(const VkSurfaceCapabilitiesKHR &swapChainCapabilities, VkExtent2D windowExtent);


private:
	VkSurfaceKHR handle_;

	VkInstance instance_;
	AbsWindowManager* windowManagerPtr_;

	VkFormat format_;
};


#endif //PICOFRAMEWORK_SURFACE_H