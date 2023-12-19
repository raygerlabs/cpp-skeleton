include_guard(GLOBAL)

# Set compiler toolchain
set(CMAKE_C_COMPILER cl)
set(CMAKE_CXX_COMPILER cl)
set(CMAKE_ASM_COMPILER ml)
set(CMAKE_LINKER link)

# Skip compiler detection info
set(CMAKE_C_COMPILER_FORCED true)
set(CMAKE_CXX_COMPILER_FORCED true)
set(CMAKE_ASM_COMPILER_FORCED true)

# Make the current compiler toolchain our only focus
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

# Override default compiler settings with our own flags
include(${CMAKE_CURRENT_LIST_DIR}/override-msvc.cmake)
