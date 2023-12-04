cmake_minimum_required(VERSION 3.15)
project(integration)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(integration integration.cpp)

find_package(imageutils CONFIG REQUIRED)
target_link_libraries(integration imageutils::imageutils)

add_custom_command(
    TARGET integration PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/../resources/ $<TARGET_FILE_DIR:integration>/resources/
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/../resources/ ${CMAKE_BINARY_DIR}/resources/
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/../resources/ ${CMAKE_CURRENT_BINARY_DIR}/resources/
)
