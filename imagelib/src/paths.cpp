#include "imagelib/paths.hpp"

#include <filesystem>

namespace imagelib
{
std::filesystem::path
project_root_path()
{
  return std::filesystem::path(__FILE__).parent_path().parent_path();
}

std::filesystem::path
resource_path()
{
  return project_root_path() / "resources";
}
}  // namespace imagelib