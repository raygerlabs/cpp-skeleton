#pragma once

#include <filesystem>

namespace unit_tests
{
std::string
get_resource_file_path(const char* filename) noexcept
{
  namespace fs = std::filesystem;
  static const auto resource_root_path = (fs::path(__FILE__).parent_path() / "resources");
  return (resource_root_path / filename).string();
}
}  // namespace unit_tests
