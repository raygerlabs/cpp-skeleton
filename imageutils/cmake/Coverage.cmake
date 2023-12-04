include_guard()

if (ENABLE_COVERAGE)
    if (NOT MSVC)
        find_program(LCOV_PROGRAM NAMES "lcov")
        if (NOT LCOV_PROGRAM)
            message(FATAL_ERROR "Could not found lcov!")
        endif (NOT LCOV_PROGRAM)
        
        find_program(GENHTML_PROGAM NAMES "genhtml")
        if (NOT GENHTML_PROGRAM)
            message(FATAL_ERROR "Could not found genhtml!")
        endif (NOT GENHTML_PROGRAM)
        
        message(STATUS "Code coverage enabled")
        
        add_compile_options("--coverage")
        add_link_options("--coverage")

        add_custom_target(coverage)
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
            COMMENT "Generating coverage information..."
            VERBATIM
        )
        add_dependencies(coverage coverage_info)
        add_custom_target(coverage_html
            COMMAND ${GENHTML_PROGRAM}
                --legend ${PROJECT_BINARY_DIR}/coverage.info
                --output-directory ${PROJECT_BINARY_DIR}/coverage
                --frames
                --show-details
                --demangle-cpp
            DEPENDS coverage_info
            COMMENT "Generating HTML with code coverage information..."
            VERBATIM
        )
        add_dependencies(coverage coverage_html)
    else (NOT MSVC)
        message(STATUS "Code coverage disabled")
        set(ENABLE_COVERAGE OFF)
    endif (NOT MSVC)
else (ENABLE_COVERAGE)
    message(STATUS "Code coverage disabled")
endif (ENABLE_COVERAGE)
