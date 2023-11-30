if (ENABLE_ASAN)
if (NOT MSVC)
  add_compile_options(-fsanitize=address)
  add_link_options(-fsanitize=address)
  message("Address sanitizer: on")
else (NOT MSVC)
  message("Address sanitizer unsupported!")
  message("Address sanitizer: off")
endif(NOT MSVC)
else (ENABLE_ASAN)
  message("Address sanitizer: off")
endif(ENABLE_ASAN)

if (ENABLE_LSAN)
if (NOT MSVC)
  add_compile_options(-fsanitize=leak)
  add_link_options(-fsanitize=leak)
  message("Leak sanitizer: on")
else (NOT MSVC)
  message("Leak sanitizer unsupported!")
  message("Leak sanitizer: off")
endif(NOT MSVC)
else (ENABLE_LSAN)
  message("Leak sanitizer: off")
endif(ENABLE_LSAN)

if (ENABLE_MSAN)
if (NOT MSVC OR NOT UNIX)
  add_compile_options(-fsanitize=memory)
  add_link_options(-fsanitize=memory)
  message("Memory sanitizer: on")
else ()
  message("Memory sanitizer unsupported!")
  message("Memory sanitizer: off")
endif(NOT MSVC OR NOT UNIX)
else (ENABLE_MSAN)
  message("Memory sanitizer: off")
endif(ENABLE_MSAN)

if (ENABLE_TSAN)
if (NOT MSVC)
  add_compile_options(-fsanitize=thread)
  add_link_options(-fsanitize=thread)
  message("Thread sanitizer: on")
else (NOT MSVC)
  message("Thread sanitizer unsupported!")
  message("Thread sanitizer: off")
endif(NOT MSVC)
else()
  message("Thread sanitizer: off")
endif(ENABLE_TSAN)

if (ENABLE_UBSAN)
if (NOT MSVC)
  add_compile_options(-fsanitize=undefined)
  add_link_options(-fsanitize=undefined)
  message(STATUS "UB sanitizer: on")
else (NOT MSVC)
  message("UB sanitizer unsupported!")
  message("UB sanitizer: off")
endif(NOT MSVC)
else (ENABLE_UBSAN)
  message(STATUS "UB sanitizer: off")
endif(ENABLE_UBSAN)
