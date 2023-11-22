#ifndef IMAGEUTILS_FILTERS_JPEGCONTRAST_HPP
#define IMAGEUTILS_FILTERS_JPEGCONTRAST_HPP

#pragma once

#include "imageutils/JPEGImage.hpp"
#include "imageutils/JPEGFilter.hpp"

#include <algorithm>

namespace imageutils
{
namespace filters
{
static inline JPEGFilter
contrast(float value)
{
  return [value](const JPEGImage& input)
  {
    JPEGImage output(input);
    float factor = (259.0f * (value + 255.0f)) / (255.0f * (259.0f - value));

    for (JPEGImage::SizeType y = 0; y < output.getHeight(); ++y)
    {
      for (JPEGImage::SizeType x = 0; x < output.getWidth(); ++x)
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

#endif