#pragma once

#include "imageutils/JPEG_Filter.hpp"

namespace imageutils
{
namespace filters
{
/**
 * @brief Flips a JPEG image horizontally.
 * @return A JPEG_Filter that horizontally flips the input image.
 *
 * This function creates a JPEG_Filter that flips a JPEG image horizontally.
 * It reverses the order of pixels along the horizontal axis (left to right).
 */
extern JPEG_Filter
flipH();
} // namespace filters
} // namespace imageutils
