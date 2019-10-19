import os
from conans import ConanFile, tools


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

    def requirements(self):
        self.requires("gtest/1.7.0@bincrafters/stable")
        self.requires("TestUtilitiesInterface/1.0.3@systelab/stable")
        print("Version env variable: %s" % os.environ['VERSION'])
        print("Recipie Version: %s" % self.version.value)
        if self.version.value == "None":
            self.requires("JSONAdapterInterface/%s@systelab/stable" % os.environ['VERSION'])
        else:
            self.requires("JSONAdapterInterface/%s@systelab/stable" % self.version)

    def package(self):
        self.copy("*.h", dst="include/JSONAdapterTestUtilities", keep_path=False)
        self.copy("*JSONAdapterTestUtilities.lib", dst="lib", keep_path=False)
        self.copy("*JSONAdapterTestUtilities.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = tools.collect_libs(self)
