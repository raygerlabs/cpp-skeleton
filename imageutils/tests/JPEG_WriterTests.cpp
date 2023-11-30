#include "ResourcePath.hpp"
#include "imageutils/JPEG.hpp"

#include <gtest/gtest.h>

namespace imageutils
{
namespace unit_tests
{
TEST(JPEG_WriterTests, TestImageReadsBack)
{
  ResourcePath samplePath("lena.jpg");
  JPEG_Image sourceImage(samplePath.getAbsolutePath());
  ASSERT_TRUE(sourceImage.is_open());

  ResourcePath targetPath("lena.copy.jpg");
  ASSERT_TRUE(sourceImage.save(targetPath.getAbsolutePath()));

  JPEG_Image targetImage(targetPath.getAbsolutePath());
  ASSERT_TRUE(targetImage.is_open());
}
} // namespace unit_tests
} // namespace imageutils
