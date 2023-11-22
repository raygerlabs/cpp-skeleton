#include "imageutils/JPEGImage.hpp"
#include "imageutils/JPEGReader.hpp"

#include <gtest/gtest.h>

using namespace imageutils;

namespace
{
TEST(ImageLoaderTest, LoadValidImage)
{
  constexpr const char* kSourcePath = "./resources/lena.jpg";
  const JPEGImage loadedImage = JPEGReader::read(kSourcePath);
  EXPECT_TRUE(loadedImage);
  EXPECT_NE(loadedImage.getPixel(0, 0).value, 0);
  EXPECT_EQ(loadedImage.getFormat(), PixelFormat::RGB);
}

TEST(ImageLoaderTest, LoadInvalidImage)
{
  constexpr const char* kSourcePath = "invalidPath.jpg";
  const JPEGImage loadedImage = JPEGReader::read(kSourcePath);
  EXPECT_FALSE(loadedImage);
}
} // namespace
