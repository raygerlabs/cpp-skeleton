if (NOT WIN32)
  find_package(Doxygen)
  if (NOT DOXYGEN_FOUND)
    message(FATAL_ERROR "Could not find Doxygen!")
  endif()
  find_package(LATEX COMPONENTS PDFLATEX)
  if(NOT EXISTS ${PDFLATEX_COMPILER})
    message(FATAL_ERROR "Could not find Latex!")
  endif()
  message(STATUS "API Documentation enabled")
  set(_SOURCE_FILES main.dox)
  set(_HEADER_FILES
      ${CMAKE_SOURCE_DIR}/include/imageutils/filters/brightness.hpp
      ${CMAKE_SOURCE_DIR}/include/imageutils/filters/contrast.hpp
      ${CMAKE_SOURCE_DIR}/include/imageutils/filters/horizontal_flip.hpp
      ${CMAKE_SOURCE_DIR}/include/imageutils/filters/vertical_flip.hpp
      ${CMAKE_SOURCE_DIR}/include/imageutils/filters/grayscale.hpp
      ${CMAKE_SOURCE_DIR}/include/imageutils/filters/invert_colors.hpp
      ${CMAKE_SOURCE_DIR}/include/imageutils/filters/resize.hpp
      ${CMAKE_SOURCE_DIR}/include/imageutils/image.hpp
      ${CMAKE_SOURCE_DIR}/include/imageutils/image_filters.hpp
      ${CMAKE_SOURCE_DIR}/include/imageutils/image_processor.hpp
  )
  
  configure_file(Doxyfile.in ${PROJECT_BINARY_DIR}/Doxyfile @ONLY)
  add_custom_target(generate_doc ALL)
  add_custom_target(generate_html
      COMMAND ${DOXYGEN_EXECUTABLE} ${PROJECT_BINARY_DIR}/Doxyfile
      WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
      MAIN_DEPENDENCY ${PROJECT_BINARY_DIR}/Doxyfile
      DEPENDS ${_HEADER_FILES} ${_SOURCE_FILES}
      COMMENT "Generating HTML documentation"
      VERBATIM
  )
  add_custom_target(generate_pdf
      COMMAND make pdf
      COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${PROJECT_BINARY_DIR}/docs/latex/refman.pdf
        ${PROJECT_BINARY_DIR}/docs/${PROJECT_NAME}.pdf
      WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/docs/latex
      DEPENDS generate_html
      COMMENT "Generating PDF documentation"
      VERBATIM
  )
  add_dependencies(generate_doc generate_html)
  add_dependencies(generate_doc generate_pdf)
else()
  message(WARNING "API documentation is unsupported on Windows!")
  message(STATUS "API Documentation disabled")
  set(ENABLE_DOCUMENTATION OFF)
endif ()
