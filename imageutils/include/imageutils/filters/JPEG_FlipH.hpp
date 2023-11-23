#ifndef IMAGEUTILS_FILTERS_JPEG_FLIPH_HPP
#define IMAGEUTILS_FILTERS_JPEG_FLIPH_HPP

#pragma once

#include "imageutils/internal/JPEG_Filter.hpp"

namespace imageutils
{
namespace filters
{
static inline JPEG_Filter
flipH()
{
  return [](const JPEG_Image& input)
  {
    JPEG_Image output(input);
    for (JPEG_Image::SizeType y = 0; y < output.getHeight(); ++y)
    {
      for (JPEG_Image::SizeType x = 0; x < output.getWidth(); ++x)
      {
        output.getPixel(input.getWidth() - x - 1, y) = input.getPixel(x, y);
      }
    }
    return output;
  };
}
} // namespace filters
} // namespace imageutils

#endif // IMAGEUTILS_FILTERS_JPEG_FLIPH_HPP