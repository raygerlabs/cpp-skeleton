from conan import ConanFile
from conan.tools.build import cross_building
from conan.tools.cmake import CMake, CMakeDeps, CMakeToolchain, cmake_layout
from conan.tools.files import collect_libs, rmdir, copy

class MainRecipe(ConanFile):
  name = "imageutils"
  version = "1.0"
  settings = "os", "arch", "compiler", "build_type"

  def export_sources(self) -> None:
    src_files = [
      "CMakeLists.txt",
      "src/*",
      "include/*",
      "resources/*",
      "cmake/*",
      "tests/*"
    ]
    for pattern in src_files:
      self.copy(pattern, src=self.recipe_folder, dst=self.export_sources_folder)

  def requirements(self) -> None:
    self.requires("libjpeg-turbo/3.0.1", transitive_headers=True, transitive_libs=True)

  def build_requirements(self) -> None:
    self.test_requires("gtest/1.14.0")
    self.test_requires("benchmark/1.8.3")
    self.tool_requires("cmake/[>=3.15]")
    self.tool_requires("doxygen/[>=1.9.4]")

  def layout(self) -> None:
    cmake_layout(self)

  def generate(self) -> None:
    self._generate_toolchain()
    self._generate_cmakedeps()

  def build(self) -> None:
    cmake = self._configure_cmake()
    cmake.build()
    if self.should_test:
      cmake.test()

  def package(self) -> None:
    cmake = self._configure_cmake()
    cmake.install()
    rmdir(self, path.join(self.package_folder, "lib", "cmake"))

  def package_id(self) -> None:
    self.info.clear()

  def package_info(self) -> None:
    self.cpp_info.libs = [self.name]
    self.cpp_info.set_property("cmake_file_name", self.name)
    self.cpp_info.set_property("cmake_target_name", f"{self.name}::{self.name}")
    self.cpp_info.names["cmake_find_package"] = self.name
    self.cpp_info.names["cmake_find_package_multi"] = self.name

  def _generate_toolchain(self) -> None:
    tc = CMakeToolchain(self)
    tc.user_presets_path = None
    tc.generate()    

  def _generate_cmakedeps(self) -> None:
    deps = CMakeDeps(self)
    deps.generate()

  def _configure_cmake(self) -> CMake:
    cmake = CMake(self)
    cmake.configure(variables={
      "BUILD_SHARED_LIBS": self.options.shared,
      "BUILD_STATIC_LIBS": not self.options.shared,
      "ENABLE_TESTS": self.should_test,
      "ENABLE_BENCHMARKS": False,
      "ENABLE_EXAMPLES": False,
      "ENABLE_SANITIZERS": False,
      "ENABLE_COVERAGE": self.should_test,
      "ENABLE_DOCS": True,
      "ENABLE_PACKAGE": False
    })
    return cmake
