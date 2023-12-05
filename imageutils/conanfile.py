import os

from conan import ConanFile
from conan.tools.cmake import CMake, CMakeDeps, CMakeToolchain, cmake_layout
from conan.tools.files import copy

class MainRecipe(ConanFile):
    name = "imageutils"
    version = "1.0"
    settings = "os", "arch", "compiler", "build_type"
    build_policy = "missing"
    
    def export_sources(self):
        export_list = { 
          "CMakeLists.txt",
          "cmake/*", 
          "src/*", 
          "include/*",
          "tests/*",
          "resources/*"
          
        }
        for pattern in export_list:
            copy(self, pattern, self.recipe_folder, self.export_sources_folder)


    def layout(self):
        cmake_layout(self)


    def build_requirements(self):
        self.tool_requires("cmake/[>=3.15]")
        self.tool_requires("ninja/1.11.1")        
        self.test_requires("gtest/1.14.0")
        self.test_requires("benchmark/1.8.3")


    def requirements(self):
        self.requires("libjpeg-turbo/3.0.1")


    def generate(self):
        self._generate_deps()
        self._generate_toolchain()


    def build(self):
        cmake = self._configure_cmake()
        cmake.build()
        cmake.test()


    def package(self):
        cmake = self._configure_cmake()
        cmake.install()


    def package_info(self):
        self.cpp_info.libs = [self.name]


    def _generate_deps(self):
        deps = CMakeDeps(self)
        deps.generate()


    def _generate_toolchain(self) -> None:
        tc = CMakeToolchain(self, generator = "Ninja")
        tc.variables["ENABLE_TESTS"] = True
        tc.user_presets_path = False
        tc.generate()


    def _configure_cmake(self):
        cmake = CMake(self)
        cmake.configure()
        return cmake
