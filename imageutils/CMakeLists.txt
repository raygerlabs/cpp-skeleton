cmake_minimum_required(VERSION 3.15)

file(STRINGS "VERSION" PROJECT_VERSION)
project(imageutils VERSION ${PROJECT_VERSION})

include(${CMAKE_SOURCE_DIR}/cmake/Configure.cmake)

add_subdirectory(src)

if (WITH_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif (WITH_TESTS)

if (WITH_BENCHMARKS)
  enable_testing()
  add_subdirectory(benchmarks)
endif (WITH_BENCHMARKS)

if (WITH_DOC)
  add_subdirectory(doc)
endif (WITH_DOC)
