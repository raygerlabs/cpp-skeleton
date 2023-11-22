if (NOT ENABLE_COVERAGE)
  message(STATUS "Code coverage disabled")
elseif (MSVC)
  message(WARNING "Code coverage unsupported for Windows")
  message(STATUS "Code coverage disabled")
  set(ENABLE_COVERAGE OFF)
else()
  find_program(LCOV_PROGRAM NAMES "lcov")
  if (NOT LCOV_PROGRAM)
    message(ERROR "LCOV Code Coverage is not installed. Please install it to generate coverage.")
    return()
  endif()

  find_program(GENHTML_PROGRAM NAMES "genhtml")
  if (NOT GENHTML_PROGRAM)
    message(ERROR "GenHtml is not installed. Please install it to generate coverage.")
    return()
  endif()
  
  message(STATUS "Code coverage enabled")
  add_compile_options("--coverage")
  add_link_options("--coverage")
  
  add_custom_target(coverage)
  set_target_properties(coverage PROPERTIES FOLDER "Tools")
  
  add_custom_target(coverage_info
    COMMAND ${LCOV_PROGRAM}
      --quiet
      --capture
      --exclude "*/benchmarks/*"
      --exclude "*/cmake/*"
      --exclude "*/docs/*"
      --exclude "*/examples/*"
      --exclude "*/tests/*"
      --exclude "gtest*"
      --exclude "gmock*"
      --exclude "*/.conan/*"
      --exclude "/usr/include/*"
      --exclude "/Library/*"
      --directory ${PROJECT_SOURCE_DIR}
      --output-file ${PROJECT_BINARY_DIR}/coverage.info
    COMMENT "Generating coverage information"
    VERBATIM
  )
  set_target_properties(coverage_info PROPERTIES FOLDER "Tools")
  add_dependencies(coverage coverage_info)

  add_custom_target(coverage_html
    COMMAND ${GENHTML_PROGRAM}
      --legend ${PROJECT_BINARY_DIR}/coverage.info
      --output-directory ${PROJECT_BINARY_DIR}/coverage
      --frames
      --show-details
      --demangle-cpp
    DEPENDS coverage_info
    COMMENT "Generating coverage HTML"
    VERBATIM
  )
  set_target_properties(coverage_html PROPERTIES FOLDER "Tools")
  add_dependencies(coverage coverage_html)
endif()
