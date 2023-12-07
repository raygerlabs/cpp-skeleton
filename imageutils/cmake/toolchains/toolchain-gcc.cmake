include_guard()

# Set C and C++ compilers
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

# Adjust the default behaviour of the FIND_XXX() commands
set (CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set (CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set (CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set (CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

# Override default compiler and linker flags
include(${CMAKE_CURRENT_LIST_DIR}/overrides-gcc.cmake)

# Output system information
message(STATUS "CMAKE_SYSTEM_NAME = ${CMAKE_SYSTEM_NAME}")
message(STATUS "CMAKE_SYSTEM_PROCESSOR = ${CMAKE_SYSTEM_PROCESSOR}")
# Output compiler and linker information
foreach (_lang IN ITEMS "C" "CXX")
    message(STATUS "CMAKE_${_lang}_COMPILER = ${CMAKE_${_lang}_COMPILER}")
    message(STATUS "CMAKE_${_lang}_LINKER = ${CMAKE_${_lang}_LINKER}")
endforeach()
# Output compiler flags for different build types
foreach (_lang IN ITEMS "C" "CXX")
    foreach (_build_type IN ITEMS "" "_DEBUG" "_RELEASE" "_RELWITHDEBINFO" "_RELEASE")
        message(STATUS "CMAKE_${_lang}_FLAGS${_build_type} = ${CMAKE_${_lang}_FLAGS${_build_type}}")
    endforeach()
endforeach()
# Output linker flags for different build types
foreach (_linker IN ITEMS "EXE" "SHARED" "MODULE" "STATIC")
    foreach (_build_type IN ITEMS "" "_DEBUG" "_RELEASE" "_RELWITHDEBINFO" "_RELEASE")
        message(STATUS "CMAKE_${_linker}_LINKER_FLAGS${_build_type} = ${CMAKE_${_linker}_LINKER_FLAGS${_build_type}}")
    endforeach()
endforeach()
