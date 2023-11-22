#ifndef IMAGEUTILS_FILTERS_JPEGINVERT_HPP
#define IMAGEUTILS_FILTERS_JPEGINVERT_HPP

#pragma once

#include "imageutils/JPEGImage.hpp"
#include "imageutils/JPEGFilter.hpp"

namespace imageutils
{
namespace filters
{
static inline JPEGFilter
invert()
{
  return [](const JPEGImage& input)
  {
    JPEGImage output(input);
    for (JPEGImage::SizeType y = 0; y < input.getHeight(); ++y)
    {
      for (JPEGImage::SizeType x = 0; x < input.getWidth(); ++x)
      {
        auto inputPixel = input.getPixel(x,y);
        output.getPixel(x, y).red = 255 - inputPixel.red;
        output.getPixel(x, y).green = 255 - inputPixel.green;
        output.getPixel(x, y).blue = 255 - inputPixel.blue;
      }
    }
    return output;
  };
}
} // namespace filters
} // namespace imageutils

#endif