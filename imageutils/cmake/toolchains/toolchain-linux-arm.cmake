# arm
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

if (NOT DEFINED CMAKE_C_COMPILER)
  set(CMAKE_C_COMPILER arm-linux-gnueabi-gcc)
endif(NOT DEFINED CMAKE_C_COMPILER)

if (NOT DEFINED CMAKE_CXX_COMPILER)
  set(CMAKE_CXX_COMPILER arm-linux-gnueabi-g++)
endif(NOT DEFINED CMAKE_CXX_COMPILER)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

include(${CMAKE_CURRENT_LIST_DIR}/compilers/toolchain-gcc.cmake)