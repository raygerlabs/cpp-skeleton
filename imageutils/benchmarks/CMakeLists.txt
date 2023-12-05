add_executable(benchmarks benchmarks.cpp)

find_package(benchmark CONFIG REQUIRED)
target_link_libraries(benchmarks
    benchmark::benchmark
    benchmark::benchmark_main
    imageutils
)

add_custom_command(TARGET benchmarks
    PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/resources/ $<TARGET_FILE_DIR:benchmarks>/resources/
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/resources/ ${CMAKE_BINARY_DIR}/resources/
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/resources/ ${CMAKE_CURRENT_BINARY_DIR}/resources/
)

include(CTest)
add_test(NAME benchmarks COMMAND benchmarks)
