#ifndef IMAGEUTILS_FILTERS_JPEG_RESIZE_HPP
#define IMAGEUTILS_FILTERS_JPEG_RESIZE_HPP

#pragma once

#include "imageutils/internal/JPEG_Filter.hpp"

namespace imageutils
{
namespace filters
{
static inline JPEG_Filter
resize(size_t width, size_t height)
{
  return [width, height](const JPEG_Image& input)
  {
    JPEG_Image output(width, height, input.getFormat());
    float scaleX = static_cast<float>(input.getWidth()) / width;
    float scaleY = static_cast<float>(input.getHeight()) / height;
    for (JPEG_Image::SizeType y = 0; y < height; ++y)
    {
      for (JPEG_Image::SizeType x = 0; x < width; ++x)
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

#endif // IMAGEUTILS_FILTERS_JPEG_RESIZE_HPP