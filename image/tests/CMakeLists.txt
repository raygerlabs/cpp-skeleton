add_executable(unit_tests)
target_sources(unit_tests
PRIVATE
  image_tests.cpp
  path_helpers.hpp
)
target_include_directories(unit_tests
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)
find_package(GTest CONFIG REQUIRED)
target_link_libraries(unit_tests
  GTest::gtest 
  GTest::gtest_main 
  ${PROJECT_NAME}::${PROJECT_NAME}
)
include(CTest)
include(GoogleTest)
gtest_discover_tests(unit_tests)

