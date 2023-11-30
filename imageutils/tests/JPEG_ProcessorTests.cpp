#include "ResourcePath.hpp"
#include "imageutils/JPEG.hpp"

#include <gtest/gtest.h>

namespace imageutils
{
namespace unit_tests
{
TEST(JPEGProcessorFixture, ChainFilters)
{
  ResourcePath samplePath("lena.jpg");
  JPEG_Image sourceImage(samplePath.getAbsolutePath());

  JPEG_Processor processor;
  JPEG_Image transform = processor.emplace(imageutils::filters::brightness(1.5f))
                             .emplace(imageutils::filters::contrast(0.5f))
                             .emplace(imageutils::filters::invert())
                             .emplace(imageutils::filters::grayscale())
                             .emplace(imageutils::filters::flipV())
                             .emplace(imageutils::filters::flipH())
                             .emplace(imageutils::filters::resize(175, 175))
                             .apply(sourceImage);

  ResourcePath targetFile("lena.chaining.jpg");
  ASSERT_TRUE(transform.save(targetFile.getAbsolutePath()));
}

} // namespace unit_tests
} // namespace imageutils
