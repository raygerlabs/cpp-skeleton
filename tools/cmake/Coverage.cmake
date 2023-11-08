if(ENABLE_COVERAGE)
  message(STATUS "Code coverage is enabled!")
  if (MSVC)
    message(WARNING "Code coverage is not supported for Visual Studio!")
    return()
  endif()

  add_custom_target(cov)
  set_target_properties(cov
  PROPERTIES
    FOLDER "Tools"
  )
  add_compile_options("--coverage -Og")
  add_link_options("--coverage")
  
  find_program(LCOV_PROGRAM NAMES "lcov")
  if (LCOV_PROGRAM) # Is lcov installed on your system?
    add_custom_target(lcov # Create CMake target for lcov
      COMMAND ${LCOV_PROGRAM}
        --quiet                   # Do not print progress
        --capture                 # Set capture mode
        --exclude "*/test/*"
        --exclude "gtest*"
        --exclude "gmock*"
        --exclude "*/.conan/*"
        --exclude "/usr/include/*"
        --exclude "/Library/*"
        --directory ${PROJECT_SOURCE_DIR}
        --output-file ${PROJECT_BINARY_DIR}/coverage.info
      COMMENT "Generating code coverage" VERBATIM)
    add_dependencies(cov lcov) # Add lcov to the target
  endif()

  find_program(GENHTML_PROGRAM NAMES "genhtml")
  if (GENHTML_PROGRAM) # Is genhtml installed on your system?
    add_custom_target(genhtml # Create CMake target for genhtml
      COMMAND ${GENHTML_PROGRAM}
        --legend ${PROJECT_BINARY_DIR}/coverage.info
        --output-directory ${PROJECT_BINARY_DIR}/coverage
        --frames
        --show-details
        --demangle-cpp
      DEPENDS lcov
      COMMENT "Generating html version of code coverage" VERBATIM)
    add_dependencies(cov genhtml) # Add genhtml to the target
  endif()
endif()
