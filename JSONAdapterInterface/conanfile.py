from conan import ConanFile
from conan.tools.files import copy
import os

class JSONAdapterInterfaceConan(ConanFile):
    name = "json-adapter-interface"
    description = "Interface of library-agnostic API for C++ to work with JSON documents"
    url = "https://github.com/systelab/cpp-json-adapter"
    homepage = "https://github.com/systelab/cpp-json-adapter"
    author = "CSW <csw@werfen.com>"
    topics = ("conan", "json", "adapter", "wrapper", "interface")
    license = "MIT"

    package_type = "header-library"
    exports_sources = "*.h"

    def package(self):
        src = self.source_folder
        dst = os.path.join(self.package_folder, "include", "JSONAdapterInterface")
        copy(self, "*.h", dst=dst, src=src, excludes=("JSONAdapterTestUtilities/*.*",))

    def package_info(self):
        self.cpp_info.includedirs = ["include"]
