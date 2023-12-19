include_guard(GLOBAL)

set(MSVC_COMMON_FLAGS
    "/permissive-"        # Disable non-standard behavior
    "/W4"                 # Enable strict warning level
    "/WX"                 # Treat warnings as errors
    "/MP12"               # Build with multiple processors
    "/GF"                 # Eliminate duplicate strings
    "/Gy"                 # Enable function-level linking
    "/utf-8"              # Set character enconding to utf-8 for source and execution
    "/w14242"             # Warn for potential data loss due to implicit conversion between differing types
    "/w14254"             # Warn for potential data loss due to larger bit field is assigned to a smaller one
    "/w14263"             # Warn for member function is shadowing the base class virtual function
    "/w14265"             # Warn for potential memory leak due to inherited class having non-virtual destructor
    "/w14287"             # Warn for unsigned variable is used in an expression with a signed variable
    "/we4289"             # Warn for loop control variable is used outside for-loop scope
    "/w14296"             # Warn for unsigned variable is compared to zero
    "/w14311"             # Warn for 64-bit pointer truncation issues
    "/w14545"             # Warn for expression before comma evaluates to a function which is missing an argument list
    "/w14546"             # Warn for function call before comma missing argument list
    "/w14547"             # Warn for ill-formed comma expression taking no effect
    "/w14549"             # Warn for ill-formed comma expression taking no effect
    "/w14555"             # Warn for an expression taking no effect
    "/w14619"             # Warn for pragma warning referring to non-existent warning number
    "/w14640"             # Warn for construction of local static object is not thread-safe
    "/w14826"             # Warn for type conversion that may cause data loss or data truncation 
    "/w14905"             # Warn for unsafe cast from wide string to narrow string
    "/w14906"             # Warn for unsafe cast from narrow string to wide string
    "/w14928"             # Warn for illegal copy initialization; more than one user-defined conversion has been implicitly applied
)
set(MSVC_CXX_COMMON_FLAGS
    "/EHsc"               # Enable C++ exceptions
    "/GR"                 # Enable runtime type information (rtti)
)


set(MSVC_DEBUG_FLAGS
    "/D_DEBUG"            # Define current build type
    "/DDEBUG"             # Enable debug assertions
    "/Od"                 # Disable optimization
    "/GS"                 # Enable buffer security checks
    "/RTC1"               # Enable runtime type checks
    "/Zi"                 # Enable debug information
)

set(MSVC_RELEASE_FLAGS
    "/D_RELEASE"          # Define current build type
    "/DNDEBUG"            # Disable debug assertions 
    "/Ox"                 # Enable full optimization
)

# Transform list to space-separated string
string(REPLACE ";" " " MSVC_COMMON_FLAGS     "${MSVC_COMMON_FLAGS}")
string(REPLACE ";" " " MSVC_CXX_COMMON_FLAGS "${MSVC_CXX_COMMON_FLAGS}")
string(REPLACE ";" " " MSVC_DEBUG_FLAGS      "${MSVC_DEBUG_FLAGS}")
string(REPLACE ";" " " MSVC_RELEASE_FLAGS    "${MSVC_RELEASE_FLAGS}")

# Override compiler flags
set(CMAKE_C_FLAGS "${MSVC_COMMON_FLAGS}")
set(CMAKE_CXX_FLAGS "${MSVC_COMMON_FLAGS} ${MSVC_CXX_COMMON_FLAGS}")
set(CMAKE_C_FLAGS_DEBUG "${MSVC_DEBUG_FLAGS}")
set(CMAKE_CXX_FLAGS_DEBUG "${MSVC_DEBUG_FLAGS}")
set(CMAKE_C_FLAGS_RELEASE "${MSVC_RELEASE_FLAGS}")
set(CMAKE_CXX_FLAGS_RELEASE "${MSVC_RELEASE_FLAGS}")
