#include "imageutils/image_processor.hpp"
#include "imageutils/image.hpp"

namespace imageutils
{
image_processor&
image_processor::operator+=(filters::image_filter&& f) noexcept
{
  m_filters.emplace_back(std::move(f));
  return *this;
}
image
image_processor::apply(const image& img)
{
  image result(img);
  for (auto&& f : m_filters)
  {
    result = f(result);
  }
  m_filters.clear();
  std::vector<filters::image_filter>().swap(m_filters);
  return result;
}
}  // namespace imageutils
