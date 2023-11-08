cmake_minimum_required(VERSION 3.23 FATAL_ERROR)
project(integration)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

list(APPEND CMAKE_PREFIX_PATH ${PROJECT_BINARY_DIR})
list(APPEND CMAKE_MODULE_PATH ${PROJECT_BINARY_DIR})

find_package(PNGProcessor CONFIG REQUIRED)
add_executable(integration integration.cpp)
target_link_libraries(integration PNGProcessor::PNGProcessor)
set_target_properties(integration PROPERTIES FOLDER "Tests")
