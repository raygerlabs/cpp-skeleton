#ifndef IMAGEUTILS_INTERNAL_JPEG_WRITER_HPP
#define IMAGEUTILS_INTERNAL_JPEG_WRITER_HPP

#pragma once

#include <string>
#include <string_view>

namespace imageutils
{
// Forward declarations
class JPEG_Image;

/**
 * @brief Class responsible for writing JPEG images.
 */
class JPEG_Writer
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
  write(const JPEG_Image& input, const char* path, int imageQuality = 75);

  /**
   * @brief Writes a JPEG image to the specified path.
   * @param input JPEG_Image object to be written.
   * @param path Path to write the JPEG image as a string view.
   * @param imageQuality Quality level of the JPG image.
   * @return True if the write operation was successful, false otherwise.
   */
  static bool
  write(const JPEG_Image& input, std::string_view path, int imageQuality = 75);

  /**
   * @brief Writes a JPEG image to the specified path.
   * @param input JPEG_Image object to be written.
   * @param path Path to write the JPEG image as a string.
   * @param imageQuality Quality level of the JPG image.
   * @return True if the write operation was successful, false otherwise.
   */
  static bool
  write(const JPEG_Image& input, const std::string& path, int imageQuality = 75);
};
} // namespace imageutils

#endif // IMAGEUTILS_INTERNAL_JPEG_WRITER_HPP