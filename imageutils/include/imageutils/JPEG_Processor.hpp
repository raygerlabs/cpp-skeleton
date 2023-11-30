#pragma once

#include "imageutils/JPEG_Filter.hpp" // Including the JPEG_Filter header
#include <vector>

namespace imageutils
{
/**
 * @brief Class responsible for applying a series of filters to a JPEG image
 *
 * The JPEG_Processor class applies a sequence of filters to a JPEG image.
 * Filters are functions that take a JPEG_Image and return a modified JPEG_Image.
 */
class JPEG_Processor
{
public:
  /**
   * @brief Adds a filter to the processor.
   * @param filter The filter to add.
   * @return Reference to the current JPEG_Processor object.
   */
  JPEG_Processor&
  add(const JPEG_Filter& filter);

  /**
   * @brief Emplaces a filter into the processor.
   * @param filter The filter to add using move semantics.
   * @return Reference to the current JPEG_Processor object.
   */
  JPEG_Processor&
  emplace(JPEG_Filter&& filter) noexcept;

  /**
   * @brief Applies all added filters to the input image.
   * @param input The input JPEG image to process.
   * @return The resulting processed JPEG image after applying all filters.
   */
  JPEG_Image
  apply(const JPEG_Image& input);

  /**
   * @brief Clears all filters from the processor.
   */
  void
  clear() noexcept;

private:
  std::vector<JPEG_Filter> m_filters; ///< Vector storing the sequence of filters.
};

// Implementation of member functions inline for simplicity

inline JPEG_Processor&
JPEG_Processor::add(const JPEG_Filter& filter)
{
  m_filters.push_back(filter);
  return *this;
}

inline JPEG_Processor&
JPEG_Processor::emplace(JPEG_Filter&& filter) noexcept
{
  m_filters.emplace_back(std::move(filter));
  return *this;
}

inline JPEG_Image
JPEG_Processor::apply(const JPEG_Image& input)
{
  JPEG_Image result(input);
  for (const auto& filter : m_filters)
  {
    result = filter(result);
  }
  return result;
}

inline void
JPEG_Processor::clear() noexcept
{
  m_filters.clear();
}

} // namespace imageutils