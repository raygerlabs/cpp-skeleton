#include "imageutils/filters/grayscale.hpp"
#include "imageutils/image.hpp"
#include <cmath>

namespace imageutils
{
namespace filters
{
image
grayscale(const image& src)
{
  if (src.channels() == 1)
  {
    return src;
  }

  image dst(src.width(), src.height(), 1);
  for (image::size_type y = 0; y < src.height(); ++y)
  {
    for (image::size_type x = 0; x < src.width(); ++x)
    {
      auto r = src.color_at(x, y, 0);
      auto g = src.color_at(x, y, 1);
      auto b = src.color_at(x, y, 2);
      dst.set_color((r * 0.2126f + g * 0.7152f + b * 0.0722f), x, y, 0);
    }
  }
  return dst;
}
}  // namespace filters
}  // namespace imageutils
