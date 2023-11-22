#include "imageutils/JPEGImage.hpp"
#include "imageutils/JPEGReader.hpp"
#include "imageutils/JPEGWriter.hpp"

#include "imageutils/filters/JPEGBrightness.hpp"
#include "imageutils/filters/JPEGContrast.hpp"
#include "imageutils/filters/JPEGFlipH.hpp"
#include "imageutils/filters/JPEGFlipV.hpp"
#include "imageutils/filters/JPEGGrayscale.hpp"
#include "imageutils/filters/JPEGInvert.hpp"
#include "imageutils/filters/JPEGResize.hpp"

#include <gtest/gtest.h>

#include <algorithm>
#include <numeric>

using namespace imageutils;

namespace
{
class JPEG_FilterTestFixture : public testing::Test
{
protected:
  inline static constexpr const char* kSourcePath = "./resources/lena.jpg";
  JPEGImage sourceImage;

  void
  SetUp() override
  {
    sourceImage = JPEGReader::read(kSourcePath);
    ASSERT_TRUE(sourceImage);
  }
};

// static float
// getAvgBrightness(const JPEGImage& image)
//{
//   const auto N = image.end() - image.begin();
//   return std::accumulate(image.begin(), image.end(), 0.0f) / N;
// };
//
// static float
// getAvgContrast(const JPEGImage& image)
//{
//   const auto N = image.end() - image.begin();
//   float avgBrightness = getAvgBrightness(image);
//   float contrastSum = std::transform_reduce(image.begin(), image.end(), 0.0f, std::plus{},
//                                             [avgBrightness](auto pixel) { return std::abs(pixel - avgBrightness); });
//   return contrastSum / N;
// };

TEST_F(JPEG_FilterTestFixture, ImageBrightnessChanged)
{
  constexpr const char* kDestinationPath = "./resources/lena_Brightness15.jpg";
  const auto brightnessValue = 1.5f;
  const auto filter = filters::brightness(brightnessValue);
  EXPECT_TRUE(JPEGWriter::write(filter(sourceImage), kDestinationPath));
}

TEST_F(JPEG_FilterTestFixture, ImageContrastChanged)
{
  constexpr const char* kDestinationPath = "./resources/lena_Contrast15.jpg";
  const auto contrastValue = 1.5f;
  const auto filter = filters::contrast(contrastValue);
  EXPECT_TRUE(JPEGWriter::write(filter(sourceImage), kDestinationPath));
}

TEST_F(JPEG_FilterTestFixture, ImageFlippedVertically)
{
  constexpr const char* kDestinationPath = "./resources/lena_FlippedV.jpg";
  const auto filter = filters::flipV();
  EXPECT_TRUE(JPEGWriter::write(filter(sourceImage), kDestinationPath));
}

TEST_F(JPEG_FilterTestFixture, ImageFlippedHorizontally)
{
  constexpr const char* kDestinationPath = "./resources/lena_FlippedH.jpg";
  const auto filter = filters::flipH();
  EXPECT_TRUE(JPEGWriter::write(filter(sourceImage), kDestinationPath));
}

TEST_F(JPEG_FilterTestFixture, ImageColorsGrayscaled)
{
  constexpr const char* kDestinationPath = "./resources/lena_Grayscale.jpg";
  const auto expectedChannels = 1;
  const auto filter = filters::grayscale();
  EXPECT_TRUE(JPEGWriter::write(filter(sourceImage), kDestinationPath));
}

TEST_F(JPEG_FilterTestFixture, ImageColorsInverted)
{
  constexpr const char* kDestinationPath = "./resources/lena_Inverted.jpg";
  const auto filter = filters::invert();
  EXPECT_TRUE(JPEGWriter::write(filter(sourceImage), kDestinationPath));
}

TEST_F(JPEG_FilterTestFixture, ImageResized)
{
  constexpr const char* kDestinationPath = "./resources/lena_Resized.jpg";
  const auto expectedSize = 100;
  const auto expectedChannels = 3;
  const auto filter = filters::resize(expectedSize, expectedSize);
  EXPECT_TRUE(JPEGWriter::write(filter(sourceImage), kDestinationPath));
}

} // namespace
