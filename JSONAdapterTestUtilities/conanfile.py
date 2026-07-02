import os
from conan import ConanFile
from conan.tools.files import copy, collect_libs
from conan.tools.cmake import CMake, cmake_layout

class JSONAdapterTestUtilitiesConan(ConanFile):
    name = "json-adapter-test-utilities"
    description = "Test utilities for library-agnostic API for C++ to work with JSON documents"
    url = "https://github.com/systelab/cpp-json-adapter"
    homepage = "https://github.com/systelab/cpp-json-adapter"
    author = "CSW <csw@werfen.com>"
    topics = ("conan", "json", "adapter", "wrapper", "test", "gtest")
    license = "MIT"

    settings = "os", "compiler", "build_type", "arch"
    exports_sources = "*", "!README.md", "!build*"

    generators = "CMakeDeps", "CMakeToolchain"

    def layout(self):
        cmake_layout(self)

    def requirements(self):
        self.requires("gtest/1.14.0", transitive_libs=True)
        self.requires("test-utilities-interface/1.1.0", transitive_headers=True)
        self.requires("json-adapter-interface/1.2.0", transitive_headers=True)

    def build(self):
        cmake = CMake(self)
        top_source = os.path.normpath(os.path.join(self.source_folder, ".."))
        cmake.configure(build_script_folder=top_source)
        cmake.build()

    def package(self):
        cmake = CMake(self).install()
		
        include_dst = os.path.join(self.package_folder, "include", "JSONAdapterTestUtilities")
        lib_dst = os.path.join(self.package_folder, "lib")
        lib_src = os.path.join(self.build_folder, "lib", str(self.settings.build_type))
        
        copy(self, "*.h",                               dst=include_dst,    src=self.source_folder)
        copy(self, "*JSONAdapterTestUtilities.lib",     dst=lib_dst,        src=lib_src, keep_path=False)
        copy(self, "*JSONAdapterTestUtilities.pdb",     dst=lib_dst,        src=lib_src, keep_path=False)
        copy(self, "*JSONAdapterTestUtilities.a",       dst=lib_dst,        src=lib_src, keep_path=False)

    def package_info(self):
        self.cpp_info.set_property("cmake_file_name", "json-adapter-test-utilities")
        self.cpp_info.set_property("cmake_target_name", "JSONAdapterTestUtilities::JSONAdapterTestUtilities")
		
        self.cpp_info.libs = collect_libs(self)