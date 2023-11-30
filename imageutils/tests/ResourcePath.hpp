#pragma once

#include <filesystem>

namespace imageutils
{
namespace unit_tests
{
namespace fs = std::filesystem;

class ResourcePath
{
public:
  ResourcePath(const char* fname) : m_relpath(kResourceRootPath) { m_relpath /= fname; }
  ResourcePath(const std::string& fname) : m_relpath(kResourceRootPath) { m_relpath /= fname; }
  ResourcePath(std::string_view fname) : m_relpath(kResourceRootPath) { m_relpath /= fname; }

  std::string
  getRelativePath() const noexcept
  {
    return m_relpath.string();
  }

  std::string
  getAbsolutePath() const noexcept
  {
    return (std::filesystem::current_path() / m_relpath).string();
  }

private:
  inline static const char* kResourceRootPath = "resources";
  std::filesystem::path m_relpath;
};
} // namespace unit_tests
} // namespace imageutils