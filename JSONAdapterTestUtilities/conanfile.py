import os
from conans import ConanFile, tools, CMake


class JSONAdapterTestUtilitiesConan(ConanFile):
    name = "JSONAdapterTestUtilities"
    description = "Test utilities for library-agnostic API for C++ to work with JSON documents"
    url = "https://github.com/systelab/cpp-json-adapter"
    homepage = "https://github.com/systelab/cpp-json-adapter"
    author = "CSW <csw@werfen.com>"
    topics = ("conan", "json", "adapter", "wrapper", "test", "gtest")
    license = "MIT"
    generators = "cmake_find_package"
    settings = "os", "compiler", "build_type", "arch"
    exports_sources = "*", "!README.md", "!build*"

    def requirements(self):
        self.requires("gtest/1.14.0@#4372c5aed2b4018ed9f9da3e218d18b3")

        self.requires("TestUtilitiesInterface/1.0.8@systelab/stable")
        if ("%s" % self.version) == "None":
            channel = os.environ['CHANNEL'] if "CHANNEL" in os.environ else "stable"
            self.requires(f"JSONAdapterInterface/{os.environ['VERSION']}@systelab/{channel}")
        else:
            self.requires(f"JSONAdapterInterface/{self.version}@systelab/{self.channel}")

    def build(self):
        cmake = CMake(self)
        cmake.configure(source_folder=".")
        cmake.build()

    def package(self):
        self.copy("*.h", dst="include/JSONAdapterTestUtilities", keep_path=True)
        self.copy("*JSONAdapterTestUtilities.lib", dst="lib", keep_path=False)
        self.copy("*JSONAdapterTestUtilities.pdb", dst="lib", keep_path=False)
        self.copy("*JSONAdapterTestUtilities.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = tools.collect_libs(self)
