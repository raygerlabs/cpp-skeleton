message("Loaded toolchain-msvc.cmake")

set(CMAKE_CXX_FLAGS
  /permissive-            # Disable non-standard behavior
  /W4                     # Set warning level 4
  /WX                     # Treat warnings as errors
  /EHs-c-                 # No C++ structured exception handling
  /GR-                    # Disable C++ RTTI (Run-Time Type Information)
  /MP12                   # Use multiple processors for compilation
  /GF                     # Eliminate duplicate strings
  /Gy                     # Enable function-level linking
  /utf-8                  # Set source and execution character sets to UTF-8
  /w14242                 # Implicit conversion potential loss of data warning
  /w14254                 # Conversion from integral type to smaller integral type warning
  /w14263                 # Compiler extension warning for use of templates
  /w14265                 # Zero-sized array warning
  /w14287                 # Truncation of constant value warning
  /we4289                 # Nonstandard extension used (decorated name with a template argument)
  /w14296                 # Decimal digit truncated to '0' warning
  /w14311                 # Missing return type warning
  /w14545                 # Expression before comma warning
  /w14546                 # Function call before comma warning
  /w14547                 # Operator before comma warning
  /w14549                 # Empty statement warning
  /w14555                 # Expression has no effect warning
  /w14619                 # Pragma warning
  /w14640                 # Unreachable code warning
  /w14826                 # Conversion from 'type1' to 'type2' warning
  /w14905                 # Macro redefinition warning
  /w14906                 # Logical not on array warning
  /w14928                 # Illegal copy initialization warning
  /wd4530                 # Disable warning for exception handling in function signatures
)

set(CMAKE_CXX_FLAGS_DEBUG
  /D_DEBUG                # Define build type as a macro
  /DDEBUG                 # Enable assertions
  /RTC1                   # Enable runtime error checks
  /GS                     # Enable security checks
  /sdl                    # Enable additional security checks
  /Od                     # Disable optimization
  /Zi                     # Generate debug information
  /Zo                     # Enhance debug information
)

set(CMAKE_CXX_FLAGS_RELWITHDEBINFO
  /D_RELWITHDEBINFO       # Define build type as a macro
  /D_PROFILE              # Define build type as a macro
  /DNDEBUG                # Disable assertions
  /Ox                     # Enable full optimization
  /Oy-                    # Keep frame pointers as omitted frame pointers may interfere debugging
  /Zi                     # Generate debug information
  /Zo                     # Enhance debug information
)

set(CMAKE_CXX_FLAGS_RELEASE
  /D_RELEASE              # Define build type as a macro
  /DNDEBUG                # Disable assertions
  /Ox                     # Enable full optimization
)

set(BUILD_TYPES "" "DEBUG" "RELWITHDEBINFO" "RELEASE" "MINSIZEREL")
set(LINK_TYPES "EXE" "SHARED" "MODULE" "STATIC")

# Set link flags
foreach(BUILD_TYPE IN ITEMS ${BUILD_TYPES})
  foreach (LINK_TYPE IN ITEMS ${LINK_TYPES})
    if (NOT "${BUILD_TYPE}" STREQUAL "DEBUG") # Optimize 
      set(CMAKE_${LINK_TYPE}_LINKER_FLAGS_${BUILD_TYPE}
        /incremental:no   # Disable incremental linking
        /opt:ref          # Remove unreferenced data or functions
        /opt:icf=2        # Remove duplicated COMBAT foldings
        /debug            # Generate debug symbol table
      )
    else () # unless if it's debug...
      set(CMAKE_${LINK_TYPE}_LINKER_FLAGS_${BUILD_TYPE}
        /debug            # Generate debug symbol table
      )
    endif()
  endforeach()
endforeach()

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
