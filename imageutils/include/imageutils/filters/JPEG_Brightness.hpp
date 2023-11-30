#pragma once

#include "imageutils/JPEG_Filter.hpp"

namespace imageutils
{
namespace filters
{
/**
 * @brief Adjusts the brightness of a JPEG image.
 * @param value The brightness adjustment factor.
 * @return A JPEG_Filter that modifies the brightness of the input image.
 *
 * This function creates a JPEG_Filter that adjusts the brightness of a JPEG image.
 * The value parameter specifies the adjustment factor, where 1.0 keeps the original brightness,
 * values greater than 1.0 increase the brightness, and values less than 1.0 decrease the brightness.
 */
extern JPEG_Filter
brightness(float value);
} // namespace filters
} // namespace imageutils
