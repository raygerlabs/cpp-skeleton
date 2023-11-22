#include "imageutils/JPEGProcessor.hpp"
#include "imageutils/JPEGImage.hpp"


namespace imageutils {
JPEGProcessor&
JPEGProcessor::add(const FilterType& filter) noexcept
{
  filters_.push_back(filter);
  return *this;
}

JPEGProcessor&
JPEGProcessor::emplace(FilterType&& filter) noexcept
{
  filters_.emplace_back(std::move(filter));
  return *this;
}

JPEGImage
JPEGProcessor::apply(const JPEGImage& input) noexcept
{
  JPEGImage output(input);
  for (const auto filter : filters_) {
    output = filter(output);
  }
  return output;
}

void
JPEGProcessor::clear() noexcept
{
  filters_.clear();
}
} // namespace imageutils