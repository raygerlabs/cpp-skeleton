if (NOT ENABLE_DOXYGEN)
  message(STATUS "Documentation disabled")
else()
  find_package(Doxygen)
  if (NOT DOXYGEN_FOUND)
    message(ERROR "Doxygen missing. Please install Doxygen first.")
    return()
  endif()

  find_package(LATEX COMPONENTS PDFLATEX)
  if(NOT EXISTS ${PDFLATEX_COMPILER})
    message(ERROR "LaTeX missing. Please install LaTeX first.")
    return()
  endif()

  set(source_files main.dox)
  set(extra_files DoxygenLayout.xml)
  set(header_files ${PROJECT_SOURCE_DIR}/include/imageutils/image_utils.h)

  foreach(path IN LISTS header_paths)
    string(APPEND DOXYGEN_INPUT " \\\n\"${path}\"")
  endforeach()
  foreach(file IN LISTS source_files)
    string(APPEND DOXYGEN_INPUT " \\\n\"${CMAKE_CURRENT_SOURCE_DIR}/${file}\"")
  endforeach()

  configure_file(Doxyfile.in ${PROJECT_BINARY_DIR}/Doxyfile @ONLY)

  add_custom_target(generate_docs)

  add_custom_target(generate_html
    COMMAND ${DOXYGEN_EXECUTABLE} ${PROJECT_BINARY_DIR}/Doxyfile
    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
    MAIN_DEPENDENCY ${PROJECT_BINARY_DIR}/Doxyfile
    DEPENDS ${header_files} ${source_files} ${extra_files}
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
endif()
