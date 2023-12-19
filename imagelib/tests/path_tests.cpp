#include "imagelib/paths.hpp"
#include <gtest/gtest.h>

namespace unit_tests
{
TEST(path_tests, valid_resource_path)
{
  namespace fs = std::filesystem;

  const auto resource_path = imagelib::resource_path();
  const auto resource_file = resource_path / "lena.jpg";

  EXPECT_TRUE(fs::is_directory(resource_path));
  EXPECT_TRUE(fs::exists(resource_file));
}
}  // namespace unit_tests
