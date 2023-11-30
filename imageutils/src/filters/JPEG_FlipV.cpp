#include "imageutils/filters/JPEG_FlipV.hpp"

namespace imageutils
{
namespace filters
{
JPEG_Filter
flipV()
{
  return [](const JPEG_Image& input)
  {
    JPEG_Image output(input);
    for (JPEG_Image::SizeType y = 0; y < input.height(); ++y)
    {
      for (JPEG_Image::SizeType x = 0; x < input.width(); ++x)
      {
        for (JPEG_Image::SizeType c = 0; c < input.channels(); ++c)
        {
          auto pixelColor = input.getPixelColor(x, input.height() - y - 1, c);
          output.setPixelColor(x, y, c, pixelColor);
        }
      }
    }
    return output;
  };
}
} // namespace filters
} // namespace imageutils
