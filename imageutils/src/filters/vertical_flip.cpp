#include "imageutils/filters/vertical_flip.hpp"
#include "imageutils/image.hpp"

namespace imageutils
{
namespace filters
{
image
vertical_flip(const image& src)
{
  image dst(src);
  for (image::size_type y = 0; y < src.height(); ++y)
  {
    for (image::size_type x = 0; x < src.width(); ++x)
    {
      for (image::size_type c = 0; c < src.channels(); ++c)
      {
        dst.set_color(src.color_at(x, src.height() - y - 1, c), x, y, c);
      }
    }
  }
  return dst;
}
}  // namespace filters
}  // namespace imageutils
