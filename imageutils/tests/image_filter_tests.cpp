#include "resource_path.hpp"

#include "imageutils/image.hpp"
#include "imageutils/image_filters.hpp"

#include <gtest/gtest.h>

using namespace imageutils::filters;

namespace imageutils
{
namespace unit_tests
{
class image_filter_fixture : public testing::Test
{
  resource_path sample_path = "lena.jpg";
  image sample_img;

  void
  SetUp() override
  {
    sample_img.open(sample_path.absolute_path());
    ASSERT_TRUE(sample_img.is_open());
  }

  void
  checks_per_pixel(const image& lhs, const image& rhs)
  {
    // jpeg is a lossy compression format
    // hence use a reasonable tolerance threshold for checks
    static constexpr const float expected_threshold = 0.1f;

    ASSERT_EQ(lhs.channels(), rhs.channels());
    ASSERT_EQ(lhs.width(),    rhs.width());
    ASSERT_EQ(lhs.height(),   rhs.height());

    for (image::size_type y = 0; y < 10; ++y)
    {
      for (image::size_type x = 0; x < 10; ++x)
      {
        for (image::size_type c = 0; c < 3; ++c)
        {
          EXPECT_NEAR(lhs.color_at(x, y, c), rhs.color_at(x, y, c), expected_threshold);
        }
      }
    }
  }

protected:
  void
  execute_filter(const std::string& filename, const image_filter& filter)
  {
    image transform_img = filter(sample_img);
    ASSERT_TRUE(transform_img.save(filename));
    
    image read_back_img(filename);
    checks_per_pixel(read_back_img, transform_img);
  }
};

TEST_F(image_filter_fixture, check_brightness)
{
  resource_path path = "lena.brightness.jpg";
  execute_filter(path.absolute_path(), make_filter(brightness, 2.0f));
}

TEST_F(image_filter_fixture, check_contrast)
{
  resource_path path = "lena.contrast.jpg";
  execute_filter(path.absolute_path(), make_filter(contrast, 2.0f));
}

TEST_F(image_filter_fixture, check_vertical_flip)
{
  resource_path path = "lena.flipped_vertical.jpg";
  execute_filter(path.absolute_path(), make_filter(vertical_flip));
}

TEST_F(image_filter_fixture, check_horizontal_flip)
{
  resource_path path = "lena.flipped_horizontal.jpg";
  execute_filter(path.absolute_path(), make_filter(horizontal_flip));
}

TEST_F(image_filter_fixture, check_grayscale)
{
  resource_path path = "lena.grayscale.jpg";
  execute_filter(path.absolute_path(), make_filter(grayscale));
}

TEST_F(image_filter_fixture, check_invert_colors)
{
  resource_path path = "lena.invert.jpg";
  execute_filter(path.absolute_path(), make_filter(invert_colors));
}

TEST_F(image_filter_fixture, check_resize)
{
  resource_path path = "lena.resize.jpg";
  execute_filter(path.absolute_path(), make_filter(resize, 75, 75));
}

}  // namespace unit_tests
}  // namespace imageutils
