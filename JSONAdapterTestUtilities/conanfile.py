import os
from conan import ConanFile
from conan.tools.cmake import CMake, CMakeDeps, CMakeToolchain, cmake_layout
from conan.tools.files import copy, collect_libs

required_conan_version = ">=2.0.0"


class JSONAdapterTestUtilitiesConan(ConanFile):
    name = "json-adapter-test-utilities"
    description = "Test utilities for library-agnostic API for C++ to work with JSON documents"
    url = "https://github.com/systelab/cpp-json-adapter"
    homepage = "https://github.com/systelab/cpp-json-adapter"
    author = "CSW <csw@werfen.com>"
    topics = ("conan", "json", "adapter", "wrapper", "test", "gtest")
    license = "MIT"
    package_type = "static-library"
    settings = "os", "compiler", "build_type", "arch"
    exports_sources = "*", "!README.md", "!build*"

    def requirements(self):
        self.requires("gtest/1.14.0", transitive_headers=True)

        self.requires("test-utilities-interface/1.0.8", transitive_headers=True)
        self.requires(f"json-adapter-interface/{self.version}", transitive_headers=True)

    def layout(self):
        cmake_layout(self)

    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure(build_script_folder=self.source_folder)
        cmake.build()

    def package(self):
        copy(self, "*.h", src=self.source_folder, dst=os.path.join(self.package_folder, "include", "JSONAdapterTestUtilities"), keep_path=True)
        copy(self, "*JSONAdapterTestUtilities.lib", src=self.build_folder, dst=os.path.join(self.package_folder, "lib"), keep_path=False)
        copy(self, "*JSONAdapterTestUtilities.pdb", src=self.build_folder, dst=os.path.join(self.package_folder, "lib"), keep_path=False)
        copy(self, "*JSONAdapterTestUtilities.a", src=self.build_folder, dst=os.path.join(self.package_folder, "lib"), keep_path=False)

    def package_info(self):
        self.cpp_info.set_property("cmake_file_name", "JSONAdapterTestUtilities")
        self.cpp_info.set_property("cmake_target_name", "JSONAdapterTestUtilities::JSONAdapterTestUtilities")
        self.cpp_info.libs = collect_libs(self)
