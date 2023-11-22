########################################
# Build instructions

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(_HEADER_LIST
  ${CMAKE_SOURCE_DIR}/include/imageutils/filters/JPEGBrightness.hpp
  ${CMAKE_SOURCE_DIR}/include/imageutils/filters/JPEGContrast.hpp
  ${CMAKE_SOURCE_DIR}/include/imageutils/filters/JPEGFlipH.hpp
  ${CMAKE_SOURCE_DIR}/include/imageutils/filters/JPEGFlipV.hpp
  ${CMAKE_SOURCE_DIR}/include/imageutils/filters/JPEGGrayscale.hpp
  ${CMAKE_SOURCE_DIR}/include/imageutils/filters/JPEGInvert.hpp
  ${CMAKE_SOURCE_DIR}/include/imageutils/filters/JPEGResize.hpp
  ${CMAKE_SOURCE_DIR}/include/imageutils/JPEGImage.hpp
  ${CMAKE_SOURCE_DIR}/include/imageutils/JPEGFilter.hpp
  ${CMAKE_SOURCE_DIR}/include/imageutils/JPEGProcessor.hpp
  ${CMAKE_SOURCE_DIR}/include/imageutils/JPEGReader.hpp
  ${CMAKE_SOURCE_DIR}/include/imageutils/JPEGWriter.hpp
)

set(_SOURCE_LIST
  ${CMAKE_CURRENT_SOURCE_DIR}/JPEGProcessor.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/JPEGReader.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/JPEGWriter.cpp
)

add_library(imageutils ${_HEADER_LIST} ${_SOURCE_LIST})

set_target_properties(${PROJECT_NAME} PROPERTIES
  VERSION ${PROJECT_VERSION}
  FOLDER "Runtime"
)
source_group(TREE ${CMAKE_SOURCE_DIR} FILES ${_HEADER_LIST} ${_SOURCE_LIST})

target_include_directories(imageutils
PUBLIC
  $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}
)

find_package(libjpeg-turbo REQUIRED CONFIG)
target_link_libraries(imageutils libjpeg-turbo::libjpeg-turbo)

########################################
# Installation instructions

install(
  TARGETS imageutils
  EXPORT imageutils-targets
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
  DIRECTORY ${CMAKE_SOURCE_DIR}/include
  DESTINATION ${CMAKE_INSTALL_PREFIX}
)

install(
  EXPORT imageutils-targets
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake
  NAMESPACE imageutils::
)

configure_package_config_file(
  ${CMAKE_SOURCE_DIR}/cmake/config/imageutils-config.cmake.in
  ${PROJECT_BINARY_DIR}/imageutils-config.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake
)

write_basic_package_version_file(
  ${PROJECT_BINARY_DIR}/imageutils-config-version.cmake
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY AnyNewerVersion
)

install(
  FILES
  ${CMAKE_BINARY_DIR}/imageutils-config.cmake
  ${CMAKE_BINARY_DIR}/imageutils-config-version.cmake
  DESTINATION ${CMAKE_INSTALL_DATADIR}/imageutils/cmake
)
