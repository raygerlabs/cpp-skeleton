#include "imageutils/JPEG.hpp"

#include <gtest/gtest.h>

namespace
{
TEST(ImageLoaderTest, ImageWriteBack)
{
  using namespace imageutils;
  constexpr const char* kSourcePath = "./resources/lena.jpg";
  constexpr const char* kDestinationPath = "./resources/lena_copy.jpg";

  const JPEG_Image sourceImage = JPEG_Reader::read(kSourcePath);
  EXPECT_TRUE(sourceImage);
  EXPECT_NE(sourceImage.getPixel(0, 0).value, 0);
  EXPECT_EQ(sourceImage.getFormat(), PixelFormat::RGB);

  const auto result = JPEG_Writer::write(sourceImage, kDestinationPath);
  EXPECT_TRUE(result);


}
} // namespace
