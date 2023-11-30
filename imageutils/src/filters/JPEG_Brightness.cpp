#include "imageutils/filters/JPEG_Brightness.hpp"
#include <cmath>

namespace imageutils
{
namespace filters
{
/**
 * @brief Adjusts the brightness of a JPEG image.
 * @param value The brightness adjustment factor.
 * @return A JPEG_Filter that modifies the brightness of the input image.
 *
 * This function creates a JPEG_Filter that adjusts the brightness of a JPEG image.
 * The value parameter specifies the adjustment factor, where 1.0 keeps the original brightness,
 * values greater than 1.0 increase the brightness, and values less than 1.0 decrease the brightness.
 */
JPEG_Filter
brightness(float value)
{
  return [value](const JPEG_Image& input)
  {
    JPEG_Image output(input);
    for (JPEG_Image::SizeType y = 0; y < output.height(); ++y)
    {
      for (JPEG_Image::SizeType x = 0; x < output.width(); ++x)
      {
        for (JPEG_Image::SizeType c = 0; c < output.channels(); ++c)
        {
          output.setPixelColor(x, y, c, std::min(1.0f, std::max(0.0f, output.getPixelColor(x, y, c) * value)));
        }
      }
    }
    return output;
  };
}
} // namespace filters
} // namespace imageutils
