[![build](https://github.com/raygerlabs/modern-cpp-init/actions/workflows/build.yaml/badge.svg)](https://github.com/raygerlabs/modern-cpp-init/actions/workflows/build.yaml)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)

# Modern C++ Template Library

This is a cross-platform project template for modern C and C++, designed to provide a robust and versatile foundation for building software across a variety of platforms and environments. It's a comprehensive solution that takes into account the diverse needs of modern software development.

## Prerequisites

To utilize this template, you'll need the following tools:
- [CMake](https://cmake.org/): An open-source, cross-platform family of tools designed to build, test, and package software.
- [Conan](https://conan.io/): A portable package manager, intended for C and C++ developers, but it is able to manage builds from source, dependencies, and precompiled binaries for any language.
- C/C++ compiler: Depending on your platform, you might use different compilers. Examples include [Visual Studio](https://visualstudio.microsoft.com/) for Windows, [gcc](https://gcc.gnu.org/) or [clang](https://clang.llvm.org/) for Linux.

## Purpose

The primary objective of this template is to provide a functional C/C++ project setup that can be easily integrated into real software projects. This integration aims to alleviate the developer's burden of project setup and infrastructure issues. The template caters to common use cases in modern software development, including coding, testing, QA, documentation, and deployment. It's designed to be flexible and adaptable, accommodating a wide range of project requirements and workflows.

We are committed to continuously improving and simplifying the design to facilitate project integration. We believe in the power of simplicity and usability, and we strive to make our template as user-friendly and intuitive as possible.

It's crucial to note that we **do not** aim to replace any existing build system or environment. Instead, our goal is to expedite and streamline the initial project setup. We understand that every project has unique needs and constraints, and our template is designed to be a helpful starting point, not a one-size-fits-all solution. We encourage developers to adapt and modify the template as needed to best suit their specific project requirements.

## Usage

This template is designed for the subsequent replacement of names, folders, and modules. Its modular design allows components to be easily swapped out. Each component is designed to function independently, ensuring that the removal of one does not impact the others. This flexibility allows for easy customization and adaptation to suit the specific needs of your project.

## Project Structure

The project comprises the following modules:
- `include/src`: This is the core library module where the primary functionality of the project resides. It contains the main codebase that the project is built upon.
- `benchmarks`: This module is used to measure the performance of the core library. It provides valuable insights into the efficiency and speed of the library's functions.
- `tests`: This module contains unit tests for the core library, located in the "test" folder. These tests are designed to verify the correctness of the library's individual units of code.
- `examples`: This module contains example code that demonstrates how to use the core API. It serves as a practical guide for developers who are new to the library.
- `integration`: This module contains integration tests for the core library, located in the "integration" folder. These tests are designed to check if the different modules of the library work correctly when combined.

## Workflows

The project supports multiple workflows. Depending on your preference, you can build the project accordingly. The current goal is to allow both Cmake and Conan to work interchangeably without any interference. This is achieved by integrating Conan into the Cmake project in a non-intrusive manner. This flexibility allows you to choose the workflow that best suits your development process and project requirements. Whether you prefer the comprehensive build system management of Cmake or the package management capabilities of Conan, this project template has got you covered.

### CMake

# TODO: Complete rework needed!

### Conan

# TODO: Complete rework needed!

## CMake Presets

# TODO: Complete rework needed!

## Supported compilers

We recommend using every available and reasonable set of warning options. Some warnings only work with optimizations enabled, or work better the higher the optimization setting is, for example `-Wnull-dereference`. Therefore, it is highly advisable to build the project with the **Profile** build type whenever possible.

#### GCC/Clang

For Clang, avoid using `-Weverything` in a production build. Even Clang developers discourage its use. Use it solely to discover whether a particular warning exists in the code.

The `-Weffc++` warning mode can sometimes be too noisy. For now, the preset adds this flag to the build.

##### Warnings

The following table lists the warning flags and their descriptions:

| Flag                       | Description                                                                                       | Support (gcc) | Support (clang)  |
|----------------------------|---------------------------------------------------------------------------------------------------|---------------|------------------|
| `-pedantic`                | Warn on language extensions                                                                       | X | X | 
| `-Werror`                  | Treat any warning as an error                                                                     | X | X |
| `-Wall -Wextra`            | Enable reasonable and standard warnings                                                           | X | X |
| `-Wshadow`                 | Warn if a variable declaration shadows one from a parent context                                  | X | X |
| `-Wnon-virtual-dtor`       | Warn if a class with virtual functions has a non-virtual destructor                               | X | X |
| `-Woverloaded-virtual`     | Warn if you overload (not override) a virtual function                                            | X | X |
| `-Wpedantic`               | Warn if non-standard C++ is used                                                                  | X | X (>=3.2) |
| `-Wmisleading-indentation` | Warn if indentation implies blocks where blocks do not exist                                      | X (>=6.0) | X |
| `-Wnull-dereference`       | Warn if a null dereference is detected                                                            | X | X |
| `-Wcast-align`             | Warn for potential performance problem casts                                                      | X | X |
| `-Wold-style-cast`         | Warn for c-style casts                                                                            | X | X |
| `-Wconversion`             | Warn for implicit conversions that may alter a value                                              | X | X |
| `-Wsign-conversion`        | Warn for implicit conversions that may change the sign of an integer value                        | X (>=4.3) | X |
| `-Wfloat-equal`            | Warn if `==` comparison is used between two `float` instead of comparing with appropriate epsilon | X | X |
| `-Wdouble-promotion`       | Warn if `float` is implicitly promoted to `double`                                                | X(>=4.6) | X(>=3.8) |
| `-Wformat=2`               | Warn on security issues around functions that format output (e.g., `printf`)                      | X | X |

The following flags would be great, but Clang tools don't support them yet:

| Flag                       | Description                                                                                       | Support (gcc) | Support (clang)  |
|----------------------------|---------------------------------------------------------------------------------------------------|---------------|------------------|
| `-Wduplicated-cond`        | Warn if `if` / `else` chain has duplicated conditions                                             | X (>=6.0) |  | 
| `-Wduplicated-branches`    | Warn if `if` / `else` branches have duplicated code                                               | X (>=7.0) |  | 
| `-Wlogical-op`             | Warn about logical operations being used where bitwise were probably wanted                       | X |  |
| `-Wuseless-cast`           | Warn if you perform a cast to the same type                                                       | X (>=4.8) |  |

##### Security

The preset aims for
- detect the maximum number of bugs or potential security problems.
- enable security mitigations in the produced binaries.
- enable runtime sanitizers to detect errors (overflows, race conditions, etc.) and make fuzzing more efficient.

Run debug/test builds with sanitizers enabled (see below in the instrumentation section)

| Flag                       | Description                                                                                       |
|----------------------------|---------------------------------------------------------------------------------------------------|
| `-D_FORTIFY_SOURCE=2`      | Enable buffer overrun checks (both compile- and run-time checks)                                  |

##### Performance

| Flag                       | Description                                                                                       |
|----------------------------|---------------------------------------------------------------------------------------------------|
| `-O3`                      | Always build with max optimization level                                                          |

#### Visual Studio

##### Warnings

Please note that the `/Wall` flag is not particularly useful as it generates too many warnings and also warns on files included from the standard library.

Instead, use `/permissive- /W4 /w14640` and consider the following flags:

| Flag                       | Description                                                                                       |
|----------------------------|---------------------------------------------------------------------------------------------------|
| `/W4`                      | Enable reasonable warning levels                                                                  |
| `/w14242`                  | Warn for implicit conversions that may alter a value                                              |
| `/w14254`                  | Warn for larger bit field assigned to a smaller bit field                                         |
| `/w14263`                  | Warn if you overload (not override) a virtual function                                            |
| `/w14265`                  | Warn if a class with virtual functions has a non-virtual destructor                               |
| `/w14287`                  | Warn if `unsigned` variable is used with negative value                                           |
| `/we4289`                  | Warn if a loop control variable declared in the for-loop is used outside its scope                |
| `/w14296`                  | Warn if `unsigned` variable is used in a comparison operation with zero                           |
| `/w14311`                  | Warn if 64-bit pointer is truncated                                                               |
| `/w14545`                  | Warn if ill-formed comma expression is detected (e.g., `*(&f), 10;`)                              |
| `/w14546`                  | Warn if ill-formed comma expression is detected (e.g., `if ( f, k )`)                             |
| `/w14547`                  | Warn if ill-formed comma expression is detected (e.g., `int l = (i != i,0)`)                      |
| `/w14549`                  | Warn if ill-formed comma expression is detected (e.g., `if ( i == 0, k )`)                        |
| `/w14555`                  | Warn if an expression has no effect (e.g., `1;` or `x;`)                                          |
| `/w14619`                  | Warn if non-existent warning is disabled                                                          |
| `/w14640`                  | Warn if static instance of an object is not thread-safe (e.g., `void f() { static X x; }`)        |
| `/w14826`                  | Warn if conversion between two types are signed extended and may cause undefined behaviour        |
| `/w14905`                  | Warn if unsafe cast is detected for LPSTR type (WIN32 API)                                        |
| `/w14906`                  | Warn if unsafe cast is detected for LPWSTR type (WIN32 API)                                       |
| `/w14928`                  | Warn if more than one user-defined conversion routine is found                                    |

##### Security

| Flag                       | Description                                                                                       |
|----------------------------|---------------------------------------------------------------------------------------------------|
| `/RTC1`                    | Enable run-time type checks                                                                       |
| `/GS`                      | Enable buffer security checks                                                                     |

##### Performance

The following flags are added to the build to enhance performance:

| Flag                       | Description                                                                                       |
|----------------------------|---------------------------------------------------------------------------------------------------|
| `/Gy`                      | Enable function-level linking                                                                     |
| `/GF`                      | Enable string pooling                                                                             |
| `/MP`                      | Build with multiple processors                                                                    |
| `/Ox`                      | Enable aggressive optimization                                                                    |

## Instrumentation

TODO

## Documentation

TODO

### Doxygen

TODO
