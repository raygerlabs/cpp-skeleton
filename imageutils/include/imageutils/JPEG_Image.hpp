#pragma once

#include <cstdint>

#include <string>
#include <vector>

namespace imageutils
{
/**
 * @brief Class representing a JPEG Image
 */
class JPEG_Image
{
public:
  /**
   * @brief Type aliases for pixel data and image characteristics
   */
  using PixelData = std::uint8_t;
  using PixelPointer = PixelData*;
  using ConstPixelPointer = const PixelData*;
  using PixelReference = PixelData&;
  using ConstPixelReference = const PixelData&;
  using PixelVector = std::vector<PixelData>;
  using PixelColor = float;
  using SizeType = std::size_t;

  /**
   * @brief Default constructor
   */
  JPEG_Image() = default;

  /**
   * @brief Constructor to open an image from a file
   * @param filename The path to the image file
   */
  explicit JPEG_Image(const std::string& filename);

  /**
   * @brief Constructor to create a new image with specified dimensions and channels
   * @param width The width of the image
   * @param height The height of the image
   * @param channels The number of color channels (default: 3)
   */
  JPEG_Image(SizeType width, SizeType height, SizeType channels = 3);

  /**
   * @brief Copy constructor
   * @param other The JPEG_Image object to be copied
   */
  JPEG_Image(const JPEG_Image& other) = default;

  /**
   * @brief Copy assignment operator
   * @param other The JPEG_Image object to be assigned
   * @return Reference to the assigned object
   */
  JPEG_Image&
  operator=(const JPEG_Image& other) = default;

  /**
   * @brief Move constructor
   * @param other The JPEG_Image object to be moved
   */
  JPEG_Image(JPEG_Image&& other) noexcept = default;

  /**
   * @brief Move assignment operator
   * @param other The JPEG_Image object to be moved
   * @return Reference to the assigned object
   */
  JPEG_Image&
  operator=(JPEG_Image&& other) noexcept = default;

  /**
   * @brief Destructor
   */
  ~JPEG_Image() = default;

  /**
   * @brief Conversion operator to check if the image is open
   * @return true if the image is open, false otherwise
   */
  operator bool() const noexcept;

  /**
   * @brief Check if the image is open
   * @return true if the image is open, false otherwise
   */
  bool
  is_open() const noexcept;

  /**
   * @brief Get the width of the image
   * @return The width of the image
   */
  constexpr SizeType
  width() const noexcept
  {
    return m_width;
  }

  /**
   * @brief Get the height of the image
   * @return The height of the image
   */
  constexpr SizeType
  height() const noexcept
  {
    return m_height;
  }

  /**
   * @brief Get the number of color channels in the image
   * @return The number of color channels
   */
  constexpr SizeType
  channels() const noexcept
  {
    return m_channels;
  }

  /**
   * @brief Get a mutable reference to the pixel at coordinates (x, y)
   * @param x The x-coordinate of the pixel
   * @param y The y-coordinate of the pixel
   * @return Reference to the pixel data
   */
  // PixelReference
  // getPixel(SizeType x, SizeType y) noexcept;

  /**
   * @brief Get an immutable reference to the pixel at coordinates (x, y)
   * @param x The x-coordinate of the pixel
   * @param y The y-coordinate of the pixel
   * @return Immutable reference to the pixel data
   */
  // ConstPixelReference
  // getPixel(SizeType x, SizeType y) const noexcept;

  /**
   * @brief Set the pixel at coordinates (x, y) with the provided pixel value
   * @param x The x-coordinate of the pixel
   * @param y The y-coordinate of the pixel
   * @param pixel The pixel value to set
   */
  // void
  // setPixel(SizeType x, SizeType y, PixelData pixel) noexcept;

  /**
   * @brief Get the color value of the specified channel at coordinates (x, y)
   * @param x The x-coordinate of the pixel
   * @param y The y-coordinate of the pixel
   * @param channel The color channel index
   * @return The color value of the specified channel
   */
  PixelColor
  getPixelColor(SizeType x, SizeType y, SizeType channel) const noexcept;

  /**
   * @brief Set the color value of the specified channel at coordinates (x, y)
   * @param x The x-coordinate of the pixel
   * @param y The y-coordinate of the pixel
   * @param channel The color channel index
   * @param color The color value to set
   */
  void
  setPixelColor(SizeType x, SizeType y, SizeType channel, PixelColor color) noexcept;

  /**
   * @brief Open an image file and load its data
   * @param filename The path to the image file
   * @return true if successful, false otherwise
   */
  bool
  open(const std::string& filename);

  /**
   * @brief Save the image data to a file with specified quality
   * @param filename The path to save the image
   * @param quality The quality of the saved image (default: 75)
   * @return true if successful, false otherwise
   */
  bool
  save(const std::string& filename, int quality = 75);

  /**
   * @brief Close the image, releasing any resources
   */
  void
  close();

private:
  PixelVector m_data;  /**< Container for pixel data */
  SizeType m_width;    /**< Width of the image */
  SizeType m_height;   /**< Height of the image */
  SizeType m_channels; /**< Number of color channels */
};
} // namespace imageutils
