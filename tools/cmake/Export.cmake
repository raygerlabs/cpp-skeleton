#------------------------------------------------------------------------------

# Generate export configuration
# .. for the install-tree

file(RELATIVE_PATH
  INSTALL_PREFIX_REL2CONFIG_DIR
  "${CMAKE_INSTALL_PREFIX}/${PACKAGE_INSTALL_CONFIGDIR}"
  "${CMAKE_INSTALL_PREFIX}"  
)

configure_file(
  "${PROJECT_SOURCE_DIR}/tools/cmake/config/PNGProcessorConfig.cmake.in"
  "${PROJECT_BINARY_DIR}/PNGProcessorConfig.install.cmake"
  @ONLY
)

install (
  FILES "${PROJECT_BINARY_DIR}/PNGProcessorConfig.install.cmake"
  RENAME "PNGProcessorConfig.cmake"
  DESTINATION ${PACKAGE_INSTALL_CONFIGDIR}
)

install (
  EXPORT "PNGProcessorTargets"
  NAMESPACE ${PROJECT_NAME}::
  DESTINATION ${PACKAGE_INSTALL_CONFIGDIR}
)

#------------------------------------------------------------------------------
# .. for the build-tree

set(INSTALL_PREFIX_REL2CONFIG_DIR .)
configure_file(
  "${PROJECT_SOURCE_DIR}/tools/cmake/config/PNGProcessorConfig.cmake.in"
  "${PROJECT_BINARY_DIR}/PNGProcessorConfig.cmake"
  @ONLY
)
export(PACKAGE ${PROJECT_NAME})

#------------------------------------------------------------------------------
# .. for both

configure_file(
  "${PROJECT_SOURCE_DIR}/tools/cmake/config/PNGProcessorConfigVersion.cmake.in"
  "${PROJECT_BINARY_DIR}/PNGProcessorConfigVersion.cmake"
  @ONLY
)

install (
  FILES "${PROJECT_BINARY_DIR}/PNGProcessorConfigVersion.cmake"
  DESTINATION ${PACKAGE_INSTALL_CONFIGDIR}
)
