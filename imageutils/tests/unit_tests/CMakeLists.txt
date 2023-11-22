set(_TEST_SOURCES
  JPEGImageFilterTests.cpp
  JPEGProcessorTests.cpp
  JPEGReaderTests.cpp
  JPEGWriterTests.cpp
)

add_executable(unit_tests ${_TEST_SOURCES})
set_target_properties(unit_tests PROPERTIES FOLDER "Tests")
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${_TEST_SOURCES})

add_custom_command(
  TARGET unit_tests PRE_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
  ${CMAKE_CURRENT_SOURCE_DIR}/../../resources
  ${CMAKE_CURRENT_BINARY_DIR}/resources
)

find_package(GTest CONFIG REQUIRED)
target_link_libraries(unit_tests
  GTest::gtest
  GTest::gtest_main
  imageutils
)

gtest_discover_tests(unit_tests)
