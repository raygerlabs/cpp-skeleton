#pragma once

#include "imageutils/JPEG_Filter.hpp"

namespace imageutils
{
namespace filters
{
/**
 * @brief Flips a JPEG image vertically.
 * @return A JPEG_Filter that vertically flips the input image.
 *
 * This function creates a JPEG_Filter that flips a JPEG image vertically.
 * It reverses the order of pixels along the vertical axis (top to bottom).
 */
extern JPEG_Filter
flipV();
} // namespace filters
} // namespace imageutils
