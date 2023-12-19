#pragma once

#include "imagelib/image_buffer.hpp"

#include <string>
#include <vector>

namespace imagelib
{
image_buffer
decode(std::vector<std::uint8_t> data);

image_buffer
load(const std::string& filename);
}  // namespace imagelib
