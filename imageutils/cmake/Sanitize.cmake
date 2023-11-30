if (ENABLE_ASAN AND NOT MSVC)
  message("Address sanitizer: on")
  add_compile_options(-fsanitize=address)
  add_link_options(-fsanitize=address)
else()
  if (MSVC)
    message("Visual Studio does not support address sanitizer")
  endif()
  message("Address sanitizer: off")
endif()

if (ENABLE_LSAN AND NOT MSVC)
  message("Leak sanitizer: on")
  add_compile_options(-fsanitize=leak)
  add_link_options(-fsanitize=leak)
else()
  if (MSVC)
    message("Visual Studio does not support leak sanitizer")
  endif()
  message("Leak sanitizer: off")
endif()

if (ENABLE_MSAN AND NOT MSVC)
  message("Memory sanitizer: on")
  add_compile_options(-fsanitize=memory)
  add_link_options(-fsanitize=memory)
else()
  if (MSVC)
    message("Visual Studio does not support memory sanitizer")
  endif()
  message("Memory sanitizer: off")
endif()

if (ENABLE_TSAN AND NOT MSVC)
  message("Thread sanitizer: on")
  add_compile_options(-fsanitize=thread)
  add_link_options(-fsanitize=thread)
else()
  if (MSVC)
    message("Visual Studio does not support thread sanitizer")
  endif()
  message("Thread sanitizer: off")
endif()

if (ENABLE_UBSAN AND NOT MSVC)
  message(STATUS "UB sanitizer: on")
  add_compile_options(-fsanitize=undefined)
  add_link_options(-fsanitize=undefined)
else()
  if (MSVC)
    message("Visual Studio does not support UB sanitizer")
  endif()
  message("UB sanitizer: off")
endif()