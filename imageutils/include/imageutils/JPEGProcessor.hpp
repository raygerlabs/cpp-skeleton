#ifndef IMAGEUTILS_JPEGPROCESSOR_HPP
#define IMAGEUTILS_JPEGPROCESSOR_HPP

#pragma once

#include "imageutils/JPEGFilter.hpp"

#include <functional>
#include <vector>

namespace imageutils
{
// Forward declarations
union PixelColor;
class JPEGImage;

/**
 * @brief Class responsible for processing JPEG images with filters.
 */
class JPEGProcessor
{
public:
  using FilterType = JPEGFilter;
  /**
   * @brief Adds a filter function to the processor.
   * @param filter Filter function to be added.
   * @return Reference to the modified JPEGProcessor object.
   */
  JPEGProcessor&
  add(const FilterType& filter) noexcept;

  /**
   * @brief Emplaces a filter function to the processor.
   * @param filter Filter function to be emplaced.
   * @return Reference to the modified JPEGProcessor object.
   */
  JPEGProcessor&
  emplace(FilterType&& filter) noexcept;

  /**
   * @brief Applies the filters from the input processor to the current processor.
   * @param input Input JPEGProcessor object containing filters to be applied.
   * @return New JPEGProcessor object after applying the filters.
   */
  JPEGImage
  apply(const JPEGImage& input) noexcept;

  /**
   * @brief Clears all filters from the processor.
   */
  void
  clear() noexcept;

private:
  std::vector<FilterType> filters_; /**< Vector containing filter functions. */
};
} // namespace imageutils

#endif