#include "imageutils/filters/JPEG_Resize.hpp"
#include <cmath>

namespace imageutils
{
namespace filters
{
JPEG_Filter
resize(std::size_t width, std::size_t height)
{
  return [width, height](const JPEG_Image& input)
  {
    JPEG_Image output(width, height, input.channels());
    JPEG_Image::PixelColor scaleX = static_cast<JPEG_Image::PixelColor>(input.width()) / static_cast<JPEG_Image::PixelColor>(width);
    JPEG_Image::PixelColor scaleY = static_cast<JPEG_Image::PixelColor>(input.height()) / static_cast<JPEG_Image::PixelColor>(height);

    for (JPEG_Image::SizeType y = 0; y < height; ++y)
    {
      for (JPEG_Image::SizeType x = 0; x < width; ++x)
      {
        JPEG_Image::PixelColor srcX = (static_cast<JPEG_Image::PixelColor>(x) + 0.5f) * scaleX - 0.5f;
        JPEG_Image::PixelColor srcY = (static_cast<JPEG_Image::PixelColor>(y) + 0.5f) * scaleY - 0.5f;

        JPEG_Image::SizeType x0 = static_cast<JPEG_Image::SizeType>(std::floor(srcX));
        JPEG_Image::SizeType y0 = static_cast<JPEG_Image::SizeType>(std::floor(srcY));
        JPEG_Image::SizeType x1 = std::min(x0 + 1U, input.width() - 1U);
        JPEG_Image::SizeType y1 = std::min(y0 + 1U, input.height() - 1U);

        JPEG_Image::PixelColor x_ratio = srcX - static_cast<JPEG_Image::PixelColor>(x0);
        JPEG_Image::PixelColor y_ratio = srcY - static_cast<JPEG_Image::PixelColor>(y0);
        JPEG_Image::PixelColor inv_x_ratio = 1 - x_ratio;
        JPEG_Image::PixelColor inv_y_ratio = 1 - y_ratio;

        for (std::size_t c = 0; c < input.channels(); ++c)
        {
          JPEG_Image::PixelColor top_left = input.getPixelColor(x0, y0, c);
          JPEG_Image::PixelColor top_right = input.getPixelColor(x1, y0, c);
          JPEG_Image::PixelColor bottom_left = input.getPixelColor(x0, y1, c);
          JPEG_Image::PixelColor bottom_right = input.getPixelColor(x1, y1, c);

          JPEG_Image::PixelColor top = top_left * inv_x_ratio + top_right * x_ratio;
          JPEG_Image::PixelColor bottom = bottom_left * inv_x_ratio + bottom_right * x_ratio;

          JPEG_Image::PixelColor pixel = top * inv_y_ratio + bottom * y_ratio;

          output.setPixelColor(x, y, c, pixel);
        }
      }
    }
    return output;
  };
}
} // namespace filters
} // namespace imageutils
