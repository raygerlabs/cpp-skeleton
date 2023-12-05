import os

from conan import ConanFile
from conan.tools.cmake import CMakeDeps, cmake_layout
from conan.tools.files import copy


class MainRecipe(ConanFile):
    name = "imageutils"
    version = "1.0"
    settings = "os", "arch", "compiler", "build_type"
    build_policy = "missing"


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
        self.run(f"cmake --workflow --fresh --preset {preset_name}", cwd=self.source_folder)


    def package(self):
        copy(self, "*.hpp",    os.path.join(self.source_folder, "include"), os.path.join(self.package_folder, "include"))
        copy(self, "*.h",      os.path.join(self.source_folder, "include"), os.path.join(self.package_folder, "include"))
        copy(self, "*.dll",    os.path.join(self.source_folder, "build"),   os.path.join(self.package_folder, "bin"), keep_path=False)
        copy(self, "*.so*" ,   os.path.join(self.source_folder, "build"),   os.path.join(self.package_folder, "lib"), keep_path=False)
        copy(self, "*.dylib*", os.path.join(self.source_folder, "build"),   os.path.join(self.package_folder, "lib"), keep_path=False)
        copy(self, "*.lib",    os.path.join(self.source_folder, "build"),   os.path.join(self.package_folder, "lib"), keep_path=False)
        copy(self, "*.a",      os.path.join(self.source_folder, "build"),   os.path.join(self.package_folder, "lib"), keep_path=False)


    def package_info(self):
        self.cpp_info.libs = [self.name]

