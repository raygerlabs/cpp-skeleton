#include "imageutils/image.hpp"
#include "imageutils/image_filters.hpp"
#include "imageutils/image_processor.hpp"
#include "resource_path.hpp"

#include <gtest/gtest.h>

using namespace imageutils::filters;

namespace imageutils
{
namespace unit_tests
{
TEST(image_processor_test, filter_chaining)
{
  resource_path input_path("lena.jpg");
  resource_path output_path("lena_chained_filters.jpg");

  image sample(input_path.absolute_path());
  ASSERT_TRUE(sample) << "Failed to open " << input_path.absolute_path();

  image_processor processor;
  processor += make_filter(brightness, 2.0f);
  processor += make_filter(contrast, 2.0f);
  processor += make_filter(grayscale);
  processor += make_filter(horizontal_flip);
  processor += make_filter(invert_colors);
  processor += make_filter(resize, 75, 75);
  processor += make_filter(vertical_flip);

  image result = processor.apply(sample);
  ASSERT_TRUE(result.save(output_path.absolute_path())) << "Failed to save " << output_path.absolute_path();

  image readBack(output_path.absolute_path());
  ASSERT_TRUE(readBack) << "Invalid image after processing";
}

}  // namespace unit_tests
}  // namespace imageutils
