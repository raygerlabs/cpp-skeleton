#ifndef IMAGEUTILS_FILTERS_JPEGRESIZE_HPP
#define IMAGEUTILS_FILTERS_JPEGRESIZE_HPP

#pragma once

#include "imageutils/JPEGImage.hpp"
#include "imageutils/JPEGFilter.hpp"

namespace imageutils
{
namespace filters
{
static inline JPEGFilter
resize(size_t width, size_t height)
{
  return [width, height](const JPEGImage& input)
  {
    JPEGImage output(width, height, input.getFormat());
    float scaleX = static_cast<float>(input.getWidth()) / width;
    float scaleY = static_cast<float>(input.getHeight()) / height;
    for (JPEGImage::SizeType y = 0; y < height; ++y)
    {
      for (JPEGImage::SizeType x = 0; x < width; ++x)
      {
        size_t srcX = static_cast<size_t>(x * scaleX);
        size_t srcY = static_cast<size_t>(y * scaleY);
        output.getPixel(x, y) = input.getPixel(srcX, srcY);
      }
    }
    return output;
  };
}
} // namespace filters
} // namespace imageutils

#endif