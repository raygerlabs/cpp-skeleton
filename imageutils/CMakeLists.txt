cmake_minimum_required(VERSION 3.15)
project(imageutils VERSION 1.0 LANGUAGES CXX)

option(BUILD_SHARED_LIBS   "Build shared libraries"   OFF)
if(WIN32)
    set(BUILD_STATIC_LIBS OFF)
else(WIN32)
    option(BUILD_STATIC_LIBS "Build static libraries" OFF)
endif(WIN32)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build")
endif (NOT CMAKE_BUILD_TYPE)

option(ENABLE_TESTS         "Enable unit tests"                   OFF)
option(ENABLE_BENCHMARKS    "Enable benchmarks"                   OFF)
option(ENABLE_EXAMPLES      "Enable examples"                     OFF)
option(ENABLE_DOCUMENTATION "Enable API documentation"            OFF)
option(ENABLE_ASAN          "Enable address sanitizer"            OFF)
option(ENABLE_LSAN          "Enable leak sanitizer"               OFF)
option(ENABLE_MSAN          "Enable memory sanitizer"             OFF)
option(ENABLE_TSAN          "Enable thread sanitizer"             OFF)
option(ENABLE_UBSAN         "Enable undefined sanitizer"          OFF)
option(ENABLE_CCACHE        "Enable ccache"                       OFF)
option(ENABLE_CPPCHECK      "Enable cppcheck"                     OFF)
option(ENABLE_CLANG_FORMAT  "Enable clang-format"                 OFF)
option(ENABLE_CLANG_TIDY    "Enable clang-tidy"                   OFF)

include(cmake/BuildPaths.cmake)
include(cmake/InstallPaths.cmake)
include(cmake/SearchPaths.cmake)

include(cmake/BuildConfig.cmake)
include(cmake/CCacheConfig.cmake)
include(cmake/Sanitizer.cmake)

if (ENABLE_DOCUMENTATION)
    add_subdirectory(docs)
    return()
endif(ENABLE_DOCUMENTATION)

add_subdirectory(src)

if (ENABLE_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif (ENABLE_TESTS)

if (ENABLE_EXAMPLES)
   add_subdirectory(examples)
endif (ENABLE_EXAMPLES)

if (ENABLE_BENCHMARKS)
    enable_testing()
    add_subdirectory(benchmarks)
endif (ENABLE_BENCHMARKS)

include(cmake/CPackConfig.cmake)

