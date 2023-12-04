#pragma once

// #include "imageutils/color.hpp"

#include <cstdint>
#include <string>
#include <vector>

namespace imageutils
{

class image
{
public:
  using pixel_data = std::uint8_t;
  using pixel_color = float;
  using size_type = std::uint32_t;

  using pixel_vector = std::vector<pixel_data>;

  using pixel_pointer = pixel_data*;
  using const_pixel_pointer = const pixel_data*;
  using pixel_reference = pixel_data&;
  using const_pixel_reference = const pixel_data&;

  image() = default;

  image(const std::string& filename)
  {
    open(filename);
  }

  image(size_type width, size_type height, size_type channels = 3)
      : m_data(width * height * channels), m_width(width), m_height(height), m_channels(channels)
  {
  }

  image(const image& other) = default;

  image&
  operator=(const image& other) = default;

  image(image&& other) noexcept = default;

  image&
  operator=(image&& other) noexcept = default;

  ~image() = default;

  operator bool() const noexcept
  {
    return this->is_open();
  }

  bool
  is_open() const noexcept
  {
    return m_data.size() > 0;
  }

  constexpr size_type
  width() const noexcept
  {
    return m_width;
  }

  constexpr size_type
  height() const noexcept
  {
    return m_height;
  }

  constexpr size_type
  channels() const noexcept
  {
    return m_channels;
  }

  bool
  open(const std::string& filename);

  bool
  save(const std::string& filename, int quality = 75);

  void
  close()
  {
    pixel_vector().swap(m_data);
  }

  pixel_color
  color_at(size_type x, size_type y, size_type channel = 0) const noexcept
  {
    return static_cast<pixel_color>(m_data[(y * m_width + x) * m_channels + channel]) / 255.0f;
  }

  void
  set_color(pixel_color color, size_type x, size_type y, size_type channel = 0)
  {
    m_data[(y * m_width + x) * m_channels + channel] = static_cast<pixel_data>(color * 255.0f);
  }

private:
  pixel_vector m_data;
  size_type m_width;
  size_type m_height;
  size_type m_channels;
};
}  // namespace imageutils
