#include "imageutils/image.hpp"
#include "imageutils/image_filters.hpp"
#include "imageutils/image_processor.hpp"

#include <iostream>

int
main()
{
  using namespace imageutils;
  using namespace imageutils::filters;

  constexpr const auto kSourcePath = "./resources/lena.jpg";
  constexpr const auto kTargetPath = "./resources/lena_Copy.jpg";

  std::cout << "-- Starting integration test..." << std::endl;

  image source_img(kSourcePath);
  if (!source_img.is_open())
  {
    std::cerr << "Could not find image: " << kSourcePath << std::endl;
    std::cerr << "-- Integration test FAILED!" << std::endl;
    return EXIT_FAILURE;
  }

  image_processor processor;
  processor += make_filter(brightness, 2.0f);
  processor += make_filter(contrast, 2.0f);
  processor += make_filter(resize, 150, 150);
  processor += make_filter(vertical_flip);
  processor += make_filter(horizontal_flip);
  processor += make_filter(invert_colors);
  processor += make_filter(grayscale);

  image target_img = processor.apply(source_img);
  if (!target_img.is_open())
  {
    std::cerr << "ERROR: Could not apply filters to source image " << kSourcePath << std::endl;
    std::cerr << "-- Integration test FAILED!" << std::endl;
    return EXIT_FAILURE;
  }

  if (!target_img.save(kTargetPath))
  {
    std::cerr << "ERROR: Could not save image: " << kTargetPath << std::endl;
    std::cerr << "-- Integration test FAILED!" << std::endl;
    return EXIT_FAILURE;
  }

  image read_back_img(kTargetPath);
  if (!read_back_img.is_open())
  {
    std::cerr << "ERROR: Could not open the previously saved image: " << kTargetPath << std::endl;
    std::cerr << "-- Integration test FAILED!" << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << "-- Integration test PASSED!" << std::endl;
  return EXIT_SUCCESS;
}
