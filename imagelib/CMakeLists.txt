cmake_minimum_required(VERSION 3.22)

# Set project name and version number
file(STRINGS "name.txt" PROJECT_NAME)
file(STRINGS "version.txt" PROJECT_VERSION)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION})

# Set default project configuration
include(${CMAKE_SOURCE_DIR}/cmake/Configure.cmake)

# Add library code
add_subdirectory(src)

# Add unit tests
option(WITH_TESTS "Enable unit tests" OFF)
if (WITH_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif (WITH_TESTS)
