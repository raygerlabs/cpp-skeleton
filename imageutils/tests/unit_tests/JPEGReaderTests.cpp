#include "imageutils/JPEG.hpp"

#include <gtest/gtest.h>

using namespace imageutils;

namespace
{
TEST(ImageLoaderTest, LoadValidImage)
{
  constexpr const char* kSourcePath = "./resources/lena.jpg";
  const auto result = JPEG_Reader::read(kSourcePath);
  EXPECT_TRUE(result);
}

TEST(ImageLoaderTest, LoadInvalidImage)
{
  constexpr const char* kSourcePath = "invalidPath.jpg";
  const auto result = JPEG_Reader::read(kSourcePath);
  EXPECT_FALSE(result);
}
} // namespace
