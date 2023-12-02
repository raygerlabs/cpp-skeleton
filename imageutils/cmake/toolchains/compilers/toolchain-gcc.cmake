message(STATUS "*** loading toolchain-gcc.cmake")

include(${CMAKE_CURRENT_LIST_DIR}/overrides-gcc.cmake)

set(_LANGUAGES C CXX)
set(_BUILD_TYPES "" _DEBUG _RELEASE _MINSIZEREL _RELWITHDEBINFO)
set(_LINK_TYPES EXE STATIC SHARED MODULE)

message(STATUS "CMAKE_SYSTEM_NAME = ${CMAKE_SYSTEM_NAME}")
message(STATUS "CMAKE_SYSTEM_PROCESSOR = ${CMAKE_SYSTEM_PROCESSOR}")

foreach(_LANGUAGE ${_LANGUAGES})
  message(STATUS "CMAKE_${_LANGUAGE}_COMPILER = ${CMAKE_${_LANGUAGE}_COMPILER}")
endforeach()

message(STATUS "CMAKE_LINKER = ${CMAKE_LINKER}")

foreach(_LANGUAGE ${_LANGUAGES})
  message(STATUS "CMAKE_${_LANGUAGE}_LINKER = ${CMAKE_${_LANGUAGE}_LINKER}")
endforeach()

foreach(_LANGUAGE ${_LANGUAGES})
  foreach(_BUILD_TYPE ${_BUILD_TYPES})
    message(STATUS "CMAKE_${_LANGUAGE}_FLAGS${_BUILD_TYPE} = ${CMAKE_${_LANGUAGE}_FLAGS${_BUILD_TYPE}}")
  endforeach()
endforeach()

foreach(_LINK_TYPE ${_LINK_TYPES})
  foreach(_BUILD_TYPE ${_BUILD_TYPES})
    message(STATUS "CMAKE_${_LINK_TYPE}_LINKER_FLAGS${_BUILD_TYPE} = ${CMAKE_${_LINK_TYPE}_LINKER_FLAGS${_BUILD_TYPE}}")
  endforeach()
endforeach()

message(STATUS "*** loaded toolchain-gcc.cmake")
