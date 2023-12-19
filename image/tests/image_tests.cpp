#include "path_helpers.hpp"

#include "image/image.hpp"
#include <gtest/gtest.h>

namespace unit_tests
{
TEST(image_tests, can_load_jpeg)
{
  constexpr const auto expected_image_size = 512;
  const auto jpeg_path = get_resource_file_path("lena.jpg");
  const auto result = cppskeleton::load_jpeg(jpeg_path);
  ASSERT_EQ(result.width(), expected_image_size);
  ASSERT_EQ(result.height(), expected_image_size);
}
}  // namespace unit_tests
