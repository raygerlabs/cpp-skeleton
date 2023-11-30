#include "ResourcePath.hpp"
#include "imageutils/JPEG.hpp"

#include <gtest/gtest.h>

namespace imageutils
{
namespace unit_tests
{
TEST(JPEG_ReaderTests, ValidPath)
{
  ResourcePath path("lena.jpg");
  JPEG_Image image(path.getAbsolutePath());
  ASSERT_TRUE(image.is_open());
}

TEST(JPEG_ReaderTests, InvalidPath)
{
  ResourcePath path("invalid.jpg");
  JPEG_Image image(path.getAbsolutePath());
  ASSERT_FALSE(image.is_open());
}
} // namespace unit_tests
} // namespace imageutils
