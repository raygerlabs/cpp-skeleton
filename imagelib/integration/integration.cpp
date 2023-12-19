#include "imagelib/image_loader.hpp"
#include "imagelib/paths.hpp"
#include <iostream>
int
main()
{
  const auto resource_file = imagelib::resource_path() / "lena.jpg";
  const auto result = imagelib::load(resource_file.string());
  (void)result;
  std::cout << "Success!\n";
}
