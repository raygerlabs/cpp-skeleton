#pragma once

#include <string>
#include <vector>

namespace cppskeleton
{
class image
{
public:
  image() = default;
  image(std::size_t width, std::size_t height) : m_data(width * height * 4), m_width(width), m_height(height)
  {
  }
  image(std::vector<std::uint8_t> data, std::size_t width, std::size_t height)
      : m_data(data), m_width(width), m_height(height)
  {
  }
  image(const image& other) = default;
  image(image&& other) noexcept = default;
  image&
  operator=(const image& other) = default;
  image&
  operator=(image&& other) noexcept = default;
  ~image() noexcept = default;
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

image
decode_jpeg(std::vector<std::uint8_t> data);

image
load_jpeg(const std::string& filename);
}  // namespace cppskeleton
