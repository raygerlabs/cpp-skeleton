import os
from conan import ConanFile
from conan.tools.cmake import CMake, CMakeDeps, CMakeToolchain, cmake_layout
from conan.tools.files import copy, load, rmdir

class MainRecipe(ConanFile):
  settings = "os", "arch", "compiler", "build_type"
  exports_sources = "name.txt", "version.txt", "CMakeLists.txt", "cmake/*", "src/*", "include/*", "tests/*"

  def set_name(self):
    self.name = load(self, os.path.join(self.recipe_folder, "name.txt"))

  def set_version(self):
    self.version = load(self, os.path.join(self.recipe_folder, "version.txt"))

  def export_sources(self):
    copy(self, "name.txt", self.recipe_folder, self.export_sources_folder)
    copy(self, "version.txt", self.recipe_folder, self.export_sources_folder)
    copy(self, "CMakeLists.txt", self.recipe_folder, self.export_sources_folder)
    copy(self, "cmake/*", self.recipe_folder, self.export_sources_folder)
    copy(self, "include/*", self.recipe_folder, self.export_sources_folder)
    copy(self, "src/*", self.recipe_folder, self.export_sources_folder)
    copy(self, "tests/*", self.recipe_folder, self.export_sources_folder)
    copy(self, "resources/*", self.recipe_folder, self.export_sources_folder)

  def requirements(self):
    self.requires("libjpeg-turbo/[>=3.0]", transitive_headers=True, transitive_libs=True)
    self.test_requires("gtest/[>=1.14]")

  def layout(self):
    cmake_layout(self)

  def generate(self):
    self._generate_toolchain()
    self._generate_cmakedeps()

  def build(self):
    cmake = self._configure_cmake()
    cmake.build()
    cmake.test()

  def package(self):
    cmake = self._configure_cmake()
    cmake.install()
    rmdir(self, os.path.join(self.package_folder, "lib", "cmake"))

  def package_info(self):
    self.cpp_info.libs = [self.name]

  def _generate_toolchain(self):
    tc = CMakeToolchain(self)
    tc.variables["WITH_TESTS"] = True
    tc.user_presets_path = None
    tc.generate()    

  def _generate_cmakedeps(self):
    deps = CMakeDeps(self)
    deps.generate()

  def _configure_cmake(self):
    cmake = CMake(self)
    cmake.configure()
    return cmake