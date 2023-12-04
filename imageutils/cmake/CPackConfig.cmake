include_guard()

set(CPACK_PACKAGE_NAME          ${PROJECT_NAME})
set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
set(CPACK_PACKAGE_VERSION       ${PROJECT_VERSION})

set(CPACK_VERBATIM_VARIABLES    ON)
set(CPACK_STRIP_FILES           ON)

include(CPack)

set(CPACK_PACKAGE_FILE_NAME ${CPACK_PACKAGE_NAME})
string(APPEND CPACK_PACKAGE_FILE_NAME "-${CPACK_PACKAGE_VERSION}")
string(APPEND CPACK_PACKAGE_FILE_NAME "-${CPACK_SYSTEM_NAME}")
string(APPEND CPACK_PACKAGE_FILE_NAME "-${CPACK_SYSTEM_PROCESSOR}")
string(TOLOWER "${CPACK_PACKAGE_FILE_NAME}" CPACK_PACKAGE_FILE_NAME)
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_FILE_NAME}" CACHE STRING "")

message(STATUS "CPACK_PACKAGE_FILE_NAME = ${CPACK_PACKAGE_FILE_NAME}")
