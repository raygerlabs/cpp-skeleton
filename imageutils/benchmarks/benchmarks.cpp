#include <benchmark/benchmark.h>


#include "imageutils/image.hpp"
#include "imageutils/image_filters.hpp"
#include "imageutils/image_processor.hpp"

using namespace imageutils;
using namespace imageutils::filters;

// Register function as benchmark
static void
BM_ImageProcessing(benchmark::State& state)
{
  constexpr const auto kSourcePath = "./resources/lena.jpg";
  image input_image(kSourcePath); 
  image_processor processor;
  processor += make_filter(brightness, 2.0f);
  processor += make_filter(contrast, 2.0f);
  processor += make_filter(resize, 75U, 75U);
  processor += make_filter(vertical_flip);
  processor += make_filter(horizontal_flip);
  processor += make_filter(invert_colors);
  processor += make_filter(grayscale);

  for (auto _ : state)
  {
    image output_image = processor.apply(input_image);
    benchmark::DoNotOptimize(output_image);
  }
}

BENCHMARK(BM_ImageProcessing);

// Run benchmarks
BENCHMARK_MAIN();
