#include "imageutils/JPEGWriter.hpp"
#include "imageutils/JPEGImage.hpp"

extern "C"
{
#include <jerror.h>
#include <jpeglib.h>
}

#include <algorithm>

namespace imageutils
{
bool
JPEGWriter::write(const JPEGImage& input, std::string_view path, int imageQuality)
{
  return JPEGWriter::write(std::move(input), path.data(), imageQuality);
}

bool
JPEGWriter::write(const JPEGImage& input, const std::string& path, int imageQuality)
{
  return JPEGWriter::write(std::move(input), path.c_str(), imageQuality);
}

bool
JPEGWriter::write(const JPEGImage& input, const char* path, int imageQuality)
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

  // Set color space and components based on the image format
  switch (input.getFormat())
  {
  case PixelFormat::GRAYSCALE:
    cinfo.input_components = 1;
    cinfo.in_color_space = JCS_GRAYSCALE;
    break;
  default:
    // Defaulting to RGB565 if the format is not recognized
    cinfo.input_components = 3;
    cinfo.in_color_space = JCS_RGB;
    break;
  }

  // Initialize libjpeg structures
  jpeg_set_defaults(&cinfo);
  jpeg_set_quality(&cinfo, imageQuality, true);
  jpeg_start_compress(&cinfo, true);

  std::uint8_t* rowBuffer[1];
  const std::size_t rowStride = cinfo.image_width * cinfo.input_components;
  while (cinfo.next_scanline < cinfo.image_height)
  {
    rowBuffer[0] =
        static_cast<uint8_t*>(&const_cast<JPEGImage&>(input).getPixel(0, 0).value) + rowStride * cinfo.next_scanline;
    jpeg_write_scanlines(&cinfo, &rowBuffer[0], 1);
  }

  // Finish compression process
  jpeg_finish_compress(&cinfo);
  fclose(fHandle);

  return true;
}

} // namespace imageutils