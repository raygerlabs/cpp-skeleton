#include "resource_path.hpp"
#include "imageutils/image.hpp"

#include <gtest/gtest.h>

namespace imageutils
{
namespace unit_tests
{
TEST(jpeg_read_tests, valid_path)
{
  resource_path path("lena.jpg");
  image img(path.absolute_path());
  ASSERT_TRUE(img);
}

TEST(jpeg_read_tests, invalid_path)
{
  resource_path path("invalid.jpg");
  image img(path.absolute_path());
  ASSERT_FALSE(img);
}
} // namespace unit_tests
} // namespace imageutils
