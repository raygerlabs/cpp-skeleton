if (NOT ENABLE_DOXYGEN)
  message(STATUS "Doxygen: off")
  return()
endif()

if (WIN32)
  message(WARNING "Doxygen is not supported for Windows")
  message(STATUS "Doxygen: off")
  set(ENABLE_DOXYGEN OFF)
  return()
endif()

find_package(Doxygen)
if (NOT DOXYGEN_FOUND)
  message(FATAL_ERROR "Doxygen missing. Please install Doxygen first.")
endif()

find_package(LATEX COMPONENTS PDFLATEX)
if(NOT EXISTS ${PDFLATEX_COMPILER})
  message(FATAL_ERROR "LaTeX missing. Please install LaTeX first.")
endif()

message(STATUS "Doxygen: on")

set(source_files main.dox)
set(header_files
  ${CMAKE_SOURCE_DIR}/include/imageutils/filters/JPEG_Brightness.hpp
  ${CMAKE_SOURCE_DIR}/include/imageutils/filters/JPEG_Contrast.hpp
  ${CMAKE_SOURCE_DIR}/include/imageutils/filters/JPEG_FlipH.hpp
  ${CMAKE_SOURCE_DIR}/include/imageutils/filters/JPEG_FlipV.hpp
  ${CMAKE_SOURCE_DIR}/include/imageutils/filters/JPEG_Grayscale.hpp
  ${CMAKE_SOURCE_DIR}/include/imageutils/filters/JPEG_Invert.hpp
  ${CMAKE_SOURCE_DIR}/include/imageutils/filters/JPEG_Resize.hpp
  ${CMAKE_SOURCE_DIR}/include/imageutils/JPEG.hpp
  ${CMAKE_SOURCE_DIR}/include/imageutils/JPEG_Filter.hpp
  ${CMAKE_SOURCE_DIR}/include/imageutils/JPEG_Image.hpp
  ${CMAKE_SOURCE_DIR}/include/imageutils/JPEG_Processor.hpp
)

foreach(file IN LISTS source_files)
  string(APPEND DOXYGEN_INPUT " \\\n\"${CMAKE_CURRENT_SOURCE_DIR}/${file}\"")
endforeach()

configure_file(Doxyfile.in ${PROJECT_BINARY_DIR}/Doxyfile @ONLY)

add_custom_target(generate_docs)

add_custom_target(generate_html
  COMMAND ${DOXYGEN_EXECUTABLE} ${PROJECT_BINARY_DIR}/Doxyfile
  WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
  MAIN_DEPENDENCY ${PROJECT_BINARY_DIR}/Doxyfile
  DEPENDS ${header_files} ${source_files}
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

set_target_properties(generate_docs PROPERTIES FOLDER "Tools")
set_target_properties(generate_html PROPERTIES FOLDER "Tools")
set_target_properties(generate_pdf PROPERTIES FOLDER "Tools")

add_dependencies(generate_docs generate_html)
add_dependencies(generate_docs generate_pdf)
