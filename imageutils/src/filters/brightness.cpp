#include "imageutils/filters/brightness.hpp"
#include "imageutils/image.hpp"

#include <algorithm>

namespace imageutils
{
namespace filters
{
image
brightness(const image& src, float value)
{
  image dst(src);
  for (image::size_type y = 0; y < src.height(); ++y)
  {
    for (image::size_type x = 0; x < src.width(); ++x)
    {
      for (image::size_type c = 0; c < src.channels(); ++c)
      {
        dst.set_color(std::clamp(src.color_at(x, y, c) * value, 0.0f, 1.0f), x, y, c);
      }
    }
  }
  return dst;
}
}  // namespace filters
}  // namespace imageutils
