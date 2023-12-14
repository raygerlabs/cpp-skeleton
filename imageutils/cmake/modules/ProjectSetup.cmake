include_guard(GLOBAL)

# Build the project with "Release" by default
if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Set language standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # Disallow non-compliant compiler extensions

# Use position independent code wherever possible
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Make the default ELF symbol visibility "hidden"
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN ON)

# Export symbols for shared libraries on Windows
set(WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Generate additional information about the current build settings
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

# Enable virtual folders in your IDE
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Determine toolchain
if (NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  message(STATUS "CMAKE_TOOLCHAIN_FILE was not defined, auto-selecting the best possible toolchain for the current system")
  if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    include(${CMAKE_CURRENT_LIST_DIR}/../toolchains/toolchain-msvc.cmake)
  elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
    include(${CMAKE_CURRENT_LIST_DIR}/../toolchains/toolchain-clang.cmake)
  else() # Make GCC as fallback option
    include(${CMAKE_CURRENT_LIST_DIR}/../toolchains/toolchain-gcc.cmake)
  endif()
else (NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  message(STATUS "CMAKE_TOOLCHAIN_FILE = ${CMAKE_TOOLCHAIN_FILE}")
endif (NOT DEFINED CMAKE_TOOLCHAIN_FILE)

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
