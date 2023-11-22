cmake_minimum_required(VERSION 3.15)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

if(USE_CCACHE)
  find_program(CCACHE_FOUND ccache)
  if(CCACHE_FOUND)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
  endif(CCACHE_FOUND)
endif()

option(ENABLE_TESTS        "Enable unit tests"        OFF)
option(ENABLE_BENCHMARKS   "Enable benchmarks"        OFF)
option(ENABLE_EXAMPLES     "Enable examples"          OFF)
option(ENABLE_SANITIZERS   "Enable sanitizers"        OFF)
option(ENABLE_COVERAGE     "Enable code coverage"     OFF)
option(ENABLE_DOCS         "Enable documentation"     OFF)
option(ENABLE_PACKAGE      "Enable packaging support" OFF)
option(ENABLE_CCACHE       "Enable ccache"            OFF)

project(imageutils VERSION 1.0)

include(cmake/Init.cmake)
include(cmake/Sanitizing.cmake)
include(cmake/Coverage.cmake)

if (ENABLE_DOCS)
  add_subdirectory(docs)
endif()

add_subdirectory(src)

if (ENABLE_TESTS)
  list(APPEND CMAKE_CTEST_ARGUMENTS "--output-on-failure")
  include(CTest)
  include(GoogleTest)
  add_subdirectory(tests/unit_tests)
endif()

if (ENABLE_EXAMPLES)
  add_subdirectory(examples)
endif()

if (ENABLE_BENCHMARKS)
  add_subdirectory(benchmarks)
endif()

if (ENABLE_PACKAGE)
  include(cmake/Packaging.cmake)
endif()
