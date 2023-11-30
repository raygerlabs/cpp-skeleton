message(STATUS "Loaded toolchain-gcc.cmake")

set(CMAKE_CXX_FLAGS
  -pedantic               # Strict ISO C and ISO C++
  -Wall                   # Enable all warnings
  -Wextra                 # Extra warning flags
  -Werror                 # Warnings into errors
  -Wshadow                # Warn when a local variable shadows another
  -Wunused                # Warn whenever a variable is unused aside from its declaration
  -Wuninitialized         # Warn if an automatic variable is used without being initialized
  -Wundef                 # Warn if an undefined identifier is evaluated in an #if directive
  -Wconversion            # Warn for implicit conversions that may alter a value
  -Wcast-align            # Warn for pointer cast which increases target alignment
  -Wcast-qual             # Warn for pointer cast which removes type qualifier
  -Wsign-conversion       # Warn for implicit conversions that change an integer type's sign
  -Wfloat-equal           # Warn if floating-point values are used in equality comparisons
  -Wdouble-promotion      # Warn if float is implicitly promoted to double
  -Wunreachable-code      # Warn if code will never be executed
  -Woverloaded-virtual    # Warn when a function declaration hides virtual functions from a base class
  -Wnon-virtual-dtor      # Warn when a class declares a non-virtual destructor
  -Wnull-dereference      # Warn if null pointer dereference is detected
  -Wpointer-arith         # Warn for anything that depends on the "size of" a function type or of void
  -Wold-style-cast        # Warn for use of old-style (C-style) casts
  -Wswitch-enum           # Warn whenever a switch statement lacks a case for one or more of the named codes of that enumeration
  -Wswitch-default        # Warn whenever a switch statement does not have a default case
  -Wimplicit-fallthrough  # Warn when a switch case falls through
  -Wduplicated-cond       # Warn for duplicated conditions in an if-else-if chain
  -Wduplicated-branches   # Warn for duplicated branches in an if-else chain
  -Wlogical-op            # Warn about suspicious uses of logical operators in expressions
  -Wuseless-cast          # Warn when an expression is casted to its own type
  -Wmisleading-indentation# Warn when indentation implies blocks of code that do not actually exist
  -Wwrite-strings         # Give string constants the type const char[length]
  -Wformat=2              # Enable -Wformat plus additional format checks
  -fno-exceptions         # Disable exception handling
  -fno-rtti               # Disable RTTI
  -fdata-sections         # Place data items in own section
  -ffunction-sections     # Each function in own section
)

set(CMAKE_CXX_FLAGS_DEBUG
  -D_DEBUG                # _DEBUG macro
  -DDEBUG                 # DEBUG macro
  -O0                     # No optimization
  -g                      # Debug information
)

set(CMAKE_CXX_FLAGS_RELWITHDEBINFO
  -D_RELWITHDEBINFO       # _PROFILE macro
  -DNDEBUG                # NDEBUG macro
  -O3                     # No optimization
  -fno-omit-frame-pointer # Keep the frame pointers
  -g                      # Debug information
)

set(CMAKE_CXX_FLAGS_RELEASE
  -D_RELEASE              # _RELEASE macro
  -DNDEBUG                # NDEBUG macro
  -O3                     # More optimization
)

set(CMAKE_LINK_FLAGS -Wl, --gc-sections)  # Remove unused sections

# Convert lists to space-separated strings (required for passing to compilers and linkers)
foreach(BUILD_TYPE IN ITEMS ${BUILD_TYPES})
  if (NOT "${BUILD_TYPE}" STREQUAL "") # If build type is non-empty, update and print flags
    string(REPLACE ";" " " CMAKE_CXX_FLAGS_${BUILD_TYPE} "${CMAKE_CXX_FLAGS_${BUILD_TYPE}}")
    message("CMAKE_CXX_FLAGS_${BUILD_TYPE} = ${CMAKE_CXX_FLAGS_${BUILD_TYPE}}")
  else() # otherwise, don't add underscore
    string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    message("CMAKE_CXX_FLAGS = ${CMAKE_CXX_FLAGS}")
  endif()
  foreach (LINK_TYPE IN ITEMS ${LINK_TYPES})
    if (NOT "${BUILD_TYPE}" STREQUAL "")
      string(REPLACE ";" " " CMAKE_${LINK_TYPE}_LINKER_FLAGS_${BUILD_TYPE} "${CMAKE_${LINK_TYPE}_LINKER_FLAGS_${BUILD_TYPE}}")
      message("CMAKE_${LINK_TYPE}_LINKER_FLAGS_${BUILD_TYPE} = ${CMAKE_${LINK_TYPE}_LINKER_FLAGS_${BUILD_TYPE}}")
    else()
      string(REPLACE ";" " " CMAKE_${LINK_TYPE}_LINKER_FLAGS "${CMAKE_${LINK_TYPE}_LINKER_FLAGS}")
      message("CMAKE_${LINK_TYPE}_LINKER_FLAGS = ${CMAKE_${LINK_TYPE}_LINKER_FLAGS}")
    endif()
  endforeach()
endforeach()
