#include "image/image.hpp"

#include <filesystem>
#include <iostream>

namespace integration {
std::string
get_resource_file_path(const std::string& filename)
{
  namespace fs = std::filesystem;
  return (fs::path(__FILE__).parent_path() / ".." / "tests" / "resources" / filename).string();
}
} // namespace integration

int
main()
{
  const auto path = integration::get_resource_file_path("lena.jpg");
  const auto result = cppskeleton::load_jpeg(path);
  if (result.width() == 0 || result.height() == 0 || !result.data())
  {
    std::cerr << "Failure: invalid decompression!\n";
    return EXIT_FAILURE;
  }
  std::cout << "Success!\n";
  return EXIT_SUCCESS;
}
