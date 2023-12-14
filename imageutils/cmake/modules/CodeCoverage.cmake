include_guard(GLOBAL)

if (WITH_COVERAGE)
  find_program(LCOV_PROGRAM lcov)
  find_program(GENHTML_PROGRAM genhtml)
  if (NOT LCOV_PROGRAM)
    message(WARNING "Could not find lcov")
    message(STATUS "Feature: code coverage skipped")
  elseif (NOT GENHTML_PROGRAM)
    message(WARNING "Could not find genhtml")
    message(STATUS "Feature: code coverage skipped")
  else ()
    add_custom_target(coverage)
    add_custom_target(lcov
      COMMAND ${LCOV_PROGRAM}
        --quiet
        --capture
        --zerocounters
        --directory "${PROJECT_SOURCE_DIR}"
        --output-file "${PROJECT_BINARY_DIR}/coverage.info"
      COMMENT "Generate coverage information"
      VERBATIM
    )
    add_dependencies(coverage lcov)

    add_custom_target(genhtml
      COMMAND ${GENHTML_PROGRAM}
        --quiet
        --frames
        --show-details
        --demangle-cpp
        --output-directory "${PROJECT_BINARY_DIR}/coverage"
        "${PROJECT_BINARY_DIR}/coverage.info"
      COMMENT "Generating HTML view from code coverage"
      DEPENDS lcov
      VERBATIM
    )
    add_dependencies(coverage genhtml)
  endif ()
else (WITH_COVERAGE)
  message(STATUS "Feature: code coverage disabled")
endif (WITH_COVERAGE)
