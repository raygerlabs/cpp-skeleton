
#if defined(_MSC_VER)
#pragma warning(push, 0)
#pragma warning(disable : 4996)
#endif

#include "imageutils/image.hpp"

extern "C"
{
#include <jerror.h>
#include <jpeglib.h>
}

#include <cassert>
#include <fstream>
#include <iostream>
#include <memory>

namespace imageutils
{
bool
image::open(const std::string& filename)
{
  jpeg_decompress_struct cinfo;
  jpeg_error_mgr jerr;
  std::unique_ptr<FILE, decltype(&fclose)> file(fopen(filename.c_str(), "rb"), &fclose);
  if (!file)
  {
    std::cerr << "ERROR: Failed to open \'" << filename << "\'\n";
    return false;
  }

  cinfo.err = jpeg_std_error(&jerr);
  jpeg_create_decompress(&cinfo);

  jpeg_stdio_src(&cinfo, file.get());
  jpeg_read_header(&cinfo, true);
  jpeg_start_decompress(&cinfo);

  size_type newSize = cinfo.output_width * cinfo.output_height * static_cast<size_type>(cinfo.output_components);
  m_data.resize(newSize);
  m_width = cinfo.output_width;
  m_height = cinfo.output_height;
  m_channels = static_cast<size_type>(cinfo.output_components);

  size_type rowStride = m_width * m_channels;
  pixel_pointer rowPtr[1];
  while (cinfo.output_scanline < cinfo.output_height)
  {
    rowPtr[0] = &m_data[0] + rowStride * cinfo.output_scanline;
    jpeg_read_scanlines(&cinfo, &rowPtr[0], 1);
  }
  jpeg_finish_decompress(&cinfo);
  jpeg_destroy_decompress(&cinfo);

  return true;
}

bool
image::save(const std::string& filename, int quality)
{
  jpeg_compress_struct cinfo;
  jpeg_error_mgr jerr;

  std::unique_ptr<FILE, decltype(&fclose)> file(fopen(filename.c_str(), "wb"), &fclose);
  if (!file)
  {
    std::cerr << "JPEG_Image::save(): Failed to open \'" << filename << "\'!";
    return false;
  }

  cinfo.err = jpeg_std_error(&jerr);
  jpeg_create_compress(&cinfo);

  cinfo.image_width = m_width;
  cinfo.image_height = m_height;
  cinfo.input_components = static_cast<std::int32_t>(m_channels);
  cinfo.in_color_space = (m_channels == 1) ? JCS_GRAYSCALE : JCS_RGB;

  jpeg_set_defaults(&cinfo);
  jpeg_set_quality(&cinfo, quality, true);
  jpeg_stdio_dest(&cinfo, file.get());
  jpeg_start_compress(&cinfo, true);

  const auto rowStride = m_width * m_channels;
  pixel_pointer rowPtr[1];
  while (cinfo.next_scanline < cinfo.image_height)
  {
    rowPtr[0] = &m_data[0] + rowStride * cinfo.next_scanline;
    jpeg_write_scanlines(&cinfo, &rowPtr[0], 1);
  }

  jpeg_finish_compress(&cinfo);
  jpeg_destroy_compress(&cinfo);

  return true;
}
}  // namespace imageutils

#if defined(_MSC_VER)
#pragma warning(pop)
#endif
