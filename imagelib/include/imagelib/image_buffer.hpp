#pragma once

#include <string>
#include <vector>

namespace imagelib
{
class image_buffer
{
public:
  image_buffer() : m_data(), m_width(0), m_height(0)
  {
  }

  image_buffer(std::size_t width, std::size_t height) : m_data(width * height * 4), m_width(width), m_height(height)
  {
  }
  image_buffer(std::vector<std::uint8_t> data, std::size_t width, std::size_t height)
      : m_data(data), m_width(width), m_height(height)
  {
  }
  image_buffer(const image_buffer& other) : m_data(other.m_data), m_width(other.m_width), m_height(other.m_height)
  {
  }
  image_buffer(image_buffer&& other) noexcept
      : m_data(std::move(other.m_data)), m_width(other.m_width), m_height(other.m_height)
  {
  }
  image_buffer&
  operator=(const image_buffer& other)
  {
    m_data = other.m_data;
    m_width = other.m_width;
    m_height = other.m_height;
    return *this;
  }

  image_buffer&
  operator=(image_buffer&& other) noexcept
  {
    m_data = std::move(other.m_data);
    m_width = other.m_width;
    m_height = other.m_height;
    return *this;
  }

  ~image_buffer() noexcept
  {
  }

  std::uint8_t*
  data() noexcept
  {
    return &m_data[0];
  }

  const std::uint8_t*
  data() const noexcept
  {
    return &m_data[0];
  }

  std::size_t
  width() const noexcept
  {
    return m_width;
  }

  std::size_t
  height() const noexcept
  {
    return m_height;
  }

private:
  std::vector<std::uint8_t> m_data;
  std::size_t m_width;
  std::size_t m_height;
};

}  // namespace imagelib
