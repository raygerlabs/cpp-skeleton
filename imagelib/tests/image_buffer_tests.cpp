#include "imagelib/image_buffer.hpp"

#include <gtest/gtest.h>

namespace unit_tests
{
TEST(image_buffer_tests, empty_buffer)
{
  imagelib::image_buffer buffer;
  EXPECT_EQ(buffer.width(), 0);
  EXPECT_EQ(buffer.height(), 0);
}

TEST(image_buffer_tests, valid_image_buffer_dimensions)
{
  imagelib::image_buffer buffer(100, 100);
  EXPECT_EQ(buffer.width(), 100);
  EXPECT_EQ(buffer.height(), 100);
}
}  // namespace unit_tests
