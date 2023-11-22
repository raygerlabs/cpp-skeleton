from conan import ConanFile
from conan.tools.build import cross_building
from conan.tools.cmake import CMake, CMakeDeps, CMakeToolchain, cmake_layout
from conan.tools.files import collect_libs, rmdir, copy
from os import path

class MainRecipe(ConanFile):
  name = "imageutils"
  version = "1.0"
  topics = ("image-processing")
  settings = "os", "arch", "compiler", "build_type"

  def export_sources(self):
    copy(self, "CMakeLists.txt", src=self.recipe_folder, dst=self.export_sources_folder)
    copy(self, "src/*", src=self.recipe_folder, dst=self.export_sources_folder)
    copy(self, "include/*", src=self.recipe_folder, dst=self.export_sources_folder)
    copy(self, "resources/*", src=self.recipe_folder, dst=self.export_sources_folder)
    copy(self, "cmake/*", src=self.recipe_folder, dst=self.export_sources_folder)
    copy(self, "tests/unit_tests/*", src=self.recipe_folder, dst=self.export_sources_folder)

  def build_requirements(self):
    self.build_requires("cmake/[>=3.15]")
    self.build_requires("doxygen/[>=1.9.4]")
    self.build_requires("cppcheck/[>=2.12.1]")
    self.test_requires("gtest/1.14.0")
    self.test_requires("benchmark/1.8.3")

  def requirements(self):
    self.requires("libjpeg-turbo/3.0.1", transitive_headers=True, transitive_libs=True)

  def layout(self):
    cmake_layout(self)

  def generate(self):
    deps = CMakeDeps(self)
    deps.generate()
    tc = CMakeToolchain(self)
    tc.user_presets_path = "ConanPresets.json"
    tc.generate()

  def configure_cmake(self):
    cmake = CMake(self)
    cmake.configure(variables={"ENABLE_TESTS": "ON"})
    return cmake

  def build(self):
    cmake = self.configure_cmake()
    cmake.build()
    cmake.test()

  def package(self):
    cmake = self.configure_cmake()
    cmake.install()
    rmdir(self, path.join(self.package_folder, "lib", "cmake"))

  def package_id(self):
    self.info.clear()

  def package_info(self):
    self.cpp_info.libs = ["imageutils"]
    self.cpp_info.set_property("cmake_file_name", "imageutils")
    self.cpp_info.set_property("cmake_target_name", "imageutils::imageutils")
    
    self.cpp_info.names["cmake_find_package"] = "imageutils"
    self.cpp_info.names["cmake_find_package_multi"] = "imageutils"