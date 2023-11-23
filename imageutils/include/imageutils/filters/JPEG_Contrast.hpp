#ifndef IMAGEUTILS_FILTERS_JPEG_CONTRAST_HPP
#define IMAGEUTILS_FILTERS_JPEG_CONTRAST_HPP

#pragma once

#include "imageutils/internal/JPEG_Filter.hpp"

#include <algorithm>

namespace imageutils
{
namespace filters
{
static inline JPEG_Filter
contrast(float value)
{
  return [value](const JPEG_Image& input)
  {
    JPEG_Image output(input);
    float factor = (259.0f * (value + 255.0f)) / (255.0f * (259.0f - value));

    for (JPEG_Image::SizeType y = 0; y < output.getHeight(); ++y)
    {
      for (JPEG_Image::SizeType x = 0; x < output.getWidth(); ++x)
      {
        auto& pixel = output.getPixel(x, y);
        if (output.getFormat() == PixelFormat::GRAYSCALE)
        {
          pixel.value = std::clamp(factor * (pixel.value - 128.0f) + 128.0f, 0.0f, 255.0f);
        }
        else // RGB
        {
          pixel.red = std::clamp(factor * (pixel.red - 128.0f) + 128.0f, 0.0f, 255.0f);
          pixel.green = std::clamp(factor * (pixel.green - 128.0f) + 128.0f, 0.0f, 255.0f);
          pixel.blue = std::clamp(factor * (pixel.blue - 128.0f) + 128.0f, 0.0f, 255.0f);
        }
      }
    }
    return output;
  };
}
} // namespace filters
} // namespace imageutils

#endif // IMAGEUTILS_FILTERS_JPEG_CONTRAST_HPP