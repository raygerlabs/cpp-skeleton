include_guard(GLOBAL)

set(GCC_COMMON_FLAGS
    "-pedantic"                # Warn for non-compliant language extensions
    "-Wall"                    # Enable baseline warnings
    "-Wextra"                  # Enable additional baseline warnings
    "-Werror"                  # Treat warnings as errors
    "-Wshadow"                 # Warn for a local variable or type declaration shadows another variable, parameter, type, or class member
    "-Wunused"                 # Warn for any unused declaration
    "-Wuninitialized"          # Warn for an object with automatic or allocated storage duration is used without having been initialized
    "-Wundef"                  # Warn for an undefined identifier is evaluated in an #if directive
    "-Wconversion"             # Warn for implicit conversions that may alter a value
    "-Wcast-align"             # Warn for pointer cast which increases target alignment
    "-Wcast-qual"              # Warn for pointer cast which removes type qualifier
    "-Wsign-conversion"        # Warn for implicit conversions that change an integer's sign
    "-Wfloat-equal"            # Warn for direct floating-point comparisons
    "-Wdouble-promotion"       # Warn for a float is implicitly promoted to double
    "-Wunreachable-code"       # Warn for code blocks never be executed
    "-Wpointer-arith"          # Warn for anything that depends on the "size of" a function type or of void
    "-Wnull-dereference"       # Warn for null pointer dereference is detected
    "-Wswitch-enum"            # Warn for a switch statement is lacking a case for one or more named enums
    "-Wswitch-default"         # Warn for a switch statement is lacking a default case
    "-Wimplicit-fallthrough"   # Warn for switch case is falling through
    "-Wmisleading-indentation" # Warn for indentation is implying blocks of code that doesn't actually exist
)

set(GCC_DEBUG_FLAGS
    "-D_DEBUG"                 # Define current build type
    "-DDEBUG"                  # Enable debug assertions
    "-O0"                      # Disable optimization
    "-g"                       # Enable debug information
)

set(GCC_RELEASE_FLAGS
    "-D_RELEASE"               # Define current build type
    "-DNDEBUG"                 # Disable debug assertions 
    "-O3"                      # Enable full optimization
)

# Transform list to space-separated string
string(REPLACE ";" " " GCC_COMMON_FLAGS  "${GCC_COMMON_FLAGS}")
string(REPLACE ";" " " GCC_DEBUG_FLAGS   "${GCC_DEBUG_FLAGS}")
string(REPLACE ";" " " GCC_RELEASE_FLAGS "${GCC_RELEASE_FLAGS}")

# Override compiler flags
set(CMAKE_C_FLAGS           "${GCC_COMMON_FLAGS}")
set(CMAKE_CXX_FLAGS         "${GCC_COMMON_FLAGS}")
set(CMAKE_C_FLAGS_DEBUG     "${GCC_DEBUG_FLAGS}")
set(CMAKE_CXX_FLAGS_DEBUG   "${GCC_DEBUG_FLAGS}")
set(CMAKE_C_FLAGS_RELEASE   "${GCC_RELEASE_FLAGS}")
set(CMAKE_CXX_FLAGS_RELEASE "${GCC_RELEASE_FLAGS}")

# Remove unused sections
set(CMAKE_LINK_FLAGS "-Wl, --gc-sections")
