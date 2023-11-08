cmake_minimum_required(VERSION 3.23 FATAL_ERROR)
project(PNGProcessor VERSION 1.0.0)

# Fall back to Release build if not explicitly defined
if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

option(ENABLE_TESTS        "Enable the build of the unit tests" OFF)
option(ENABLE_EXAMPLES     "Enable the build of the example projects" OFF)
option(ENABLE_BENCHMARKING "Enable the build of the benchmarks" OFF)
option(ENABLE_ASAN         "Enable address sanitizer (clang/gcc only)" OFF)
option(ENABLE_LSAN         "Enable leak sanitizer (clang/gcc only)" OFF)
option(ENABLE_MSAN         "Enable memory sanitizer (clang/gcc only)" OFF)
option(ENABLE_TSAN         "Enable thread sanitizer (clang/gcc only)" OFF)
option(ENABLE_UBSAN        "Enable UB sanitizer (clang/gcc only)" OFF)
option(ENABLE_COVERAGE     "Enable coverage (clang/gcc only)" OFF)
option(ENABLE_DOC          "Enable API documentation (clang/gcc only)" OFF)
option(ENABLE_PACKAGING    "Enable packaging" OFF)

include(tools/cmake/Init.cmake)
include(tools/cmake/GenerateExportHeaders.cmake)
include(tools/cmake/Coverage.cmake)
include(tools/cmake/Sanitizers.cmake)
include(tools/cmake/Doxygen.cmake)

add_subdirectory(src)
include(${PROJECT_SOURCE_DIR}/tools/cmake/Export.cmake)

if (ENABLE_TESTS)
  include(CTest)
  include(GoogleTest)
  add_subdirectory(tests/unit_tests)
endif()

if (ENABLE_EXAMPLES)
  add_subdirectory(examples)
endif()

#if (ENABLE_INTEGRATION)
#  add_subdirectory(tests/integration)
#endif()

if (ENABLE_BENCHMARKS)
  add_subdirectory(benchmarks)
endif()

if (ENABLE_PACKAGING)
  include(tools/cmake/Packaging.cmake)
endif()
