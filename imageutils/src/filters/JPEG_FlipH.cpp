#include "imageutils/filters/JPEG_FlipH.hpp"

namespace imageutils
{
namespace filters
{
JPEG_Filter
flipH()
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
          auto pixelColor = input.getPixelColor(input.width() - x - 1, y, c);
          output.setPixelColor(x, y, c, pixelColor);
        }
      }
    }
    return output;
  };
}
} // namespace filters
} // namespace imageutils
