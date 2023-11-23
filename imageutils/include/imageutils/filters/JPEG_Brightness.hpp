#ifndef IMAGEUTILS_FILTERS_JPEG_BRIGHTNESS_HPP
#define IMAGEUTILS_FILTERS_JPEG_BRIGHTNESS_HPP

#pragma once

#include "imageutils/internal/JPEG_Filter.hpp"

namespace imageutils
{
namespace filters
{
static inline JPEG_Filter
brightness(float value)
{
  return [value](const JPEG_Image& input)
  {
    JPEG_Image output(input);
    for (JPEG_Image::SizeType y = 0; y < output.getHeight(); ++y)
    {
      for (JPEG_Image::SizeType x = 0; x < output.getWidth(); ++x)
      {
        auto& pixel = output.getPixel(x, y);
        if (output.getFormat() == PixelFormat::GRAYSCALE)
        {
          pixel.value = std::min(255.0f, pixel.value * value);
        }
        else // RGB
        {
          pixel.red = std::min(255.0f, pixel.red * value);
          pixel.green = std::min(255.0f, pixel.green * value);
          pixel.blue = std::min(255.0f, pixel.blue * value);
        }
      }
    }
    return output;
  };
}
} // namespace filters
} // namespace imageutils

#endif // IMAGEUTILS_FILTERS_JPEG_BRIGHTNESS_HPP