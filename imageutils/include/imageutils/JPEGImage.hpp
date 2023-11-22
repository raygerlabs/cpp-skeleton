#ifndef IMAGEUTILS_JPEGIMAGE_HPP
#define IMAGEUTILS_JPEGIMAGE_HPP

#pragma once

#include <vector>

namespace imageutils
{
/**
 * @brief Represents the color of a single pixel, encompassing red, green, blue,
 * and alpha channels.
 */
union PixelColor
{
  uint8_t value;
  struct
  {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
  };
};

/**
 * @brief Enumerates various image formats.
 */
enum class PixelFormat : uint8_t
{
  GRAYSCALE = 1, /**< Grayscale image format. */
  RGB = 3        /**< RGB image format. */
};

/**
 * @brief Represents an image along with its pixel data and associated metadata.
 */
class JPEGImage
{
public:
  using PixelDataType = PixelColor;                  /**< Type representing individual pixels. */
  using PixelDataPointer = PixelColor*;              /**< Pointer to pixel data. */
  using ConstPixelDataPointer = const PixelColor*;   /**< Constant pointer to pixel data. */
  using PixelDataReference = PixelColor&;            /**< Reference to pixel data. */
  using ConstPixelDataReference = const PixelColor&; /**< Constant reference to pixel data. */
  using SizeType = std::size_t;                      /**< Type representing size-related values. */

  /**
   * @brief Default constructor creating an empty image with the default format
   * RGBA.
   */
  JPEGImage();

  /**
   * @brief Constructor creating an image with specified width, height, and
   * format.
   * @param width Width of the image.
   * @param height Height of the image.
   * @param format Format of the image (default: RGB).
   */
  explicit JPEGImage(SizeType width, SizeType height, PixelFormat format = PixelFormat::RGB);

  /**
   * @brief Copy constructor.
   * @param other Another JPEGImage object to copy from.
   */
  JPEGImage(const JPEGImage& other);

  /**
   * @brief Move constructor.
   * @param other Another JPEGImage object to move from.
   */
  JPEGImage(JPEGImage&& other) noexcept;

  /**
   * @brief Default destructor.
   */
  ~JPEGImage();

  /**
   * @brief Copy assignment operator.
   * @param other Another JPEGImage object to copy from.
   * @return Reference to the assigned JPEGImage object.
   */
  JPEGImage&
  operator=(const JPEGImage&);

  /**
   * @brief Move assignment operator.
   * @param other Another JPEGImage object to move from.
   * @return Reference to the assigned JPEGImage object.
   */
  JPEGImage&
  operator=(JPEGImage&&) noexcept;

  /**
   * @brief Conversion to boolean operator indicating if the image is valid.
   * @return True if the image is valid, false otherwise.
   */
  operator bool() const noexcept;

  /**
   * @brief Retrieves a reference to the pixel at the specified coordinates.
   * @param x X-coordinate.
   * @param y Y-coordinate.
   * @return Reference to the pixel at the given coordinates.
   */
  PixelDataReference
  operator()(SizeType x, SizeType y) noexcept;

  /**
   * @brief Retrieves a constant reference to the pixel at the specified
   * coordinates.
   * @param x X-coordinate.
   * @param y Y-coordinate.
   * @return Constant reference to the pixel at the given coordinates.
   */
  ConstPixelDataReference
  operator()(SizeType x, SizeType y) const noexcept;

  /**
   * @brief Retrieves a pointer to the beginning of the pixel data.
   * @return Pointer to the beginning of the pixel data.
   */
  PixelDataPointer
  begin() noexcept;

  /**
   * @brief Retrieves a constant pointer to the beginning of the pixel data.
   * @return Constant pointer to the beginning of the pixel data.
   */
  ConstPixelDataPointer
  begin() const noexcept;

  /**
   * @brief Retrieves a pointer to the end of the pixel data.
   * @return Pointer to the end of the pixel data.
   */
  PixelDataPointer
  end() noexcept;

  /**
   * @brief Retrieves a constant pointer to the end of the pixel data.
   * @return Constant pointer to the end of the pixel data.
   */
  ConstPixelDataPointer
  end() const noexcept;

  /**
   * @brief Retrieves a pointer to the underlying pixel data.
   * @return Pointer to the pixel data.
   */
  PixelDataPointer
  data() noexcept;

  /**
   * @brief Retrieves a constant pointer to the underlying pixel data.
   * @return Constant pointer to the pixel data.
   */
  ConstPixelDataPointer
  data() const noexcept;

  /**
   * @brief Checks if the image is empty.
   * @return True if the image is empty, false otherwise.
   */
  bool
  isEmpty() const noexcept;

  /**
   * @brief Retrieves the width of the image.
   * @return Width of the image.
   */
  constexpr SizeType
  getWidth() const noexcept;

  /**
   * @brief Retrieves the height of the image.
   * @return Height of the image.
   */
  constexpr SizeType
  getHeight() const noexcept;

  /**
   * @brief Retrieves the pixel format of the image.
   * @return Pixel format of the image (either: GRAYSCALE or RGB).
   */
  constexpr PixelFormat
  getFormat() const noexcept;

  /**
   * @brief Retrieves a reference to the pixel at the specified coordinates.
   * @param x X-coordinate.
   * @param y Y-coordinate.
   * @return Reference to the pixel at the given coordinates.
   */
  PixelDataReference
  getPixel(SizeType x, SizeType y) noexcept;

  /**
   * @brief Retrieves a constant reference to the pixel at the specified
   * coordinates.
   * @param x X-coordinate.
   * @param y Y-coordinate.
   * @return Constant reference to the pixel at the given coordinates.
   */
  ConstPixelDataReference
  getPixel(SizeType x, SizeType y) const noexcept;

