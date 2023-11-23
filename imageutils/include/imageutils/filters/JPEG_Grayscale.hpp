#ifndef IMAGEUTILS_FILTERS_JPEG_GRAYSCALE_HPP
#define IMAGEUTILS_FILTERS_JPEG_GRAYSCALE_HPP

#pragma once

#include "imageutils/internal/JPEG_Filter.hpp"

namespace imageutils
{
namespace filters
{
static inline JPEG_Filter
grayscale()
{
  return [](const JPEG_Image& input)
  {
    JPEG_Image output(input);
    JPEG_Image::SizeType pixelCount = output.getWidth() * output.getHeight();
    for (auto& pixelColor : output)
    {
      const auto luma = 0.299f * pixelColor.red + 0.587f * pixelColor.green + 0.114f * pixelColor.blue;
      pixelColor.red = luma;
      pixelColor.green = luma;
      pixelColor.blue = luma;
    }
    return output;
  };
}
} // namespace filters
} // namespace imageutils

#endif