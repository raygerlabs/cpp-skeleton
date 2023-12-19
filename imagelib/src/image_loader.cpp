#include "imagelib/image_loader.hpp"
#include "tj_helpers.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>

namespace imagelib
{
image_buffer
decode(std::vector<std::uint8_t> data)
{
  int width = 0, height = 0;
  const auto decompressor = make_decompressor();
  if (tjDecompressHeader(decompressor.get(), data.data(), static_cast<unsigned long>(data.size()), &width, &height) < 0)
  {
    std::stringstream ss;
    ss << "Could not decompress image header: " << tjGetErrorStr();
    throw std::runtime_error(ss.str());
  }
  image_buffer buffer(static_cast<std::size_t>(width), static_cast<std::size_t>(height));
  if (tjDecompress2(decompressor.get(), data.data(), static_cast<unsigned long>(data.size()), buffer.data(), width,
                    width * 4, height, TJPF_BGRX, 0) < 0)
  {
    std::stringstream ss;
    ss << "Could not decompress image: " << tjGetErrorStr();
    throw std::runtime_error(ss.str());
  }
  return buffer;
}
image_buffer
load(const std::string& filename)
{
  std::streampos fsize = 0;
  std::ifstream file(filename, std::ios::binary | std::ios::ate);
  if (!file)
  {
    std::stringstream ss;
    ss << "Could not find file: " << filename;
    throw std::runtime_error(ss.str());
  }
  fsize = file.tellg();
  file.clear();
  file.seekg(0, std::ios::beg);
  std::vector<std::uint8_t> data(static_cast<std::size_t>(fsize));
  file.read(reinterpret_cast<char*>(&data[0]), fsize);
  return decode(std::move(data));
}
}  // namespace imagelib
