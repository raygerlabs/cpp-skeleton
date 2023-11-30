########################################
# Build instructions

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(_HEADER_LIST
  ${CMAKE_SOURCE_DIR}/include/imageutils/filters/JPEG_Brightness.hpp
  ${CMAKE_SOURCE_DIR}/include/imageutils/filters/JPEG_Contrast.hpp
  ${CMAKE_SOURCE_DIR}/include/imageutils/filters/JPEG_FlipH.hpp
  ${CMAKE_SOURCE_DIR}/include/imageutils/filters/JPEG_FlipV.hpp
  ${CMAKE_SOURCE_DIR}/include/imageutils/filters/JPEG_Grayscale.hpp
  ${CMAKE_SOURCE_DIR}/include/imageutils/filters/JPEG_Invert.hpp
  ${CMAKE_SOURCE_DIR}/include/imageutils/filters/JPEG_Resize.hpp
  ${CMAKE_SOURCE_DIR}/include/imageutils/JPEG_Filter.hpp
  ${CMAKE_SOURCE_DIR}/include/imageutils/JPEG_Image.hpp
  ${CMAKE_SOURCE_DIR}/include/imageutils/JPEG_Processor.hpp
  ${CMAKE_SOURCE_DIR}/include/imageutils/JPEG.hpp
)

set(_SOURCE_LIST
  ${CMAKE_CURRENT_SOURCE_DIR}/filters/JPEG_Brightness.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/filters/JPEG_Contrast.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/filters/JPEG_FlipH.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/filters/JPEG_FlipV.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/filters/JPEG_Invert.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/filters/JPEG_Grayscale.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/filters/JPEG_Resize.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/JPEG_Image.cpp
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
