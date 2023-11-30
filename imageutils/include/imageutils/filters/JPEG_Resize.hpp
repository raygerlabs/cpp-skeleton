#pragma once

#include "imageutils/JPEG_Filter.hpp"

namespace imageutils
{
namespace filters
{
/**
 * @brief Resizes a JPEG image to a specified width and height.
 * @param width The target width for the resized image.
 * @param height The target height for the resized image.
 * @return A JPEG_Filter that resizes the input image.
 *
 * This function creates a JPEG_Filter that resizes a JPEG image to the specified dimensions.
 * It uses simple nearest-neighbor interpolation to scale the image.
 */
extern JPEG_Filter
resize(std::size_t width, std::size_t height);
} // namespace filters
} // namespace imageutils
