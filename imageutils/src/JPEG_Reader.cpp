#include "imageutils/internal/JPEG_Reader.hpp"
#include "imageutils/internal/JPEG_Image.hpp"

extern "C"
{
#include <jerror.h>
#include <jpeglib.h>
}

#include <cassert>
#include <utility>

namespace imageutils
{
JPEG_Image
JPEG_Reader::read(std::string_view path)
{
  return JPEG_Reader::read(path.data());
}

JPEG_Image
JPEG_Reader::read(const std::string& path)
{
  return JPEG_Reader::read(path.c_str());
}

JPEG_Image
JPEG_Reader::read(const char* path)
{
  FILE* fHandle = fopen(path, "rb");
  if (!fHandle)
  {
    return {};
  }
  jpeg_decompress_struct cinfo;
  jpeg_error_mgr err;
  cinfo.err = jpeg_std_error(&err);
  jpeg_create_decompress(&cinfo);

  jpeg_stdio_src(&cinfo, fHandle);
  jpeg_read_header(&cinfo, true);
  jpeg_start_decompress(&cinfo);

  JPEG_Image result(cinfo.output_width, cinfo.output_height, static_cast<PixelFormat>(cinfo.output_components));
  std::uint8_t* rowBuffer[1];
  const auto rowStride = cinfo.output_width * cinfo.output_components;
  while (cinfo.output_scanline < cinfo.output_height)
  {
    rowBuffer[0] = static_cast<uint8_t*>(&result(0,0).value) + rowStride * cinfo.output_scanline;
    jpeg_read_scanlines(&cinfo, &rowBuffer[0], 1);
  }
  jpeg_finish_decompress(&cinfo);
  jpeg_destroy_decompress(&cinfo);
  fclose(fHandle);

  return result;
}

} // namespace imageutils