import os
from conan import ConanFile
from conan.tools.files import copy

required_conan_version = ">=2.0.0"


class JSONAdapterInterfaceConan(ConanFile):
    name = "json-adapter-interface"
    description = "Interface of library-agnostic API for C++ to work with JSON documents"
    url = "https://github.com/systelab/cpp-json-adapter"
    homepage = "https://github.com/systelab/cpp-json-adapter"
    author = "CSW <csw@werfen.com>"
    topics = ("conan", "json", "adapter", "wrapper", "interface")
    license = "MIT"
    package_type = "header-library"
    # No settings/options are necessary, this is header only
    exports_sources = "*.h"

    def package(self):
        copy(self, "*.h", src=self.source_folder, dst=os.path.join(self.package_folder, "include", "JSONAdapterInterface"), excludes="JSONAdapterTestUtilities/*.*")

    def package_id(self):
        self.info.clear()

    def package_info(self):
        self.cpp_info.set_property("cmake_file_name", "JSONAdapterInterface")
        self.cpp_info.set_property("cmake_target_name", "JSONAdapterInterface::JSONAdapterInterface")
        self.cpp_info.bindirs = []
        self.cpp_info.libdirs = []
