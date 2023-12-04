include_guard()

message(STATUS "CMAKE_BINARY_DIR = ${CMAKE_BINARY_DIR}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
message(STATUS "CMAKE_RUNTIME_OUTPUT_DIRECTORY = ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
message(STATUS "CMAKE_LIBRARY_OUTPUT_DIRECTORY = ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
message(STATUS "CMAKE_ARCHIVE_OUTPUT_DIRECTORY = ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
