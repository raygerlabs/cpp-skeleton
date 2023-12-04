#pragma once

#include "imageutils/image_filters.hpp"

#include <functional>
#include <vector>

namespace imageutils
{
class image;
class image_processor
{
public:
  image_processor&
  operator+=(filters::image_filter&& f) noexcept;

  image
  apply(const image& img);

private:
  std::vector<filters::image_filter> m_filters;
};
}  // namespace imageutils