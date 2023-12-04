#include "resource_path.hpp"
#include "imageutils/image.hpp"

#include <gtest/gtest.h>

namespace imageutils
{
namespace unit_tests
{
TEST(jpeg_write_tests, check_jpeg_write)
{
  resource_path input_path("lena.jpg");
  resource_path output_path("lena_copy.jpg");

  image input_image(input_path.absolute_path());
  ASSERT_TRUE(input_image);

  ASSERT_TRUE(input_image.save(output_path.absolute_path()));

  image output_image(output_path.absolute_path());
  ASSERT_TRUE(output_image);
}
} // namespace unit_tests
} // namespace imageutils
