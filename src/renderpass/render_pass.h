//
// Created by ross on 2020-09-27.
//

#ifndef PICOFRAMEWORK_RENDER_PASS_H
#define PICOFRAMEWORK_RENDER_PASS_H

#include <vector>
#include "pfvk.h"

class RenderPass
{
public:
	explicit RenderPass(VkRenderPass handle);

	void destroy(VkDevice device);

	std::vector<VkFramebuffer> createFramebuffers(VkDevice deviceHandle, std::vector<std::vector<VkImageView>> &attachmentsList, VkExtent2D extent);

public:
	VkRenderPass handle_;
};


#endif //PICOFRAMEWORK_RENDER_PASS_H
