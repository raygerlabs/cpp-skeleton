#ifndef IMAGEUTILS_FILTERS_JPEGFLIPH_HPP
#define IMAGEUTILS_FILTERS_JPEGFLIPH_HPP

#pragma once

#include "imageutils/JPEGImage.hpp"
#include "imageutils/JPEGFilter.hpp"

namespace imageutils
{
namespace filters
{
static inline JPEGFilter
flipH()
{
  return [](const JPEGImage& input)
  {
    JPEGImage output(input);
    for (JPEGImage::SizeType y = 0; y < input.getHeight(); ++y)
    {
      for (JPEGImage::SizeType x = 0; x < input.getWidth(); ++x)
      {
        output.getPixel(input.getWidth() - x - 1, y) = input.getPixel(x, y);
      }
    }
    return output;
  };
}
} // namespace filters
} // namespace imageutils

#endif