  /**
   * @brief Sets the pixel at the specified coordinates to the provided value.
   * @param x X-coordinate.
   * @param y Y-coordinate.
   * @param value Pixel value to be set.
   * @return Reference to the modified JPEGImage object.
   */
  JPEGImage&
  setPixel(SizeType x, SizeType y, ConstPixelDataReference value);

  /**
   * @brief Reserves memory for the image with specified width, height, and
   * format.
   * @param width Width of the image.
   * @param height Height of the image.
   * @param format Format of the image (default: RGB).
   */
  void
  reserve(SizeType width, SizeType height, PixelFormat format = PixelFormat::RGB);

  /**
   * @brief Clears the image data, making it empty.
   */
  void
  clear() noexcept;

  /**
   * @brief Resizes the image to the specified width, height, and format.
   * @param width Width of the image.
   * @param height Height of the image.
   * @param format Format of the image (default: RGB).
   */
  void
  resize(SizeType width, SizeType height, PixelFormat format = PixelFormat::RGB);

  /**
   * @brief Swaps the content of this JPEGImage object with another JPEGImage
   * object.
   * @param other JPEGImage object to swap content with.
   */
  void
  swap(JPEGImage& other) noexcept;

private:
  std::vector<PixelDataType> data_; /**< Storage for pixel data. */
  SizeType width_;                  /**< Width of the image. */
  SizeType height_;                 /**< Height of the image. */
  PixelFormat format_;              /**< Format of the image. */
};

inline JPEGImage::JPEGImage() : data_(), width_(), height_(), format_(PixelFormat::RGB) {}

inline JPEGImage::JPEGImage(SizeType width, SizeType height, PixelFormat format)
    : data_(width * height), width_(width), height_(height), format_(format)
{
}

inline JPEGImage::JPEGImage(const JPEGImage& other)
    : data_(other.data_), width_(other.width_), height_(other.height_), format_(other.format_)
{
}

inline JPEGImage::JPEGImage(JPEGImage&& other) noexcept
    : data_(std::move(other.data_)), width_(other.width_), height_(other.height_), format_(other.format_)
{
}

inline JPEGImage::~JPEGImage() = default;

inline JPEGImage&
JPEGImage::operator=(const JPEGImage& other)
{
  data_ = other.data_;
  width_ = other.width_;
  height_ = other.height_;
  format_ = other.format_;
  return *this;
}

inline JPEGImage&
JPEGImage::operator=(JPEGImage&& other) noexcept
{
  data_ = std::move(other.data_);
  width_ = other.width_;
  height_ = other.height_;
  format_ = other.format_;
  return *this;
}

inline JPEGImage::operator bool() const noexcept { return !isEmpty(); }

inline typename JPEGImage::PixelDataReference
JPEGImage::operator()(SizeType x, SizeType y) noexcept
{
  return getPixel(x, y);
}

inline typename JPEGImage::ConstPixelDataReference
JPEGImage::operator()(SizeType x, SizeType y) const noexcept
{
  return getPixel(x, y);
}

inline typename JPEGImage::PixelDataPointer
JPEGImage::begin() noexcept
{
  return data();
}

inline typename JPEGImage::ConstPixelDataPointer
JPEGImage::begin() const noexcept
{
  return data();
}

inline typename JPEGImage::PixelDataPointer
JPEGImage::end() noexcept
{
  return data() + data_.size();
}

inline typename JPEGImage::ConstPixelDataPointer
JPEGImage::end() const noexcept
{
  return data() + data_.size();
}

inline typename JPEGImage::PixelDataPointer
JPEGImage::data() noexcept
{
  return data_.data();
}

inline typename JPEGImage::ConstPixelDataPointer
JPEGImage::data() const noexcept
{
  return data_.data();
}

inline bool
JPEGImage::isEmpty() const noexcept
{
  return data_.empty();
}

inline constexpr typename JPEGImage::SizeType
JPEGImage::getWidth() const noexcept
{
  return width_;
}

inline constexpr typename JPEGImage::SizeType
JPEGImage::getHeight() const noexcept
{
  return height_;
}

inline typename JPEGImage::PixelDataReference
JPEGImage::getPixel(SizeType x, SizeType y) noexcept
{
  return data_[y * width_ + x];
}

inline typename JPEGImage::ConstPixelDataReference
JPEGImage::getPixel(SizeType x, SizeType y) const noexcept
{
  return data_[y * width_ + x];
}

inline JPEGImage&
JPEGImage::setPixel(SizeType x, SizeType y, ConstPixelDataReference value)
{
  getPixel(x, y) = value;
  return *this;
}

inline constexpr PixelFormat
JPEGImage::getFormat() const noexcept
{
  return format_;
}

inline void
JPEGImage::reserve(SizeType width, SizeType height, PixelFormat format)
{
  data_.reserve(width * height);
  width_ = width;
  height_ = height;
  format_ = format;
}

inline void
JPEGImage::clear() noexcept
{
  data_.clear();
  width_ = height_ = 0;
}

inline void
JPEGImage::resize(SizeType width, SizeType height, PixelFormat format)
{
  data_.resize(width * height);
  width_ = width;
  height_ = height;
  format_ = format;
}

inline void
JPEGImage::swap(JPEGImage& other) noexcept
{
  std::swap(data_, other.data_);
  std::swap(width_, other.width_);
  std::swap(height_, other.height_);
  std::swap(format_, other.format_);
}

} // namespace imageutils

#endif