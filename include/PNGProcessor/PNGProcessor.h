#pragma once

#include <string_view>

namespace raygerlabs
{
bool compress(std::string_view, std::string_view);
bool decompress(std::string_view, std::string_view);
} // namespace raygerlabs
