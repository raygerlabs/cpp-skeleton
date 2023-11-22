#include "imageutils/JPEGImage.hpp"
#include "imageutils/JPEGReader.hpp"
#include "imageutils/JPEGWriter.hpp"

#include <gtest/gtest.h>

namespace
{
TEST(ImageLoaderTest, ImageWriteBack)
{
  using namespace imageutils;
  constexpr const char* kSourcePath = "./resources/lena.jpg";
  constexpr const char* kDestinationPath = "./resources/lena_copy.jpg";
  const JPEGImage sourceImage = JPEGReader::read(kSourcePath);
  EXPECT_TRUE(sourceImage);
  EXPECT_NE(sourceImage.getPixel(0, 0).value, 0);
  EXPECT_EQ(sourceImage.getFormat(), PixelFormat::RGB);
  const bool result = JPEGWriter::write(sourceImage, kDestinationPath);
  EXPECT_TRUE(result); // image has been written to the disk
}
} // namespace
