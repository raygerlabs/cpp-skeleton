include_guard(GLOBAL)

# Build the project with "Release" by default
if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Set C language standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF) # Disallow non-compliant extensions

# Set C++ language standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # Disallow non-compliant extensions

# Use position independent code wherever possible
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Make the default ELF symbol visibility "hidden"
set(CMAKE_C_VISIBILITY_PRESET hidden)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN ON)

# Export symbols for shared libraries on Windows
set(WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Generate additional information about the current build settings
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

# Enable virtual folders in your IDE
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Determine the suitable compiler toolchain if
# - No CMake toolchain was provided by the user
# - Conan attempts to intrude with its own :)
set(USE_TOOLCHAIN_OVERRIDE 0)
if (NOT CMAKE_TOOLCHAIN_FILE)
  set(USE_TOOLCHAIN_OVERRIDE 1)
endif (NOT CMAKE_TOOLCHAIN_FILE)
if (CMAKE_TOOLCHAIN_FILE MATCHES "conan_toolchain.cmake")
  set(USE_TOOLCHAIN_OVERRIDE 1)
endif (CMAKE_TOOLCHAIN_FILE MATCHES "conan_toolchain.cmake")

if (USE_TOOLCHAIN_OVERRIDE)
  message(STATUS "Auto-detecting toolchain for the current system...")
  if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    include(${CMAKE_CURRENT_LIST_DIR}/../toolchains/toolchain-msvc.cmake)
  elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
    include(${CMAKE_CURRENT_LIST_DIR}/../toolchains/toolchain-clang.cmake)
  else() # Make GCC as a fallback option
    include(${CMAKE_CURRENT_LIST_DIR}/../toolchains/toolchain-gcc.cmake)
  endif()
endif (USE_TOOLCHAIN_OVERRIDE)

# Build everything under the topmost folder in the build tree, or otherwise we
# must perform copying across targets!
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)

# Set install paths
include(GNUInstallDirs)
