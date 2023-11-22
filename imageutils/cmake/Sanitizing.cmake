if (ENABLE_ASAN)
  message(STATUS "Address sanitizing enabled")
  add_compile_options("-fsanitize=address")
  add_link_options("-fsanitize=address")
else()
  message(STATUS "Address sanitizing disabled")
endif()

if (ENABLE_LSAN)
  if (NOT MSVC)
    message(STATUS "Leak sanitizing enabled")
    add_compile_options("-fsanitize=leak")
    add_link_options("-fsanitize=leak")
  else()
    message("Leak sanitizing is unsupported by Visual C/C++")
    message(STATUS "Leak sanitizing disabled")
    set(ENABLE_LSAN OFF)
  endif()
else()
  message(STATUS "Leak sanitizing disabled")
endif()

if (ENABLE_MSAN)
  if (NOT MSVC)
    message(STATUS "Memory sanitizing enabled")
    add_compile_options("-fsanitize=memory")
    add_link_options("-fsanitize=memory")
  else()
    message(STATUS "Memory sanitizing is unsupported by Visual C/C++")
    message(STATUS "Memory sanitizing disabled")
    set(ENABLE_MSAN OFF)
  endif()
else()
  message(STATUS "Memory sanitizing disabled")
endif()

if (ENABLE_TSAN)
  if (NOT MSVC)
    message(STATUS "Thread sanitizing enabled")
    add_compile_options("-fsanitize=thread")
    add_link_options("-fsanitize=thread")
  else()
    message(STATUS "Thread sanitizing is unsupported by Visual C/C++")
    message(STATUS "Thread sanitizing disabled")
    set(ENABLE_TSAN OFF)
  endif()
else()
   message(STATUS "Thread sanitizing disabled")
endif()

if (ENABLE_UBSAN)
  if (NOT MSVC)
    message(STATUS "UB sanitizing enabled")
    add_compile_options("-fsanitize=undefined")
    add_link_options("-fsanitize=undefined")
  else ()
    message(STATUS "UB Sanitizing is unsupported by Visual C/C++")
    message(STATUS "UB sanitizing disabled")
    set(ENABLE_UBSAN OFF)
  endif()
else()
  message(STATUS "UB sanitizing disabled")
endif()