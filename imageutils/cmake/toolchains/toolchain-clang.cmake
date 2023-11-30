set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

set(CLANG_COMMON_FLAGS
  -pedantic               # Strict ISO C and ISO C++
  -Wall                   # Enable all warnings
  -Wextra                 # Extra warning flags
  -Werror                 # Warnings into errors
  -Wshadow                # Warn when a local variable shadows another
  -Wuninitialized         # Warn if an automatic variable is used without being initialized
  -Wundef                 # Warn if an undefined identifier is evaluated in an #if directive
  -Wunused                # Warn whenever a variable is unused aside from its declaration
  -Wconversion            # Warn for implicit conversions that may alter a value
  -Wcast-align            # Warn for pointer cast which increases target alignment
  -Wcast-qual             # Warn for pointer cast which removes type qualifier
  -Wsign-conversion       # Warn for implicit conversions that change an integer type's sign
  -Wfloat-equal           # Warn if floating-point values are used in equality comparisons
  -Wdouble-promotion      # Warn if float is implicitly promoted to double
  -Wunreachable-code      # Warn if code will never be executed
  -Wpointer-arith         # Warn for anything that depends on the "size of" a function type or of void
  -Wold-style-cast        # Warn for use of old-style (C-style) casts
  -Wswitch-default        # Warn whenever a switch statement does not have a default case
  -Wswitch-enum           # Warn whenever a switch statement lacks a case for one or more of the named codes of that enumeration
  -Wimplicit-fallthrough  # Warn when a switch case falls through
  -Wwrite-strings         # Give string constants the type const char[length]
  -Wformat=2              # Enable -Wformat plus additional format checks
  -fdata-sections         # Place data items in own section
  -ffunction-sections     # Each function in own section
)
string(REPLACE ";" " " CLANG_COMMON_FLAGS "${CLANG_COMMON_FLAGS}")


### Override C/C++ flags

# Warn when a function declaration hides virtual functions from a base class (-Woverloaded-virtual)
# Warn when a class declares a non-virtual destructor (-Wnon-virtual-dtor)
# Warn if null pointer dereference is detected (-Wnull-dereference)
# Disable exceptions (-fno-exceptions)
# Disable run-time type information (-fno-rtti)
set(CMAKE_CXX_FLAGS "${CLANG_COMMON_FLAGS} -Woverloaded-virtual -Wnon-virtual-dtor -Wnull-dereference -fno-exceptions -fno-rtti")
set(CMAKE_C_FLAGS "${CLANG_COMMON_FLAGS}")
# Define build type macro (-D_DEBUG, -D_RELWITHDEBINFO, -D_RELEASE)
# Enable debug assertions (-DDEBUG)
# Enable run-time buffer overflow detection (-D_FORTIFY_SOURCE=2)
# Enable stack canaries (-fstack-protector-all)
# Enable debug information (-g)
# Disable optimizations (-O0)
set(CMAKE_CXX_FLAGS_DEBUG "-D_DEBUG -DDEBUG -D_FORTIFY_SOURCE=2 -fstack-protector-all -g -O0")
set(CMAKE_C_FLAGS_DEBUG "-D_DEBUG -DDEBUG -D_FORTIFY_SOURCE=2 -fstack-protector-all -g -O0")
# Disable debug assertions (-DNDEBUG)
# Keep frame pointers (-fno-omit-frame-pointer)
# Enable full optimizations (-O3)
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-D_RELWITHDEBINFO -DNDEBUG -fno-omit-frame-pointer -g -O3")
set(CMAKE_C_FLAGS_RELWITHDEBINFO "-D_RELWITHDEBINFO -DNDEBUG -fno-omit-frame-pointer -g -O3")
set(CMAKE_CXX_FLAGS_RELEASE "-D_RELEASE -DNDEBUG -O3")
set(CMAKE_C_FLAGS_RELEASE "-D_RELEASE -DNDEBUG -O3")


### Linker flags

# Remove unused sections
set(CMAKE_LINK_FLAGS ${CMAKE_LINK_FLAGS} "-Wl, --gc-sections")

### Print

message(STATUS "Loaded toolchain-clang.cmake")
set(_LANGUAGES C CXX)
set(_BUILD_TYPES "" _DEBUG _RELEASE _MINSIZEREL _RELWITHDEBINFO)
set(_LINK_TYPES EXE STATIC SHARED MODULE)
foreach(_LANGUAGE ${_LANGUAGES})
  foreach(_BUILD_TYPE ${_BUILD_TYPES})
    message(STATUS "CMAKE_${_LANGUAGE}_FLAGS${_BUILD_TYPE}: ${CMAKE_${_LANGUAGE}_FLAGS${_BUILD_TYPE}}")
  endforeach()
endforeach()
foreach(_LINK_TYPE ${_LINK_TYPES})
  foreach(_BUILD_TYPE ${_BUILD_TYPES})
    message(STATUS "${_LINK_TYPE}_LINKER_FLAGS${_BUILD_TYPE}: ${${_LINK_TYPE}_LINKER_FLAGS${_BUILD_TYPE}}")
  endforeach()
endforeach()
