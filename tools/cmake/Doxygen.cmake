if (ENABLE_DOXYGEN)
  message(STATUS "API documentation is enabled!")
  
  add_custom_target(doc)
  set_target_properties(doc
  PROPERTIES
    FOLDER "Tools"
  )
  find_package(Doxygen)
  if(DOXYGEN_FOUND)
    # Generate Doxygen configuration file
    configure_file(${PROJECT_SOURCE_DIR}/docs/Doxyfile.in
      ${PROJECT_BINARY_DIR}/Doxyfile
      @ONLY)

    # Cmake target for generating doxygen API doc
    add_custom_target(doxydoc
      WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
      COMMAND ${DOXYGEN_EXECUTABLE} ${PROJECT_BINARY_DIR}/Doxyfile
      COMMENT "Generating API documentation"
      VERBATIM)
    add_dependencies(doc doxydoc)
  else()
    message(ERROR "Doxygen is missing!"
                  "Cannot generate API documentation!")
  endif()

  find_package(LATEX COMPONENTS PDFLATEX)
  if(NOT EXISTS ${PDFLATEX_COMPILER})
    message(ERROR "Latex is missing!" 
                  "Cannot generate API documentation!")
  else()
    # CMake target for generating PDF version of user manual
    add_custom_target(pdfdoc
      COMMAND make pdf
      COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${PROJECT_BINARY_DIR}/doc/latex/refman.pdf
        ${PROJECT_BINARY_DIR}/doc/${PROJECT_NAME}-user-manual.pdf
      WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/doc/latex
      DEPENDS doxydoc
      COMMENT "Generating PDF"
      VERBATIM)
    add_dependencies(doc pdfdoc)
  endif()
endif()