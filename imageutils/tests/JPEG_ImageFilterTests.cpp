#include "ResourcePath.hpp"

#include "imageutils/JPEG.hpp"

#include <gtest/gtest.h>

namespace imageutils
{
namespace unit_tests
{
class JPEG_ImageFilterFixture : public testing::Test
{
  ResourcePath samplePath = "lena.jpg";
  JPEG_Image sampleImage;

  void
  SetUp() override
  {
    sampleImage.open(samplePath.getAbsolutePath());
    ASSERT_TRUE(sampleImage.is_open());
  }

  void
  checkPixels(const JPEG_Image& a, const JPEG_Image& b)
  {
    static constexpr const float expectedThreshold = 0.1f; // JPEG is a lossy compression format, hence 

    ASSERT_EQ(a.channels(), b.channels());
    ASSERT_EQ(a.width(), b.width());
    ASSERT_EQ(a.height(), b.height());

    for (JPEG_Image::SizeType y = 0; y < 10; ++y)
    {
      for (JPEG_Image::SizeType x = 0; x < 10; ++x)
      {
        for (JPEG_Image::SizeType c = 0; c < 3; ++c)
        {
          EXPECT_NEAR(a.getPixelColor(x, y, c), b.getPixelColor(x, y, c), expectedThreshold);
        }
      }
    }
  }

protected:
  void
  performFilter(const std::string& filename, JPEG_Filter filter)
  {
    JPEG_Image transformedImage = filter(sampleImage);
    ASSERT_TRUE(transformedImage.save(filename));
    JPEG_Image readBackImage(filename);
    checkPixels(transformedImage, readBackImage);
  }
};

TEST_F(JPEG_ImageFilterFixture, verifyBrightnessFilter)
{
  ResourcePath path = "lena.brightness.jpg";
  performFilter(path.getAbsolutePath(), filters::brightness(1.8f));
}

TEST_F(JPEG_ImageFilterFixture, verifyContrastFilter)
{
  ResourcePath path = "lena.contrast.jpg";
  performFilter(path.getAbsolutePath(), filters::contrast(1.8f));
}

TEST_F(JPEG_ImageFilterFixture, verifyFlipVFilter)
{
  ResourcePath path = "lena.flipv.jpg";
  performFilter(path.getAbsolutePath(), filters::flipV());
}

TEST_F(JPEG_ImageFilterFixture, verifyFlipHFilter)
{
  ResourcePath path = "lena.fliph.jpg";
  performFilter(path.getAbsolutePath(), filters::flipH());
}

TEST_F(JPEG_ImageFilterFixture, verifyGrayscaleFilter)
{
  ResourcePath path = "lena.grayscale.jpg";
  performFilter(path.getAbsolutePath(), filters::grayscale());
}

TEST_F(JPEG_ImageFilterFixture, verifyInvertFilter)
{
  ResourcePath path = "lena.invert.jpg";
  performFilter(path.getAbsolutePath(), filters::invert());
}

TEST_F(JPEG_ImageFilterFixture, verifyResizeFilter)
{
  ResourcePath path = "lena.resize.jpg";
  performFilter(path.getAbsolutePath(), filters::resize(175, 175));
}

} // namespace unit_tests
} // namespace imageutils
