#include "imageutils/filters/JPEG_Grayscale.hpp"
#include <cmath>

namespace imageutils
{
namespace filters
{
JPEG_Filter
grayscale()
{
  return [](const JPEG_Image& input)
  {
    if (input.channels() == 1)
    {
      return input;
    }

    JPEG_Image output(input.width(), input.height(), 1);
    for (JPEG_Image::SizeType y = 0; y < input.height(); ++y)
    {
      for (JPEG_Image::SizeType x = 0; x < input.width(); ++x)
      {
        const auto r = input.getPixelColor(x, y, 0);
        const auto g = input.getPixelColor(x, y, 1);
        const auto b = input.getPixelColor(x, y, 2);
        output.setPixelColor(x, y, 0, (r * 0.2126f + g * 0.7152f + b * 0.0722f));
      }
    }
    return output;
  };
}
} // namespace filters
} // namespace imageutils
