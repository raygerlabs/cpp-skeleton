#pragma once

#include "imageutils/JPEG_Filter.hpp"

namespace imageutils
{
namespace filters
{
/**
 * @brief Converts a JPEG image to grayscale.
 * @return A JPEG_Filter that converts the input image to grayscale.
 *
 * This function creates a JPEG_Filter that converts a JPEG image to grayscale.
 * It uses the luminance formula (Y = 0.2126*R + 0.7152*G + 0.0722*B) to calculate grayscale values.
 */
extern JPEG_Filter
grayscale();
} // namespace filters
} // namespace imageutils
