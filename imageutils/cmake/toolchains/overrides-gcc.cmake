Mmessage(STATUS "Executing overrides-gcc.cmake!")

# Initial C++ compiler flags for all build configurations
set(CMAKE_CXX_FLAGS_INIT
  -Wall                     # Enable all baseline warnings
  -Wextra                   # Enable additional warnings
  -pedantic                 # Enable strict C++ comformance
  -Werror                   # Treat warnings as errors
  -Wshadow                  # Warn about variable shadowing
  -Wunused                  # Warn about unused variables
  -Wuninitialized           # Warn about uninitialized variables
  -Wundef                   # Warn about undefined identifiers
  -Wconversion              # Warn about type conversion issues
  -Wcast-align              # Warn about type casts that might lead to alignment issues
  -Wcast-qual               # Warn about casting away const qualifiers
  -Wsign-conversion         # Warn about sign conversion issues
  -Wfloat-equal             # Warn about floating-point comparisons
  -Wdouble-promotion        # Warn about float-to-double promotion
  -Wunreachable-code        # Warn about unreachable code
  -Woverloaded-virtual      # Warn about overloaded virtual functions
  -Wnon-virtual-dtor        # Warn about missing virtual destructors
  -Wnull-dereference        # Warn about null pointer dereference
  -Wpointer-arith           # Warn about pointer arithmetic
  -Wold-style-cast          # Warn about C-style type casts
  -Wswitch-enum             # Warn about incomplete enumeration cases
  -Wswitch-default          # Warn about no 'default' label in switch-cases
  -Wimplicit-fallthrough    # Warn about switch-case statements fall through
  -Wduplicated-cond         # Warn about conditionals having duplicated conditions
  -Wduplicated-branches     # Warn about conditionals having duplicated code
  -Wlogical-op              # Warn about suspicious uses of logical operators
  -Wuseless-cast            # Warn about useless type casts
  -Wmisleading-indentation  # Warn about misleading indentation
  -Wwrite-strings           # Warn about string literals assigned to non-const pointers
  -Wformat=2                # Warn about format string vulnerabilities
  -fno-exceptions           # Disable C++ exceptions
  -fno-rtti                 # Disable runtime type information (RTTI)
  -ffast-math               # Use fast math
  -fdata-sections           # Place data items into their own section
	-ffunction-sections       # Place function bodies into their own section
)

# Debug build configuration flags
set(CMAKE_CXX_FLAGS_DEBUG_INIT
  -D_DEBUG                 # Define _DEBUG preprocessor symbol
  -DDEBUG                  # Define DEBUG preprocessor symbol
  -O0                      # Disable optimization
  -g                       # Enable debugging symbols
)

# Profile build configuration flags
set(CMAKE_CXX_FLAGS_PROFILE_INIT
  -D_PROFILE               # Define _PROFILE preprocessor symbol
  -DNDEBUG                 # Disable debugging information
  -O2                      # Enable high optimization
  -fno-omit-frame-pointer  # Keep frame pointers
  -g                       # Enable debugging information
)

# Release build configuration flags
set(CMAKE_CXX_FLAGS_RELEASE_INIT
  -D_RELEASE               # Define _RELEASE preprocessor symbol
  -DNDEBUG                 # Disable debugging information
  -O3                      # Enable full optimization
  -g                       # Enable debugging information
)

# Combine the list of individual flags into a single space-separated string
set(BUILD_TYPES DEBUG PROFILE RELEASE)
string(REPLACE ";" " " CMAKE_CXX_FLAGS_INIT "${CMAKE_CXX_FLAGS_INIT}")
message(STATUS "CMAKE_CXX_FLAGS_INIT=${CMAKE_CXX_FLAGS_INIT}")
foreach(build_type IN ITEMS ${BUILD_TYPES})
  string(REPLACE ";" " " CMAKE_CXX_FLAGS_${build_type}_INIT "${CMAKE_CXX_FLAGS_${build_type}_INIT}")
  message(STATUS "CMAKE_CXX_FLAGS_${build_type}_INIT=${CMAKE_CXX_FLAGS_${build_type}_INIT}")
endforeach()

# Define a list of linker types
set(LINKER_TYPES EXE SHARED MODULE)
# Define the linker flags
set(LINK_FLAGS "-Wl, --gc-sections -Wl,-dead_strip")
# Update linker flags
foreach(link_type IN LISTS LINKER_TYPES)
  set(CMAKE_${link_type}_LINKER_FLAGS_INIT ${LINK_FLAGS})
  message(STATUS "CMAKE_${link_type}_LINKER_FLAGS_INIT=${CMAKE_${link_type}_LINKER_FLAGS_INIT}")
endforeach()
