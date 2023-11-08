# Configure C++ compiler flags for various build configurations.
# CMAKE_CXX_FLAGS_INIT contains common flags.
set(CMAKE_CXX_FLAGS_INIT
  -D_FORTIFY_SOURCE=2       # Enable runtime buffer overflow protection.
  -D_GLIBCXX_ASSERTIONS     # Enable GNU C++ library debugging assertions.
  -Wall                     # Enable all commonly used warning flags.
  -Wextra                   # Enable extra warning flags.
  -pedantic                 # Check code against the C++ standard.
  -Werror                   # Treat warnings as errors.
  -Wshadow                  # Warn about variable shadowing.
  -Wnon-virtual-dtor        # Warn about missing virtual destructors.
  -Wunused                  # Warn about unused variables.
  -Wuninitialized           # Warn about uninitialized variables.
  -Wundef                   # Warn if an undefined identifier is used.
  -Wconversion              # Warn about type conversion issues.
  -Wcast-align              # Warn about type casts that might lead to alignment issues.
  -Wcast-qual               # Warn about casting away const qualifiers.
  -Wsign-conversion         # Warn about sign conversion issues.
  -Wfloat-equal             # Warn about floating-point comparisons.
  -Wdouble-promotion        # Warn about float-to-double promotion.
  -Wunreachable-code        # Warn about unreachable code.
  -Waggregate-return        # Warn about returning aggregates.
  -Woverloaded-virtual      # Warn about overloaded virtual functions.
  -Wmisleading-indentation  # Warn about misleading indentation.
  -Wnull-dereference        # Warn about null pointer dereference.
  -Wpointer-arith           # Warn about pointer arithmetic.
  -Wold-style-cast          # Warn about C-style type casts.
  -Wswitch-default          # Warn if there is no 'default' label in a switch.
  -Wswitch-enum             # Warn about incomplete enumeration cases.
  -Wstrict-prototypes       # Warn about non-prototype function declarations.
  -Wstrict-overflow=5       # Enable strict overflow checks up to level 5.
  -Wwrite-strings           # Warn if a string literal is assigned to a non-const pointer.
  -Wformat=2                # Check format strings against arguments.
)

# Debug build configuration flags.
set(CMAKE_CXX_FLAGS_DEBUG_INIT
  -D_DEBUG                 # Define _DEBUG for debugging.
  -DDEBUG                  # Define DEBUG for debugging.
  -O0                     # Optimization level 0 (no optimization).
  -g                      # Generate debug information.
)

# Profile build configuration flags.
set(CMAKE_CXX_FLAGS_PROFILE_INIT
  -D_PROFILE               # Define _PROFILE for profiling.
  -DNDEBUG                # Define NDEBUG to disable assertions.
  -O2                     # Optimization level 2 (moderate optimization).
  -g                      # Generate debug information.
)

# Release build configuration flags.
set(CMAKE_CXX_FLAGS_RELEASE_INIT
  -D_RELEASE               # Define _RELEASE for release builds.
  -DNDEBUG                # Define NDEBUG to disable assertions.
  -O3                     # Optimization level 3 (maximum optimization).
)

# Combine individual flags into space-separated strings for CMake.
foreach(_language IN ITEMS C CXX)
  string(REPLACE ";" " " CMAKE_${_language}_FLAGS_INIT ${CMAKE_${_language}_FLAGS_INIT})
  foreach(_config IN ITEMS DEBUG PROFILE RELEASE)
    string(REPLACE ";" " " CMAKE_${_language}_FLAGS_${_config}_INIT ${CMAKE_${_language}_FLAGS_${_config}_INIT})
  endforeach(_config)
endforeach(_language)

# Set initial link flags:
# - enable garbage collection of unused sections,
# - ensure definitions exist for all symbols,
# - enable immediate binding,
# - enable read-only relocations sections 
set(CMAKE_LINK_FLAGS_INIT "-Wl, --gc-sections -Wl,-z,defs -Wl,-z,now -Wl,-z,relro")
