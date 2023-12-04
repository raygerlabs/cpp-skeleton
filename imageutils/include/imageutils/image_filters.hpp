#pragma once

#include "imageutils/filters/brightness.hpp"
#include "imageutils/filters/contrast.hpp"
#include "imageutils/filters/grayscale.hpp"
#include "imageutils/filters/horizontal_flip.hpp"
#include "imageutils/filters/invert_colors.hpp"
#include "imageutils/filters/resize.hpp"
#include "imageutils/filters/vertical_flip.hpp"
#include "imageutils/image.hpp"

#include <functional>
#include <utility>

namespace imageutils
{
namespace filters
{
using image_filter = std::function<image(const image&)>;

template <typename F, typename... Args>
image_filter
make_filter(F&& f, Args... args) noexcept
{
  return [=](const image& img) -> image { 
    return f(img, args...);
};
}
}  // namespace filters
}  // namespace imageutils
