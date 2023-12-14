########################################
# Build instructions

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

add_library(imageutils
    ${CMAKE_SOURCE_DIR}/include/imageutils/filters/brightness.hpp
    ${CMAKE_SOURCE_DIR}/include/imageutils/filters/contrast.hpp
    ${CMAKE_SOURCE_DIR}/include/imageutils/filters/horizontal_flip.hpp
    ${CMAKE_SOURCE_DIR}/include/imageutils/filters/vertical_flip.hpp
    ${CMAKE_SOURCE_DIR}/include/imageutils/filters/invert_colors.hpp
    ${CMAKE_SOURCE_DIR}/include/imageutils/filters/grayscale.hpp
    ${CMAKE_SOURCE_DIR}/include/imageutils/filters/resize.hpp
    ${CMAKE_SOURCE_DIR}/include/imageutils/image.hpp
    ${CMAKE_SOURCE_DIR}/include/imageutils/image_filters.hpp
    ${CMAKE_SOURCE_DIR}/include/imageutils/image_processor.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/filters/brightness.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/filters/contrast.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/filters/horizontal_flip.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/filters/vertical_flip.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/filters/invert_colors.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/filters/grayscale.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/filters/resize.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/image.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/image_processor.cpp
)

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
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
    DIRECTORY ${CMAKE_SOURCE_DIR}/include/imageutils
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
    EXPORT imageutils-targets
    DESTINATION ${CMAKE_INSTALL_DATADIR}/imageutils/cmake
    NAMESPACE imageutils::
)

configure_package_config_file(
    ${CMAKE_SOURCE_DIR}/cmake/config/imageutils-config.cmake.in
    ${PROJECT_BINARY_DIR}/imageutils-config.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_DATADIR}/imageutils/cmake
)

write_basic_package_version_file(
    ${PROJECT_BINARY_DIR}/imageutils-config-version.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

install(FILES
    ${CMAKE_BINARY_DIR}/imageutils-config.cmake
    ${CMAKE_BINARY_DIR}/imageutils-config-version.cmake
    DESTINATION ${CMAKE_INSTALL_DATADIR}/imageutils/cmake
)
