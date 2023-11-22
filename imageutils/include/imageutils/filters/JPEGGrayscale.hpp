#ifndef IMAGEUTILS_FILTERS_JPEGGRAYSCALE_HPP
#define IMAGEUTILS_FILTERS_JPEGGRAYSCALE_HPP

#pragma once

#include "imageutils/JPEGImage.hpp"
#include "imageutils/JPEGFilter.hpp"

namespace imageutils
{
namespace filters
{
static inline JPEGFilter
grayscale()
{
  return [](const JPEGImage& input)
  {
    JPEGImage output(input);
    JPEGImage::SizeType pixelCount = input.getWidth() * input.getHeight();
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