add_library(PNGProcessor)

target_sources(PNGProcessor
PRIVATE
  PNGProcessor.cpp
PUBLIC INTERFACE
  FILE_SET HEADERS
    BASE_DIRS
      ${PROJECT_SOURCE_DIR}/include
      ${PROJECT_BINARY_DIR}/include
    FILES
      ${PROJECT_SOURCE_DIR}/include/PNGProcessor/PNGProcessor.h
      ${PROJECT_BINARY_DIR}/include/PNGProcessor/PNGProcessorConfig.h
      ${PROJECT_BINARY_DIR}/include/PNGProcessor/PNGProcessorConfigVersion.h
)

target_include_directories(PNGProcessor
PUBLIC
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>
  $<INSTALL_INTERFACE:${PACKAGE_INSTALL_INCLUDEDIR}>
PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}
)

find_package(RapidJSON CONFIG REQUIRED)
find_package(PNG CONFIG REQUIRED)
find_package(ZLIB CONFIG REQUIRED)
target_link_libraries(PNGProcessor
  rapidjson
  PNG::PNG
  ZLIB::ZLIB
)

set_target_properties(PNGProcessor
  PROPERTIES
    FOLDER "Runtime"
)
get_target_property(SOURCES PNGProcessor SOURCES)
get_target_property(INCLUDES PNGProcessor HEADER_SET_PNGPROCESSOR)
source_group(TREE ${CMAKE_SOURCE_DIR} FILES "${SOURCES}" "${INCLUDES}")

install(
  TARGETS PNGProcessor
  EXPORT PNGProcessorTargets
  RUNTIME DESTINATION "${PACKAGE_INSTALL_BINDIR}"
  LIBRARY DESTINATION "${PACKAGE_INSTALL_LIBDIR}"
  ARCHIVE DESTINATION "${PACKAGE_INSTALL_LIBDIR}"
  INCLUDES DESTINATION "${PACKAGE_INSTALL_INCLUDEDIR}"
  FILE_SET HEADERS
)

export(
  TARGETS PNGProcessor
  NAMESPACE ${PROJECT_NAME}::
  FILE "${PROJECT_BINARY_DIR}/PNGProcessorTargets.cmake"
)
