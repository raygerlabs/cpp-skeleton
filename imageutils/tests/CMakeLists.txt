add_executable(unit_tests
  resource_path.hpp
  image_filter_tests.cpp
  image_processor_tests.cpp
  jpeg_read_tests.cpp
  jpeg_write_tests.cpp
)

target_include_directories(unit_tests
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)

find_package(GTest CONFIG REQUIRED)
target_link_libraries(unit_tests
    GTest::gtest 
    GTest::gtest_main 
    imageutils
)

target_enable_sanitizing(unit_tests)

add_custom_command( TARGET unit_tests
    PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/resources/ $<TARGET_FILE_DIR:unit_tests>/resources/
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/resources/ ${CMAKE_BINARY_DIR}/resources/
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/resources/ ${CMAKE_CURRENT_BINARY_DIR}/resources/
)

include(CTest)
include(GoogleTest)
gtest_discover_tests(unit_tests)

