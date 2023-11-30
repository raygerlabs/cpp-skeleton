#include "imageutils/filters/JPEG_Resize.hpp"

namespace imageutils
{
namespace filters
{
JPEG_Filter
invert()
{
  return [](const JPEG_Image& input)
  {
    JPEG_Image output(input);
    for (JPEG_Image::SizeType y = 0; y < output.height(); ++y)
    {
      for (JPEG_Image::SizeType x = 0; x < output.width(); ++x)
      {
        for (JPEG_Image::SizeType c = 0; c < output.channels(); ++c)
        {
          output.setPixelColor(x, y, c, 1.0f - output.getPixelColor(x, y, c));
        }
      }
    }
    return output;
  };
}
} // namespace filters
} // namespace imageutils
