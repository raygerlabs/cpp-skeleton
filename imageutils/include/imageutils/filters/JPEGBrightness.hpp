#ifndef IMAGEUTILS_FILTERS_JPEGBRIGHTNESS_HPP
#define IMAGEUTILS_FILTERS_JPEGBRIGHTNESS_HPP

#pragma once

#include "imageutils/JPEGImage.hpp"
#include "imageutils/JPEGFilter.hpp"

namespace imageutils
{
namespace filters
{
static inline JPEGFilter
brightness(float value)
{
  return [value](const JPEGImage& input)
  {
    JPEGImage output(input);
    for (JPEGImage::SizeType y = 0; y < output.getHeight(); ++y)
    {
      for (JPEGImage::SizeType x = 0; x < output.getWidth(); ++x)
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

#endif