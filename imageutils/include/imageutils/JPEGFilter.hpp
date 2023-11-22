#ifndef IMAGEUTILS_JPEGFILTER_HPP
#define IMAGEUTILS_JPEGFILTER_HPP

#pragma once

#include <functional>

namespace imageutils
{
class JPEGImage;
using JPEGFilter = std::function<JPEGImage(const JPEGImage&)>;
} // namespace imageutils

#endif