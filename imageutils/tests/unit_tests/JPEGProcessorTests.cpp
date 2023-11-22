#include "imageutils/JPEGImage.hpp"
#include "imageutils/JPEGProcessor.hpp"
#include "imageutils/JPEGReader.hpp"
#include "imageutils/JPEGWriter.hpp"

#include "imageutils/filters/JPEGGrayscale.hpp"
#include "imageutils/filters/JPEGInvert.hpp"

#include <gtest/gtest.h>

using namespace imageutils;

namespace
{
class JPEGProcessorTestFixture : public testing::Test
{
protected:
  inline static constexpr const char* kSourcePath = "./resources/lena.jpg";
  JPEGProcessor processor;
  JPEGImage sourceImnage;

  void
  SetUp() override
  {
    processor.clear();
    sourceImnage = JPEGReader::read(kSourcePath);
    EXPECT_TRUE(sourceImnage);
  }
};

TEST_F(JPEGProcessorTestFixture, FilterChaining)
{
  constexpr const char* kDestinationPath = "./resources/lena_chain.jpg";
  const auto transform = processor.emplace(filters::invert()).emplace(filters::grayscale()).apply(sourceImnage);
  const auto result = JPEGWriter::write(transform, kDestinationPath);
  EXPECT_TRUE(result);
}

} // namespace
