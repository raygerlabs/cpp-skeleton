set(GCC_COMMON_FLAGS)
string(APPEND GCC_COMMON_FLAGS
  " -pedantic "               # Disable non-standard behavior
  " -Wall "                   # Enable all warnings
  " -Wextra "                 # Enable extra warnings
  " -Werror "                 # Treat warnings as errors
  " -Wshadow "                # Warns for local variables shadows an another
  " -Wunused "                # Warns for unused variables
  " -Wuninitialized "         # Warns if any automatic variable is uninitialized
  " -Wundef "                 # Warns if an undefined identifier is evaluated in an #if directive
  " -Wconversion "            # Warns for implicit conversions that may alter a value
  " -Wcast-align "            # Warns for pointer cast which increases target alignment
  " -Wcast-qual "             # Warns for pointer cast which removes type qualifier
  " -Wsign-conversion "       # Warns for implicit conversions that change an integer's sign
  " -Wfloat-equal "           # Warns if floating-point values are compared without considering tolerance
  " -Wdouble-promotion "      # Warns if a float is implicitly promoted to double
  " -Wunreachable-code "      # Warns if a code block is never be executed
  " -Wpointer-arith "         # Warns for anything that depends on the "size of" a function type or of void
  " -Wold-style-cast "        # Warns for old-style (C-style) casts
  " -Wswitch-enum "           # Warns whenever a switch statement is lacking a case for one or more named enums
  " -Wswitch-default "        # Warns whenever a switch statement is lacking a default case
  " -Wimplicit-fallthrough "  # Warns when a switch case falls through
  " -Wmisleading-indentation "# Warns when indentation implies blocks of code that don't actually exist
  " -Wformat=2 "              # Enables additional format checks
  " -fdata-sections "         # Places each data items in its own section
  " -ffunction-sections "     # Places each function in its own section
)

### Override C/C++ flags

# Warn when a function declaration hides virtual functions from a base class (-Woverloaded-virtual)
# Warn when a class declares a non-virtual destructor (-Wnon-virtual-dtor)
# Warn if null pointer dereference is detected (-Wnull-dereference)
# Disable exceptions (-fno-exceptions)
# Disable run-time type information (-fno-rtti)
set(CMAKE_CXX_FLAGS " ${GCC_COMMON_FLAGS} -Woverloaded-virtual -Wnon-virtual-dtor -Wnull-dereference -fno-exceptions -fno-rtti ")
set(CMAKE_C_FLAGS " ${GCC_COMMON_FLAGS} ")
# Define build type macro (-D_DEBUG, -D_RELWITHDEBINFO, -D_RELEASE)
# Enable debug assertions (-DDEBUG)
# Enable run-time buffer overflow detection (-D_FORTIFY_SOURCE=2)
# Enable run-time bounds checking (-D_GLIBCXX_ASSERTIONS)
# Enable stack canaries (-fstack-protector-all)
# Enable debug information (-g)
# Disable optimizations (-O0)
set(CMAKE_CXX_FLAGS_DEBUG " -D_DEBUG -DDEBUG -D_FORTIFY_SOURCE=2 -D_GLIBCXX_ASSERTIONS -fstack-protector-all -g -O0 ")
set(CMAKE_C_FLAGS_DEBUG " -D_DEBUG -DDEBUG -D_FORTIFY_SOURCE=2 -D_GLIBC_ASSERTIONS -fstack-protector-all -g -O0 ")
# Set release with debug info flags
# Disable debug assertions (-DNDEBUG)
# Keep frame pointers (-fno-omit-frame-pointer)
# Enable full optimizations (-O3)
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO " -D_RELWITHDEBINFO -DNDEBUG -fno-omit-frame-pointer -g -O3 ")
set(CMAKE_C_FLAGS_RELWITHDEBINFO " -D_RELWITHDEBINFO -DNDEBUG -fno-omit-frame-pointer -g -O3 ")
set(CMAKE_CXX_FLAGS_RELEASE " -D_RELEASE -DNDEBUG -O3 ")
set(CMAKE_C_FLAGS_RELEASE " -D_RELEASE -DNDEBUG -O3 ")


### Linker flags

# Remove unused sections
set(CMAKE_LINK_FLAGS " -Wl, --gc-sections ")
