#pragma once

#include <filesystem>

namespace imageutils
{
namespace unit_tests
{
namespace fs = std::filesystem;

class resource_path
{
public:
  inline static const char* kCommonResourceRootPath = "resources";

  resource_path(const char* filename) : m_path(kCommonResourceRootPath)
  {
    m_path /= filename;
  }

  resource_path(const std::string& filename) : m_path(kCommonResourceRootPath)
  {
    m_path /= filename;
  }

  resource_path(std::string_view filename) : m_path(kCommonResourceRootPath)
  {
    m_path /= filename;
  }

  std::string
  relative_path() const noexcept
  {
    return m_path.string();
  }

  std::string
  absolute_path() const noexcept
  {
    return (std::filesystem::current_path() / m_path).string();
  }

private:
  std::filesystem::path m_path;
};
}  // namespace unit_tests
}  // namespace imageutils