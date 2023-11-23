#ifndef IMAGEUTILS_FILTERS_JPEG_INVERT_HPP
#define IMAGEUTILS_FILTERS_JPEG_INVERT_HPP

#pragma once

#include "imageutils/internal/JPEG_Filter.hpp"

namespace imageutils
{
namespace filters
{
static inline JPEG_Filter
invert()
{
  return [](const JPEG_Image& input)
  {
    JPEG_Image output(input);
    for (JPEG_Image::SizeType y = 0; y < output.getHeight(); ++y)
    {
      for (JPEG_Image::SizeType x = 0; x < output.getWidth(); ++x)
      {
        auto& pixel = output.getPixel(x, y);
        output.getPixel(x, y).red = 255 - pixel.red;
        output.getPixel(x, y).green = 255 - pixel.green;
        output.getPixel(x, y).blue = 255 - pixel.blue;
      }
    }
    return output;
  };
}
} // namespace filters
} // namespace imageutils

#endif // IMAGEUTILS_FILTERS_JPEG_INVERT_HPP