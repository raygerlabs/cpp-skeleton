#ifndef IMAGEUTILS_INTERNAL_JPEG_FILTER_HPP
#define IMAGEUTILS_INTERNAL_JPEG_FILTER_HPP

#pragma once

#include "imageutils/internal/JPEG_Image.hpp"

#include <functional>

namespace imageutils
{
using JPEG_Filter = std::function<JPEG_Image(const JPEG_Image&)>;
} // namespace imageutils

#endif // IMAGEUTILS_INTERNAL_JPEG_FILTER_HPP