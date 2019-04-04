cmake_minimum_required(VERSION 3.2)

project(JSONAdapterPackageTestProject)

# Configure environment
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../cmake)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Setup up Google test
include(ConfigureGoogleTest)
configure_google_test()

# Setup 3rd party libraries through conan
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Configure test package project
set(JSON_ADAPTER_PACKAGE_TEST_PROJECT JSONAdapterPackageTest)
add_executable(${JSON_ADAPTER_PACKAGE_TEST_PROJECT} JSONAdapterExample.cpp)
target_link_libraries(${JSON_ADAPTER_PACKAGE_TEST_PROJECT} ${CONAN_LIBS})
