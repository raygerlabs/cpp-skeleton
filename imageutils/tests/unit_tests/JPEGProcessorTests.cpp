#include "imageutils/JPEG.hpp"

#include <gtest/gtest.h>

using namespace imageutils;

namespace
{
class JPEGProcessorTestFixture : public testing::Test
{
protected:
  inline static constexpr const char* kSourcePath = "./resources/lena.jpg";
  JPEG_Processor processor;
  JPEG_Image sourceImage;

  void
  SetUp() override
  {
    processor.clear();
    sourceImage = JPEG_Reader::read(kSourcePath);
    EXPECT_TRUE(sourceImage);
  }
};

TEST_F(JPEGProcessorTestFixture, FilterChaining)
{
  constexpr const char* kDestinationPath = "./resources/lena_chain.jpg";
  const auto transform = processor.emplace(filters::brightness(1.5f))
                             .emplace(filters::contrast(0.5f))
                             .emplace(filters::invert())
                             .emplace(filters::grayscale())
                             .emplace(filters::flipV())
                             .emplace(filters::flipH())
                             .emplace(filters::resize(175, 175))
                             .apply(sourceImage);
  const auto result = JPEG_Writer::write(transform, kDestinationPath);
  EXPECT_TRUE(result);
}

} // namespace
