#ifndef IMAGEUTILS_INTERNAL_JPEG_READER_HPP
#define IMAGEUTILS_INTERNAL_JPEG_READER_HPP

#pragma once

#include <string>
#include <string_view>

namespace imageutils
{
// Forward declarations
class JPEG_Image;

/**
 * @brief Class responsible for reading JPEG images.
 */
class JPEG_Reader
{
public:
  /**
   * @brief Reads a JPEG image from the specified path.
   * @param path Path to the JPEG image as a C-style string.
   * @return JPEGImage object containing the read image data.
   */
  static JPEG_Image
  read(const char* path);

  /**
   * @brief Reads a JPEG image from the specified path.
   * @param path Path to the JPEG image as a string view.
   * @return JPEGImage object containing the read image data.
   */
  static JPEG_Image
  read(std::string_view path);

  /**
   * @brief Reads a JPEG image from the specified path.
   * @param path Path to the JPEG image as a string.
   * @return JPEGImage object containing the read image data.
   */
  static JPEG_Image
  read(const std::string& path);
};
} // namespace imageutils

#endif // #define IMAGEUTILS_INTERNAL_JPEG_READER_HPP