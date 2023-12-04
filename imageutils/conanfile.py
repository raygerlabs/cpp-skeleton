from os.path import join

from conan import ConanFile
from conan.tools.cmake import CMakeDeps, cmake_layout
from conan.tools.files import copy


class MainRecipe(ConanFile):
    name = "imageutils"
    version = "1.0"
    settings = "os", "arch", "compiler", "build_type"
    build_policy = "missing"


    @property
    def _source_subfolder(self):
        return "source_subfolder"


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


    def build(self):
        config_mode = "dev" if self.settings.build_type == "Debug" else "ci"
        preset_name = f"{config_mode}-{self.settings.compiler}"
        self.run("cmake --version")
        self.run("ninja --version")
        self.run(f"cmake --workflow --fresh --preset {preset_name}", cwd=self.source_folder)


    def package(self):
        copy(self, pattern="*.*",      dst=join(self.package_folder, "include"), src=join(self.source_folder, "include"))
        copy(self, pattern="*.lib",    dst=join(self.package_folder, "lib"),     src=self.build_folder, keep_path=False)
        copy(self, pattern="*.a",      dst=join(self.package_folder, "lib"),     src=self.build_folder, keep_path=False)
        copy(self, pattern="*.dylib*", dst=join(self.package_folder, "lib"),     src=self.build_folder, keep_path=False)
        copy(self, pattern="*.so*",    dst=join(self.package_folder, "lib"),     src=self.build_folder, keep_path=False)
        copy(self, pattern="*.dll",    dst=join(self.package_folder, "bin"),     src=self.build_folder, keep_path=False)


    def package_info(self):
        self.cpp_info.libs = [self.name]
        self.cpp_info.set_property("cmake_file_name", self.name)
        self.cpp_info.set_property("cmake_target_name", f"{self.name}::{self.name}")
        self.cpp_info.names["cmake_find_package"] = self.name
        self.cpp_info.names["cmake_find_package_multi"] = self.name
