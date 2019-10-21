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
    options = {"gtest": ["1.7.0", "1.8.1"]}
    default_options = "gtest=1.8.1"

    def requirements(self):
        if self.options.gtest == "1.7.0":
            self.requires("gtest/1.7.0@systelab/stable")
        else:
            self.requires("gtest/1.8.1@bincrafters/stable")

        self.requires("TestUtilitiesInterface/1.0.3@systelab/stable")
        if ("%s" % self.version) == "None":
            self.requires("JSONAdapterInterface/%s@systelab/stable" % os.environ['VERSION'])
        else:
            self.requires("JSONAdapterInterface/%s@systelab/stable" % self.version)

    def package(self):
        self.copy("*.h", dst="include/JSONAdapterTestUtilities", keep_path=True)
        self.copy("*JSONAdapterTestUtilities.lib", dst="lib", keep_path=False)
        self.copy("*JSONAdapterTestUtilities.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = tools.collect_libs(self)
