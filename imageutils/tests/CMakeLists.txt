add_executable(benchmarks benchmarks.cpp)
target_include_directories(benchmarks PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

add_custom_command(
  TARGET unit_tests PRE_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/resources/ $<TARGET_FILE_DIR:unit_tests>/resources/
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/resources/ ${CMAKE_BINARY_DIR}/resources/
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/resources/ ${CMAKE_CURRENT_BINARY_DIR}/resources/
)

find_package(GTest CONFIG REQUIRED)
target_link_libraries(unit_tests GTest::gtest GTest::gtest_main imageutils)

include(CTest)
include(GoogleTest)
gtest_discover_tests(unit_tests)

