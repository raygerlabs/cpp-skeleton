message(STATUS "Executing toolchain-msvc.cmake!")

set(CMAKE_C_COMPILER "cl")
set(CMAKE_CXX_COMPILER "cl")

set(CMAKE_USER_MAKE_RULES_OVERRIDE "${CMAKE_CURRENT_LIST_DIR}/overrides-msvc.cmake")
