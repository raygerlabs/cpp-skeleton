import os

from conan import ConanFile
from conan.tools.cmake import CMake, CMakeDeps, CMakeToolchain, cmake_layout
from conan.tools.files import copy


class MainRecipe(ConanFile):
    name = "imageutils"
    version = "1.0"
    settings = "os", "arch", "compiler", "build_type"
    build_policy = "missing"

    @property
    def should_test(self):
        return not self.conf.get("tools.build:skip_test", default=False)

    def export_sources(self):
        export_list = { 
          "CMakePresets.json",
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
        self.tool_requires("doxygen/1.9.4")
        self.test_requires("gtest/1.14.0")
        self.test_requires("benchmark/1.8.3")


    def requirements(self):
        self.requires("libjpeg-turbo/3.0.1")


    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self, generator = "Ninja")
        tc.variables["ENABLE_TESTS"] = self.should_test
        tc.user_presets_path = False
        tc.generate()


    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        if self.should_test:
            cmake.test()


    def package(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.install()


    def package_info(self):
        self.cpp_info.libs = [self.name]

