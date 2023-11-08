string(TOUPPER ${PROJECT_NAME} PACKAGE_PREFIX)

if(BUILD_SHARED_LIBS)
  set(PACKAGE_IS_A_DLL 1)
else()
  set(PACKAGE_IS_A_DLL 0)
endif()

# Write utility files
# Mainly for CI jobs to pickup
file(WRITE ${PROJECT_BINARY_DIR}/NAME ${PROJECT_NAME})
file(WRITE ${PROJECT_BINARY_DIR}/VERSION ${PROJECT_VERSION})

# Generate config header
configure_file(
  ${PROJECT_SOURCE_DIR}/src/PNGProcessorConfig.h.in
  ${PROJECT_BINARY_DIR}/include/PNGProcessor/PNGProcessorConfig.h
  @ONLY
)

# Generate version header
configure_file(
  ${PROJECT_SOURCE_DIR}/src/PNGProcessorConfigVersion.h.in
  ${PROJECT_BINARY_DIR}/include/PNGProcessor/PNGProcessorConfigVersion.h
  @ONLY
)
