#ifndef IMAGEUTILS_JPEGREADER_HPP
#define IMAGEUTILS_JPEGREADER_HPP

#pragma once

#include <string>
#include <string_view>

namespace imageutils
{
// Forward declarations
union PixelColor;
class JPEGImage;

/**
 * @brief Class responsible for reading JPEG images.
 */
class JPEGReader
{
public:
  /**
   * @brief Reads a JPEG image from the specified path.
   * @param path Path to the JPEG image as a C-style string.
   * @return JPEGImage object containing the read image data.
   */
  static JPEGImage
  read(const char* path);

  /**
   * @brief Reads a JPEG image from the specified path.
   * @param path Path to the JPEG image as a string view.
   * @return JPEGImage object containing the read image data.
   */
  static JPEGImage
  read(std::string_view path);

  /**
   * @brief Reads a JPEG image from the specified path.
   * @param path Path to the JPEG image as a string.
   * @return JPEGImage object containing the read image data.
   */
  static JPEGImage
  read(const std::string& path);
};
} // namespace imageutils

#endif