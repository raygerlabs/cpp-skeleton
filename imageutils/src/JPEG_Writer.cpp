#include "imageutils/internal/JPEG_Writer.hpp"
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
bool
JPEG_Writer::write(const JPEG_Image& input, std::string_view path, int imageQuality)
{
  return JPEG_Writer::write(input, path.data(), imageQuality);
}

bool
JPEG_Writer::write(const JPEG_Image& input, const std::string& path, int imageQuality)
{
  return JPEG_Writer::write(input, path.c_str(), imageQuality);
}

bool
JPEG_Writer::write(const JPEG_Image& input, const char* path, int imageQuality)
{
  // Initialize the JPEG compression structures
  jpeg_compress_struct cinfo;
  jpeg_error_mgr err;

  // File handle for writing
  FILE* fHandle = fopen(path, "wb");
  if (!fHandle)
  {
    return false;
  }

  // Error handling setup
  cinfo.err = jpeg_std_error(&err);
  jpeg_create_compress(&cinfo);
  jpeg_stdio_dest(&cinfo, fHandle);

  // Set image parameters
  cinfo.image_width = input.getWidth();
  cinfo.image_height = input.getHeight();

  switch (input.getFormat())
  {
  case PixelFormat::GRAYSCALE:
    cinfo.input_components = 1;
    cinfo.in_color_space = JCS_GRAYSCALE;
    break;
  default:
    cinfo.input_components = 3;
    cinfo.in_color_space = JCS_RGB;
    break;
  }

  // Initialize libjpeg structures
  jpeg_set_defaults(&cinfo);
  jpeg_set_quality(&cinfo, imageQuality, true);
  jpeg_start_compress(&cinfo, true);

  std::uint8_t* rowBuffer[1];
  const auto rowStride = cinfo.image_width * cinfo.input_components;
  while (cinfo.next_scanline < cinfo.image_height)
  {
    rowBuffer[0] = static_cast<uint8_t*>(&const_cast<JPEG_Image&>(input)(0, 0).value) + rowStride * cinfo.next_scanline;
    jpeg_write_scanlines(&cinfo, &rowBuffer[0], 1);
  }

  // Finish compression process
  jpeg_finish_compress(&cinfo);
  fclose(fHandle);

  return true;
}

} // namespace imageutils