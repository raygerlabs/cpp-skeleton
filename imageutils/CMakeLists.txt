cmake_minimum_required(VERSION 3.15)
project(imageutils VERSION 1.0)

# Options
option(BUILD_SHARED_LIBS   "Build shared libraries"   OFF)
if(WIN32)
  set(BUILD_STATIC_LIBS OFF)
else(WIN32)
  option(BUILD_STATIC_LIBS "Build static libraries" OFF)
endif(WIN32)

# Build types
if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build")
endif()

# Features
option(ENABLE_PCH          "Enable precompiled headers"          OFF)
option(ENABLE_TESTS        "Enable unit tests"                   OFF)
option(ENABLE_BENCHMARKS   "Enable benchmarks"                   OFF)
option(ENABLE_EXAMPLES     "Enable examples"                     OFF)
option(ENABLE_COVERAGE     "Enable code coverage"                OFF)
option(ENABLE_DOXYGEN      "Enable doxygen"                      OFF)

option(ENABLE_ASAN         "Enable address sanitizer"            OFF)
option(ENABLE_LSAN         "Enable leak sanitizer"               OFF)
option(ENABLE_MSAN         "Enable memory sanitizer"             OFF)
option(ENABLE_TSAN         "Enable thread sanitizer"             OFF)
option(ENABLE_UBSAN        "Enable undefined behavior sanitizer" OFF)

option(ENABLE_CCACHE       "Enable ccache"                       OFF)
option(ENABLE_CPPCHECK     "Enable cppcheck"                     OFF)
option(ENABLE_CLANG_FORMAT "Enable clang-format"                 OFF)
option(ENABLE_CLANG_TIDY   "Enable clang-tidy"                   OFF)

include(cmake/Init.cmake)
include(cmake/Coverage.cmake)
include(cmake/Sanitize.cmake)

if (ENABLE_DOXYGEN)
  add_subdirectory(docs)
endif()

add_subdirectory(src)

if (ENABLE_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()

if (ENABLE_EXAMPLES)
  add_subdirectory(examples)
endif()

if (ENABLE_BENCHMARKS)
  add_subdirectory(benchmarks)
endif()

include(cmake/CPackConfig.cmake)

