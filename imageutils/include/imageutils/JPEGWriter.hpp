#ifndef IMAGEUTILS_JPEGWRITER_HPP
#define IMAGEUTILS_JPEGWRITER_HPP

#pragma once

#include <string>
#include <string_view>

namespace imageutils
{
// Forward declarations
union PixelColor;
class JPEGImage;

/**
 * @brief Class responsible for writing JPEG images.
 */
class JPEGWriter
{
public:
  /**
   * @brief Writes a JPEG image to the specified path.
   * @param input JPEG_Image object to be written.
   * @param path Path to write the JPEG image as a C-style string.
   * @param imageQuality Quality level of the JPG image.
   * @return True if the write operation was successful, false otherwise.
   */
  static bool
  write(const JPEGImage& input, const char* path, int imageQuality = 100);

  /**
   * @brief Writes a JPEG image to the specified path.
   * @param input JPEG_Image object to be written.
   * @param path Path to write the JPEG image as a string view.
   * @param imageQuality Quality level of the JPG image.
   * @return True if the write operation was successful, false otherwise.
   */
  static bool
  write(const JPEGImage& input, std::string_view path, int imageQuality = 100);

  /**
   * @brief Writes a JPEG image to the specified path.
   * @param input JPEG_Image object to be written.
   * @param path Path to write the JPEG image as a string.
   * @param imageQuality Quality level of the JPG image.
   * @return True if the write operation was successful, false otherwise.
   */
  static bool
  write(const JPEGImage& input, const std::string& path, int imageQuality = 100);
};
} // namespace imageutils

#endif