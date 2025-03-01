/* Copyright (c) 2022, NVIDIA CORPORATION. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 the "License";
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <fence_pool.h>
#include <vulkan/vulkan.hpp>

namespace vkb
{
namespace core
{
class HPPDevice;
}

/**
 * @brief facade class around vkb::FencePool, providing a vulkan.hpp-based interface
 *
 * See vkb::FencePool for documentation
 */
class HPPFencePool : private vkb::FencePool
{
  public:
	HPPFencePool(vkb::core::HPPDevice &device) :
	    vkb::FencePool(reinterpret_cast<vkb::Device &>(device))
	{}

	vk::Fence request_fence()
	{
		return static_cast<vk::Fence>(vkb::FencePool::request_fence());
	}
};

}        // namespace vkb
