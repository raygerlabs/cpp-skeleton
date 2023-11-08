#include "PNGProcessor/PNGProcessor.h"

#include <gtest/gtest.h>

namespace
{
TEST(PNGProcessorTests, compressNominal)
{
  EXPECT_TRUE(raygerlabs::compress("i", "o"));
}
TEST(PNGProcessorTests, decompressNominal)
{
  EXPECT_TRUE(raygerlabs::decompress("i", "o"));
}
}
