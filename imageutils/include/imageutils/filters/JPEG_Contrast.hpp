#pragma once

#include "imageutils/JPEG_Filter.hpp"

namespace imageutils
{
namespace filters
{
/**
 * @brief Adjusts the contrast of a JPEG image.
 * @param value The contrast adjustment factor.
 * @return A JPEG_Filter that modifies the contrast of the input image.
 *
 * This function creates a JPEG_Filter that adjusts the contrast of a JPEG image.
 * The value parameter specifies the adjustment factor, where 1.0 keeps the original contrast,
 * values greater than 1.0 increase the contrast, and values less than 1.0 decrease the contrast.
 */
extern JPEG_Filter
contrast(float value);
} // namespace filters
} // namespace imageutils
