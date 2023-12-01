set(MSVC_COMMON_FLAGS)
string(APPEND MSVC_COMMON_FLAGS
  " /permissive- " # Disable non-standard behavior
  " /W4 " # Set warning level 4
  " /WX " # Treat warnings as errors
  " /MP12 "  # Use multiple processors for compilation
  " /GF " # Eliminate duplicate strings
  " /Gy " # Enable function-level linking
  " /utf-8 " # Set source and execution character sets to UTF-8
  " /w14242 " # Implicit conversion potential loss of data warning
  " /w14254 " # Conversion from integral type to smaller integral type warning
  " /w14263 " # Compiler extension warning for use of templates
  " /w14265 " # Zero-sized array warning
  " /w14287 " # Truncation of constant value warning
  " /we4289 " # Nonstandard extension used (decorated name with a template argument)
  " /w14296 " # Decimal digit truncated to '0' warning
  " /w14311 " # Missing return type warning
  " /w14545 " # Expression before comma warning
  " /w14546 " # Function call before comma warning
  " /w14547 " # Operator before comma warning
  " /w14549 " # Empty statement warning
  " /w14555 " # Expression has no effect warning
  " /w14619 " # Pragma warning
  " /w14640 " # Unreachable code warning
  " /w14826 " # Conversion from 'type1' to 'type2' warning
  " /w14905 " # Macro redefinition warning
  " /w14906 " # Logical not on array warning
  " /w14928 " # Illegal copy initialization warning
  " /wd4530 " # Disable warning for exception handling in function signatures
)

# Override C++ flags
# Disable exceptions (/EHs-c-)
# Disable RTTI (/GR-)
set(CMAKE_CXX_FLAGS "${MSVC_COMMON_FLAGS} /EHs-c- /GR-")
set(CMAKE_C_FLAGS "${MSVC_COMMON_FLAGS}")

# Define build type macro (/D_DEBUG, /D_RELWITHDEBINFO, /D_RELEASE)
# Enable runtime error checks (/RTC1)
# Enable buffer security checks (/GS)
# Enable additional security checks (/sdl)
# Enable debug information (/Zi)
# Disable optimizations (/Od)
set(CMAKE_CXX_FLAGS_DEBUG "/D_DEBUG /DDEBUG /RTC1 /GS /sdl /Zi /Od")
set(CMAKE_C_FLAGS_DEBUG "/D_DEBUG /DDEBUG /RTC1 /GS /sdl /Zi /Od")
# Disable debug assertions (/DNDEBUG)
# Keep frame pointers (/Oy-)
# Generate debug information (/Zi)
# Enable full optimization (/Ox)
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/D_RELWITHDEBINFO /DNDEBUG /Oy- /Zi /Ox")
set(CMAKE_C_FLAGS_RELWITHDEBINFO "/D_RELWITHDEBINFO /DNDEBUG /Oy- /Zi /Ox")
set(CMAKE_CXX_FLAGS_RELEASE "/D_RELEASE /DNDEBUG /Ox")
set(CMAKE_C_FLAGS_RELEASE "/D_RELEASE /DNDEBUG /Ox")

### Linker flags

# Generate PDB (/debug)
set(CMAKE_SHARED_LINKER_FLAGS_DEBUG "/debug")
set(CMAKE_MODULE_LINKER_FLAGS_DEBUG "/debug")
set(CMAKE_EXE_LINKER_FLAGS_DEBUG "/debug")

# Disable incremental linking (/incremental:no)
# Remove unreferenced data or function (/opt:ref)
# Remove duplicated COMDAT (/opt:icf=2)
set(CMAKE_SHARED_LINKER_FLAGS_RELWITHDEBINFO "/incremental:no /debug /opt:ref /opt:icf=2")
set(CMAKE_MODULE_LINKER_FLAGS_RELWITHDEBINFO "/incremental:no /debug /opt:ref /opt:icf=2")
set(CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO "/incremental:no /debug /opt:ref /opt:icf=2")
set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "/opt:ref /opt:icf=2")
set(CMAKE_MODULE_LINKER_FLAGS_RELEASE "/opt:ref /opt:icf=2")
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "/opt:ref /opt:icf=2")
