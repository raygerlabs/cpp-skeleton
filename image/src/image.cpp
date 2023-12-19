#include "image/image.hpp"

extern "C"
{
  #include <turbojpeg.h>
}

#include <filesystem>
#include <fstream>
#include <memory>
#include <sstream>
#include <stdexcept>

namespace cppskeleton
{
using unique_handle = std::unique_ptr<std::remove_pointer<tjhandle>::type, decltype(&tjDestroy)>;

unique_handle
make_compressor()
{
  return unique_handle(tjInitCompress(), tjDestroy);
}

unique_handle
make_decompressor()
{
  return unique_handle(tjInitDecompress(), tjDestroy);
}

image
decode_jpeg(std::vector<std::uint8_t> data)
{
  const auto decompressor = make_decompressor();
  int width{};
  int height{};
  if (tjDecompressHeader(decompressor.get(), data.data(), static_cast<unsigned long>(data.size()), &width, &height) < 0)
  {
    std::stringstream ss;
    ss << "Could not decompress jpeg header - error: ";
    ss << tjGetErrorStr();
    throw std::runtime_error(ss.str());
  }

  image result(static_cast<std::size_t>(width), static_cast<std::size_t>(height));
  if (tjDecompress2(decompressor.get(), data.data(), static_cast<unsigned long>(data.size()), result.data(), width, width * 4, height, TJPF_BGRX, 0) < 0)
  {
    std::stringstream ss;
    ss << "Could not decompress jpeg - error: ";
    ss << tjGetErrorStr();
    throw std::runtime_error(ss.str());
  }
  return result;
}

image
load_jpeg(const std::string& filename)
{
  std::ifstream file(filename, std::ios::binary);
  if (!file)
  {
    std::stringstream ss;
    ss << "Could not find file: " << filename;
    throw std::runtime_error(ss.str());
  }
  std::size_t file_size = std::filesystem::file_size(filename);
  std::vector<std::uint8_t> file_data(file_size);
  file.read(reinterpret_cast<char*>(&file_data[0]), static_cast<std::streamsize>(file_size));
  return decode_jpeg(std::move(file_data));
}
}  // namespace imagix
