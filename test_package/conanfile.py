import os
from conan import ConanFile
from conan.tools.build import can_run
from conan.tools.files import copy
from conan.tools.cmake import CMake, cmake_layout

class JSONAdapterTestUtilitiesTestConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):
        self.requires(self.tested_reference_str)
        self.requires("gtest/1.14.0")
		
    def layout(self):
        cmake_layout(self)

    def generate(self):
        for dep in self.dependencies.values():
            copy(self, "*.dylib", dep.cpp_info.libdirs[0], self.build_folder)
            copy(self, "*.dll", dep.cpp_info.libdirs[0], self.build_folder)
            copy(self, "*.so*", dep.cpp_info.libdirs[0], self.build_folder)
		
    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def test(self):
        if can_run(self):
            cmd = os.path.join(self.cpp.build.bindir, "JSONAdapterPackageTest")
            self.run(cmd, env="conanrun")
