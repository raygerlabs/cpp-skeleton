#ifndef IMAGEUTILS_INTERNAL_JPEG_PROCESSOR_HPP
#define IMAGEUTILS_INTERNAL_JPEG_PROCESSOR_HPP

#pragma once

#include "imageutils/internal/JPEG_Filter.hpp"

#include <functional>
#include <vector>

namespace imageutils
{
/**
 * @brief Class responsible for processing JPEG images with filters.
 */
class JPEG_Processor
{
public:
  using FilterType = JPEG_Filter;
  /**
   * @brief Adds a filter function to the processor.
   * @param filter Filter function to be added.
   * @return Reference to the modified JPEGProcessor object.
   */
  JPEG_Processor&
  add(const FilterType& filter);

  /**
   * @brief Emplaces a filter function to the processor.
   * @param filter Filter function to be emplaced.
   * @return Reference to the modified JPEGProcessor object.
   */
  JPEG_Processor&
  emplace(FilterType&& filter) noexcept;

  /**
   * @brief Applies the filters from the input processor to the current processor.
   * @param input Input JPEGProcessor object containing filters to be applied.
   * @return New JPEGProcessor object after applying the filters.
   */
  JPEG_Image
  apply(const JPEG_Image& input);

  /**
   * @brief Clears all filters from the processor.
   */
  void
  clear() noexcept;

private:
  std::vector<FilterType> filters_; /**< Vector containing filter functions. */
};

inline JPEG_Processor&
JPEG_Processor::add(const FilterType& filter)
{
  filters_.push_back(filter);
  return *this;
}

inline JPEG_Processor&
JPEG_Processor::emplace(FilterType&& filter) noexcept
{
  filters_.emplace_back(std::move(filter));
  return *this;
}

inline JPEG_Image
JPEG_Processor::apply(const JPEG_Image& input)
{
  JPEG_Image result(input);
  for (const auto filter : filters_)
  {
    result = filter(result);
  }
  return result;
}

inline void
JPEG_Processor::clear() noexcept
{
  filters_.clear();
}

} // namespace imageutils

#endif // IMAGEUTILS_INTERNAL_JPEG_PROCESSOR_HPP