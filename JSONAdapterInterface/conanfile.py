from conans import ConanFile, tools


class JSONAdapterInterfaceConan(ConanFile):
    name = "JSONAdapterInterface"
    description = "Interface of library-agnostic API for C++ to work with JSON documents"
    url = "https://github.com/systelab/cpp-json-adapter"
    homepage = "https://github.com/systelab/cpp-json-adapter"
    author = "CSW <csw@werfen.com>"
    topics = ("conan", "json", "adapter", "wrapper", "interface")
    license = "MIT"
    generators = "cmake_find_package"
    # No settings/options are necessary, this is header only

    def package(self):
        self.copy("*.h", dst="include/JSONAdapterInterface")

    def package_info(self):
        self.info.header_only()
