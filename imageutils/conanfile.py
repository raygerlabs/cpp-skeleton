import os

from conan import ConanFile
from conan.tools.cmake import CMakeDeps, cmake_layout
from conan.tools.files import copy


class MainRecipe(ConanFile):
    name = "imageutils"
    version = "1.0"
    settings = "os", "arch", "compiler", "build_type"
    build_policy = "missing"

    options = {
        "shared": [True,False],
        "fPIC": [True, False],
        "with_asan": [True,False],
        "with_lsan": [True,False],
        "with_msan": [True,False],
        "with_tsan": [True,False],
        "with_ubsan": [True,False]
    }

    default_options = {
        "shared": False,
        "fPIC": True,
        "with_asan": False,
        "with_lsan": False,
        "with_msan": False,
        "with_tsan": False,
        "with_ubsan": False
    }


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
        build_mode = "dev" if self.settings.build_type == "Debug" else "ci"
        
        additional_mode = None
        
        if self.options.with_asan:
            additional_mode = "asan"
        elif self.options.with_lsan:
            additional_mode = "lsan"
        elif self.options.with_msan:
            additional_mode = "msan"
        elif self.options.with_tsan:
            additional_mode = "tsan"
        elif self.options.with_ubsan:
            additional_mode = "ubsan"
        
        if additional_mode:
            build_mode = f"{build_mode}-{additional_mode}"
        
        preset_name = f"{build_mode}-{self.settings.compiler}"
        
        self.run(f"cmake --preset {preset_name}", cwd=self.source_folder)
        self.run(f"cmake --build --preset {preset_name}", cwd=self.source_folder)
        self.run(f"ctest --preset {preset_name}", cwd=self.source_folder)


    def package(self):
        
        self.output.info(f"self.source_folder  = {self.source_folder}")
        self.output.info(f"self.build_folder   = {self.build_folder}")
        self.output.info(f"self.package_folder = {self.package_folder}")

        copy(self, "*.hpp",    os.path.join(self.source_folder, "include"), os.path.join(self.package_folder, "include"))
        copy(self, "*.dll",    os.path.join(self.build_folder),             os.path.join(self.package_folder, "bin"), keep_path=False)
        copy(self, "*.so*" ,   os.path.join(self.build_folder),             os.path.join(self.package_folder, "lib"), keep_path=False)
        copy(self, "*.dylib*", os.path.join(self.build_folder),             os.path.join(self.package_folder, "lib"), keep_path=False)
        copy(self, "*.lib",    os.path.join(self.build_folder),             os.path.join(self.package_folder, "lib"), keep_path=False)
        copy(self, "*.a",      os.path.join(self.build_folder),             os.path.join(self.package_folder, "lib"), keep_path=False)


    def package_info(self):
        self.cpp_info.libs = [self.name]

