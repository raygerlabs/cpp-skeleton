#include "imageutils/JPEG.hpp"

#include <gtest/gtest.h>

using namespace imageutils;

namespace
{
using TestParam = std::tuple<std::string_view, imageutils::JPEG_Filter>;

class JPEG_FilterTextFixture : public testing::TestWithParam<TestParam>
{
protected:
  inline static constexpr const char* kSampleImagePath = "./resources/lena.jpg";

  JPEG_Image
  loadImage(std::string_view path)
  {
    const auto readResult = JPEG_Reader::read(path);
    EXPECT_TRUE(readResult) << "Failed to load image from path: " << path;
    return readResult;
  }

  void
  saveImage(const JPEG_Image& image, std::string_view path)
  {
    const auto writeResult = JPEG_Writer::write(image, path);
    EXPECT_TRUE(writeResult) << "Failed to save image to path: " << path;
  }

  void
  verifyImageEquality(const JPEG_Image& source, const JPEG_Image& target)
  {
    ASSERT_EQ(source.getWidth(), target.getWidth());
    ASSERT_EQ(source.getHeight(), target.getHeight());
    ASSERT_EQ(source.getFormat(), target.getFormat());
  }
};

TEST_P(JPEG_FilterTextFixture, ImageFilterTest)
{
  auto&& [outputPath, filterMethod] = GetParam();

  const auto sampleImage = loadImage(kSampleImagePath);
  const auto transformedImage = filterMethod(sampleImage);

  saveImage(transformedImage, outputPath);

  const JPEG_Image& readBackImage = loadImage(outputPath);
  verifyImageEquality(transformedImage, readBackImage);
}

INSTANTIATE_TEST_SUITE_P(ImageFilterTests, JPEG_FilterTextFixture,
                         testing::Values(std::make_tuple("./resources/lena_Brightness.jpg", filters::brightness(1.5f)),
                                         std::make_tuple("./resources/lena_Contrast.jpg", filters::contrast(1.5f)),
                                         std::make_tuple("./resources/lena_FlipH.jpg", filters::flipH()),
                                         std::make_tuple("./resources/lena_FlipV.jpg", filters::flipV()),
                                         std::make_tuple("./resources/lena_Grayscale.jpg", filters::grayscale()),
                                         std::make_tuple("./resources/lena_Invert.jpg", filters::invert()),
                                         std::make_tuple("./resources/lena_Resize.jpg", filters::resize(100, 100))));
} // namespace
