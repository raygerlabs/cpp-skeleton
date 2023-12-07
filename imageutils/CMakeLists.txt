cmake_minimum_required(VERSION 3.15)

project(imageutils VERSION 1.0)

list(APPEND CMAKE_INCLUDE_PATH ${CMAKE_SOURCE_DIR}/cmake)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/cmake)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()


option(ENABLE_CCACHE      "Enable ccache support"      OFF)
option(ENABLE_TESTS       "Enable unit tests"          OFF)
option(ENABLE_BENCHMARKS  "Enable benchmarks"          OFF)
option(ENABLE_DOC         "Enable API documentation"   OFF)
option(ENABLE_ASAN        "Enable address sanitizer"   OFF)
option(ENABLE_LSAN        "Enable leak sanitizer"      OFF)
option(ENABLE_MSAN        "Enable memory sanitizer"    OFF)
option(ENABLE_TSAN        "Enable thread sanitizer"    OFF)
option(ENABLE_UBSAN       "Enable undefined sanitizer" OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN ON)
set(WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Output CMake search paths
message(STATUS "CMAKE_SYSTEM_INCLUDE_PATH = ${CMAKE_SYSTEM_INCLUDE_PATH}")
message(STATUS "CMAKE_INCLUDE_PATH = ${CMAKE_INCLUDE_PATH}")
message(STATUS "CMAKE_PREFIX_PATH = ${CMAKE_PREFIX_PATH}")
message(STATUS "CMAKE_MODULE_PATH = ${CMAKE_MODULE_PATH}")

# Output CMake build paths
message(STATUS "CMAKE_RUNTIME_OUTPUT_DIRECTORY = ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message(STATUS "CMAKE_LIBRARY_OUTPUT_DIRECTORY = ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
message(STATUS "CMAKE_ARCHIVE_OUTPUT_DIRECTORY = ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")

# Output CMake install paths
message(STATUS "CMAKE_INSTALL_PREFIX = ${CMAKE_INSTALL_PREFIX}")
message(STATUS "CMAKE_INSTALL_INCLUDEDIR = ${CMAKE_INSTALL_BINDIR}")
message(STATUS "CMAKE_INSTALL_LIBDIR = ${CMAKE_INSTALL_LIBDIR}")
message(STATUS "CMAKE_INSTALL_DATAROOTDIR = ${CMAKE_INSTALL_DATAROOTDIR}")
message(STATUS "CMAKE_INSTALL_DATADIR = ${CMAKE_INSTALL_DATADIR}")
message(STATUS "CMAKE_INSTALL_MANDIR = ${CMAKE_INSTALL_MANDIR}")
message(STATUS "CMAKE_INSTALL_DOCDIR = ${CMAKE_INSTALL_DOCDIR}")

include(CCacheConfig)
include(Sanitizer)

add_subdirectory(src)

if (ENABLE_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif (ENABLE_TESTS)

if (ENABLE_BENCHMARKS)
  enable_testing()
  add_subdirectory(benchmarks)
endif (ENABLE_BENCHMARKS)

if (ENABLE_DOC)
  add_subdirectory(doc)
endif()

include(CPackConfig)
