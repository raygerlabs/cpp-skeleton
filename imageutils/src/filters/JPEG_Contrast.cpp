#include "imageutils/filters/JPEG_Contrast.hpp"

#include <cmath>

namespace imageutils
{
namespace filters
{
/**
 * @brief Adjusts the contrast of a JPEG image.
 * @param value The contrast adjustment factor.
 * @return A JPEG_Filter that modifies the contrast of the input image.
 *
 * This function creates a JPEG_Filter that adjusts the contrast of a JPEG image.
 * The value parameter specifies the adjustment factor, where 1.0 keeps the original contrast,
 * values greater than 1.0 increase the contrast, and values less than 1.0 decrease the contrast.
 */
JPEG_Filter
contrast(float value)
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
          output.setPixelColor(x, y, c,
                               std::max(0.0f, std::min(1.0f, (output.getPixelColor(x, y, c) - 0.5f) * value + 0.5f)));
        }
      }
    }
    return output;
  };
}
} // namespace filters
} // namespace imageutils
