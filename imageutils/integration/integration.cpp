#include "imageutils/JPEG.hpp"
#include <iostream>

int main() {
  using namespace imageutils;
  
  constexpr const auto sourcePath = "./resources/lena.jpg";
  constexpr const auto targetPath = "./resources/lena_Copy.jpg";

  const auto imageSample = JPEG_Reader::read(sourcePath);
  if (!imageSample) {
    std::cerr << "Could not find sample image: " << sourcePath << '\n';
    return EXIT_FAILURE;
  }

  JPEG_Processor processor;

  const auto transformedImage = processor
          .add(imageutils::filters::brightness(2.0))
          .add(imageutils::filters::contrast(0.8))
          .add(imageutils::filters::resize(175, 175))
          .add(imageutils::filters::flipH())
          .add(imageutils::filters::flipV())
          .add(imageutils::filters::invert())
          .add(imageutils::filters::grayscale())
          .apply(imageSample);

  const auto writeResult = JPEG_Writer::write(transformedImage, targetPath);
  if (!writeResult) {
    std::cerr << "Could not save the transformed image: " << targetPath << "\n";
    return EXIT_FAILURE;
  }

  const auto readBackImage = JPEG_Reader::read(targetPath);
  if (!readBackImage) {
    std::cerr << "Could not read back previously saved image: " << sourcePath << '\n';
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
