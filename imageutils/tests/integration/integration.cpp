#include "imageutils/JPEGImage.hpp"
#include "imageutils/JPEGProcessor.hpp"
#include "imageutils/JPEGReader.hpp"
#include "imageutils/JPEGWriter.hpp"

#include "imageutils/filters/JPEGBrightness.hpp"
#include "imageutils/filters/JPEGContrast.hpp"
#include "imageutils/filters/JPEGFlipH.hpp"
#include "imageutils/filters/JPEGFlipV.hpp"
#include "imageutils/filters/JPEGGrayscale.hpp"
#include "imageutils/filters/JPEGInvert.hpp"
#include "imageutils/filters/JPEGResize.hpp"

#include <iostream>

int main() {
  constexpr const auto sourcePath = "./resources/lena.jpg";
  constexpr const auto targetPath = "./resources/lena_Copy.jpg";
  const auto sourceImage = imageutils::JPEGReader::read(sourcePath);
  if (!sourceImage) {
    std::cerr << "Failed to find input image: " << sourcePath << '\n';
    return EXIT_FAILURE;
  }

  imageutils::JPEGProcessor processor;
  const auto targetImage = processor
          .add(imageutils::filters::brightness(2.0))
          .add(imageutils::filters::contrast(0.8))
          .add(imageutils::filters::resize(175, 175))
          .add(imageutils::filters::flipH())
          .add(imageutils::filters::flipV())
          .add(imageutils::filters::invert())
          .add(imageutils::filters::grayscale())
          .apply(sourceImage);
  if (!imageutils::JPEGWriter::write(targetImage, targetPath)) {
    std::cerr << "Failed to save image on disk: " << targetPath << "\n";
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
