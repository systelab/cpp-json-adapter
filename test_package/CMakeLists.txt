cmake_minimum_required(VERSION 3.2)

project(JSONAdapterPackageTestProject)

# Configure environment
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find external dependencies
find_package(json-adapter-test-utilities)
find_package(gtest)

# Configure test package project
set(JSON_ADAPTER_PACKAGE_TEST_PROJECT JSONAdapterPackageTest)
add_executable(${JSON_ADAPTER_PACKAGE_TEST_PROJECT} JSONAdapterExample.cpp)
target_link_libraries(${JSON_ADAPTER_PACKAGE_TEST_PROJECT} gtest::gtest JSONAdapterTestUtilities::JSONAdapterTestUtilities)

# Register tests
enable_testing()
add_test(NAME JSONAdapterPackageTest COMMAND ${JSON_ADAPTER_PACKAGE_TEST_PROJECT})
