#include "imagelib/image_loader.hpp"
#include "imagelib/paths.hpp"
#include <gtest/gtest.h>

namespace unit_tests
{
TEST(image_loader_tests, image_can_be_loaded)
{
  const auto resource_file = imagelib::resource_path() / "lena.jpg";
  constexpr const auto expected_image_size = 512;
  const auto result = imagelib::load(resource_file.string());
  ASSERT_EQ(result.width(), expected_image_size);
  ASSERT_EQ(result.height(), expected_image_size);
}
}  // namespace unit_tests
