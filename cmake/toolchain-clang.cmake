#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#
#-------------------------------------------------------------------------------------------------------------------#
set(CMAKE_CONFIGURATION_TYPES
  "Debug;Profile;Release"
    CACHE INTERNAL
      "Build configuration types override"
    FORCE
)

if (NOT CMAKE_C_COMPILER)
  set(CMAKE_C_COMPILER clang)
endif()

if (NOT CMAKE_CXX_COMPILER)
  set(CMAKE_CXX_COMPILER clang++)
endif()

set(CMAKE_USER_MAKE_RULES_OVERRIDE
  "${CMAKE_CURRENT_LIST_DIR}/overrides-clang.cmake"
)
#-------------------------------------------------------------------------------------------------------------------#
#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#
