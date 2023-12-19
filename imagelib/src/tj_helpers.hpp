#pragma once

extern "C"
{
#include <turbojpeg.h>
}
#include <memory>

namespace imagelib
{
using unique_tjhandle = std::unique_ptr<std::remove_pointer<tjhandle>::type, decltype(&tjDestroy)>;

unique_tjhandle
make_compressor()
{
  return unique_tjhandle(tjInitCompress(), tjDestroy);
}

unique_tjhandle
make_decompressor()
{
  return unique_tjhandle(tjInitDecompress(), tjDestroy);
}

}  // namespace imagelib
