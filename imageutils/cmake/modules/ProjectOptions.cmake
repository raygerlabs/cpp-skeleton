include_guard(GLOBAL)

option(WITH_CCACHE "Build with ccache to speed up compilation process" ON)

option(WITH_TESTS "Build with unit tests" OFF)
option(WITH_COVERAGE "Build with code coverage" OFF)
option(WITH_BENCHMARKS "Build with performance benchmarks" OFF)

option(WITH_DOC "Build with documentation" OFF)

option(WITH_ASAN "Build with address sanitizer" OFF)
option(WITH_LSAN "Build with leak sanitizer" OFF)
option(WITH_MSAN "Build with memory sanitizer" OFF)
option(WITH_TSAN "Build with thread sanitizer" OFF)
option(WITH_UBSAN "Build with undefined behavior sanitizer" OFF)

option(WITH_CPPCHECK "Build with cppcheck static analysis tool" OFF)
option(WITH_TIDY "Build with clang-tidy static analysis tool" OFF)
