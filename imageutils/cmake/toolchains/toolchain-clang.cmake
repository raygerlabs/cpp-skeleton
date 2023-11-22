message(STATUS "Executing toolchain-clang.cmake!")

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

set(CMAKE_CONFIGURATION_TYPES Debug Profile Release)

set(CMAKE_USER_MAKE_RULES_OVERRIDE "${CMAKE_CURRENT_LIST_DIR}/overrides-clang.cmake")
