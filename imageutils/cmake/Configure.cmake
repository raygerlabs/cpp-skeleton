include_guard(GLOBAL)

include(${CMAKE_CURRENT_LIST_DIR}/modules/ProjectOptions.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/modules/ProjectSetup.cmake)

include(${CMAKE_CURRENT_LIST_DIR}/modules/CCacheConfig.cmake)

include(${CMAKE_CURRENT_LIST_DIR}/modules/CodeCoverage.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/modules/SanityChecks.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/modules/StaticChecks.cmake)

include(${CMAKE_CURRENT_LIST_DIR}/modules/CPackConfig.cmake)
