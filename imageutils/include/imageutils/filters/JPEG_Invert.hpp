#pragma once

#include "imageutils/JPEG_Filter.hpp"

namespace imageutils
{
namespace filters
{
/**
 * @brief Inverts a JPEG image.
 * @return A JPEG_Filter that inverts the input image.
 *
 * This function creates a JPEG_Filter that inverts a JPEG image.
 * It produces an image where each pixel's color value is inverted (1.0 - pixelColor).
 */
extern JPEG_Filter
invert();
} // namespace filters
} // namespace imageutils
