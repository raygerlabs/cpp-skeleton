#pragma once

#include "imageutils/JPEG_Image.hpp"

#include <functional>

namespace imageutils
{
/**
 * @brief Alias for a JPEG filter function
 * A function that takes a JPEG_Image as input and returns a modified JPEG_Image.
 */
using JPEG_Filter = std::function<JPEG_Image(const JPEG_Image&)>;
} // namespace imageutils
