message(STATUS "Executing overrides-msvc.cmake!")

# Custom CMake settings for MSVC

# Initial C++ compiler flags for all build configurations.
set(CMAKE_CXX_FLAGS_INIT
  /W4               # Set level 4 warning comformance
  /WX               # Treat warnings as errors
  /permissive-      # Strict C++ conformance
  /EHsc             # Enable C++ exceptions
  /GR               # Enable RTTI
  /MP               # Multi-process compilation
  /GF               # Eliminate duplicate strings
  /Gy               # Enable function-level linking
  /utf-8            # Enable UTF-8 character set
  /w14242           # Warn for signed/unsigned mismatch
  /w14254           # Warn for possible data loss during conversion
  /w14263           # Warn for member function does not override base class
  /w14265           # Warn for class with virtual functions but non-virtual destructor
  /w14287           # Warn for unsigned/negative constant mismatch
  /we4289           # Treat 'identifier' warning as an error
  /w14296           # Expression is constant; presumed zero result
  /w14311           # Pointer truncation during conversion
  /w14545           # Expression has no effect
  /w14546           # Variable is initialized to itself
  /w14547           # Statement is not executed
  /w14549           # Contains different type 'type1' from function 'type2'
  /w14555           # Expression has no operators
  /w14619           # Macro redefinition
  /w14640           # Attribute 'attribute' ignored in 'declaration'
  /w14826           # Sign-extended conversion from 'type1' to 'type2'
  /w14905           # Class has virtual functions but trivial destructor is not virtual
  /w14906           # Symbol 'type1' is never used
  /w14928           # Assignment operator could not be generated
)

# Debug build configuration.
set(CMAKE_CXX_FLAGS_DEBUG_INIT
  /D_DEBUG          # Define _DEBUG preprocessor symbol
  /DDEBUG           # Define DEBUG preprocessor symbol
  /Od               # Disable optimizations
  /RTC1             # Enable run-time checks for C++ code (level 1)
  /GS               # Enable buffer security checks
  /Zi               # Produce PDB information for debugging
  /Zo               # Enhance the debugging experience
)

# Profile build configuration.
set(CMAKE_CXX_FLAGS_PROFILE_INIT
  /D_PROFILE        # Define _PROFILE preprocessor symbol
  /DNDEBUG          # Disable debugging information
  /Ox               # Enable full optimization
  /Oy-              # Disable frame pointer omission
  /GS-              # Disable buffer security checks
  /Zi               # Produce PDB information for debugging
  /Zo               # Enhance the debugging experience
)

# Release build configuration.
set(CMAKE_CXX_FLAGS_RELEASE_INIT
   /D_RELEASE       # Define _RELEASE preprocessor symbol
   /DNDEBUG         # Disable debugging information
   /Ox              # Enable full optimization
   /GS-             # Disable buffer security checks
)

# Combine individual flags into a single space-separated string for CMake.
string(REPLACE ";" " " CMAKE_CXX_FLAGS_INIT "${CMAKE_CXX_FLAGS_INIT}")
message(STATUS "CMAKE_CXX_FLAGS_INIT=${CMAKE_CXX_FLAGS_INIT}")
foreach(build_type IN ITEMS DEBUG PROFILE RELEASE)
  string(REPLACE ";" " " CMAKE_CXX_FLAGS_${build_type}_INIT "${CMAKE_CXX_FLAGS_${build_type}_INIT}")
  message(STATUS "CMAKE_CXX_FLAGS_${build_type}_INIT=${CMAKE_CXX_FLAGS_${build_type}_INIT}")
endforeach()

# Define the linker flags for each build type
set(DEBUG_FLAGS "/DEBUG /INCREMENTAL:NO")
set(PROFILE_FLAGS "/DEBUG /INCREMENTAL:NO /OPT:REF /OPT:ICF=2")
set(RELEASE_FLAGS "/INCREMENTAL:NO /OPT:REF /OPT:ICF=2")

# Define a list of linker types
set(LINKER_TYPES EXE SHARED STATIC MODULE)

# Update linker flags for MSVC
foreach(link_type IN LISTS LINKER_TYPES)
  set(CMAKE_${link_type}_LINKER_FLAGS_DEBUG_INIT ${DEBUG_FLAGS})
  set(CMAKE_${link_type}_LINKER_FLAGS_PROFILE_INIT ${PROFILE_FLAGS})
  set(CMAKE_${link_type}_LINKER_FLAGS_RELEASE_INIT ${RELEASE_FLAGS})
  message(STATUS "CMAKE_${link_type}_LINKER_FLAGS_DEBUG_INIT=${CMAKE_${link_type}_LINKER_FLAGS_DEBUG_INIT}")
  message(STATUS "CMAKE_${link_type}_LINKER_FLAGS_PROFILE_INIT=${CMAKE_${link_type}_LINKER_FLAGS_PROFILE_INIT}")
  message(STATUS "CMAKE_${link_type}_LINKER_FLAGS_RELEASE_INIT=${CMAKE_${link_type}_LINKER_FLAGS_RELEASE_INIT}")
endforeach()
