#include "imageutils/filters/resize.hpp"
#include "imageutils/image.hpp"
#include <cmath>

namespace imageutils
{
namespace filters
{
image
resize(const image& src, std::uint32_t width, std::uint32_t height)
{
  image dst(width, height, src.channels());
  image::pixel_color scaleX = static_cast<image::pixel_color>(src.width()) / static_cast<image::pixel_color>(width);
  image::pixel_color scaleY = static_cast<image::pixel_color>(src.height()) / static_cast<image::pixel_color>(height);

  for (image::size_type y = 0; y < height; ++y)
  {
    for (image::size_type x = 0; x < width; ++x)
    {
      image::pixel_color srcX = (static_cast<image::pixel_color>(x) + 0.5f) * scaleX - 0.5f;
      image::pixel_color srcY = (static_cast<image::pixel_color>(y) + 0.5f) * scaleY - 0.5f;

      image::size_type x0 = static_cast<image::size_type>(std::floor(srcX));
      image::size_type y0 = static_cast<image::size_type>(std::floor(srcY));
      image::size_type x1 = std::min(x0 + 1U, src.width() - 1U);
      image::size_type y1 = std::min(y0 + 1U, src.height() - 1U);

      image::pixel_color x_ratio = srcX - static_cast<image::pixel_color>(x0);
      image::pixel_color y_ratio = srcY - static_cast<image::pixel_color>(y0);
      image::pixel_color inv_x_ratio = 1 - x_ratio;
      image::pixel_color inv_y_ratio = 1 - y_ratio;

      for (image::size_type c = 0; c < src.channels(); ++c)
      {
        image::pixel_color top_left = src.color_at(x0, y0, c);
        image::pixel_color top_right = src.color_at(x1, y0, c);
        image::pixel_color bottom_left = src.color_at(x0, y1, c);
        image::pixel_color bottom_right = src.color_at(x1, y1, c);

        image::pixel_color top = top_left * inv_x_ratio + top_right * x_ratio;
        image::pixel_color bottom = bottom_left * inv_x_ratio + bottom_right * x_ratio;

        image::pixel_color final_color = top * inv_y_ratio + bottom * y_ratio;

        dst.set_color(final_color, x, y, c);
      }
    }
  }
  return dst;
}
}  // namespace filters
}  // namespace imageutils
