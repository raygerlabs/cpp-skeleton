cmake_minimum_required(VERSION 3.15)
project(integration)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(integration integration.cpp)
add_custom_command(
  TARGET integration PRE_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
  ${CMAKE_CURRENT_LIST_DIR}/../../resources
  ${CMAKE_CURRENT_BINARY_DIR}/resources
)
find_package(imageutils CONFIG REQUIRED)
target_link_libraries(integration imageutils::imageutils)
set_target_properties(integration PROPERTIES FOLDER "Tests")
