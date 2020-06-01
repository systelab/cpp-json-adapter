cmake_minimum_required(VERSION 3.2)

# Find external dependencides
find_package(gtest)

# Find external dependencies
find_package(TestUtilitiesInterface)
find_package(JSONAdapterInterface)

set(GTEST_PACKAGE_NAME gtest)
find_package(${GTEST_PACKAGE_NAME})
if (NOT TARGET ${GTEST_PACKAGE_NAME}::${GTEST_PACKAGE_NAME})
    set(GTEST_PACKAGE_NAME GTest)
    find_package(${GTEST_PACKAGE_NAME})
endif()

# Add project folder into includes
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Configure JSON Adapter test utilities project
set(JSON_ADAPTER_TEST_UTILITIES_PROJECT JSONAdapterTestUtilities)
file(GLOB_RECURSE JSON_ADAPTER_TEST_UTILITIES_PROJECT_SRC "*.cpp")
file(GLOB_RECURSE JSON_ADAPTER_TEST_UTILITIES_PROJECT_HDR "*.h")
add_library(${JSON_ADAPTER_TEST_UTILITIES_PROJECT} STATIC ${JSON_ADAPTER_TEST_UTILITIES_PROJECT_SRC} ${JSON_ADAPTER_TEST_UTILITIES_PROJECT_HDR})
target_link_libraries(${JSON_ADAPTER_TEST_UTILITIES_PROJECT} ${GTEST_PACKAGE_NAME}::${GTEST_PACKAGE_NAME} TestUtilitiesInterface::TestUtilitiesInterface JSONAdapterInterface::JSONAdapterInterface)

# Configure source groups
foreach(FILE ${JSON_ADAPTER_TEST_UTILITIES_PROJECT_SRC} ${JSON_ADAPTER_TEST_UTILITIES_PROJECT_HDR})
    get_filename_component(PARENT_DIR "${FILE}" DIRECTORY)
    string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}" "" GROUP "${PARENT_DIR}")
    string(REPLACE "/" "\\" GROUP "${GROUP}")

    if ("${FILE}" MATCHES ".*\\.cpp")
       set(GROUP "Source Files${GROUP}")
    elseif("${FILE}" MATCHES ".*\\.h")
       set(GROUP "Header Files${GROUP}")
    endif()

    source_group("${GROUP}" FILES "${FILE}")
endforeach()
