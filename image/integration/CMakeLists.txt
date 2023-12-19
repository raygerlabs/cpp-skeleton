cmake_minimum_required(VERSION 3.22)
project(integration)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(integration integration.cpp)
find_package(image CONFIG REQUIRED)
target_link_libraries(integration image::image)
