include_guard()

if (WITH_TIDY)
  find_program(TIDY_PROGRAM clang-tidy)
  if (NOT TIDY_PROGRAM)
    message(WARNING "Could not find clang-tidy")
    message(STATUS "Feature: clang-tidy skipped")
  else (NOT TIDY_PROGRAM)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
    add_custom_target(clang-tidy ALL
      COMMAND clang-tidy
        --quiet
        "-header-filter=${PROJECT_SOURCE_DIR}/(include/Zemon|src|tests)/.*"
        -p "${PROJECT_BINARY_DIR}/compile_commands.json"
      )
    message(STATUS "Feature: clang-tidy enabled!")
  endif (NOT TIDY_PROGRAM)
else (WITH_TIDY)
  message(STATUS "Tidy is disabled!")
endif (WITH_TIDY)

if (WITH_CPPCHECK)
  find_program(CPPCHECK_PROGRAM cppcheck)
  if (NOT CPPCHECK_PROGRAM)
    message(WARNING "Could not find cppcheck!")
    message(STATUS "CppCheck is disabled!")
  else (NOT CPPCHECK_PROGRAM)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
    add_custom_target(cppcheck ALL
      COMMAND cppcheck
        --quiet
        --std=c++${CMAKE_CXX_STANDARD}
        --enable=all
        "--project=${PROJECT_BINARY_DIR}/compile_commands.json"
      )
    message(STATUS "Feature: cppcheck enabled")
  endif (NOT CPPCHECK_PROGRAM)
else()
  message(STATUS "Feature: cppcheck disabled")
endif()
