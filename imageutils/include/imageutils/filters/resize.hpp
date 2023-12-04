#pragma once

#include <cstdint>

namespace imageutils
{
class image;
namespace filters
{
image
resize(const image& src, std::uint32_t width, std::uint32_t height);
}  // namespace filters
}  // namespace imageutils
