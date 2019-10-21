cmake_minimum_required(VERSION 3.2)

project(JSONAdapterPackageTestProject)

# Configure environment
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../cmake ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Find external dependencies
find_package(JSONAdapterTestUtilities)

# Configure test package project
set(JSON_ADAPTER_PACKAGE_TEST_PROJECT JSONAdapterPackageTest)
add_executable(${JSON_ADAPTER_PACKAGE_TEST_PROJECT} JSONAdapterExample.cpp)
target_link_libraries(${JSON_ADAPTER_PACKAGE_TEST_PROJECT} JSONAdapterTestUtilities::JSONAdapterTestUtilities)

# Register tests
enable_testing()
add_test(NAME JSONAdapterPackageTest COMMAND ${JSON_ADAPTER_PACKAGE_TEST_PROJECT})
