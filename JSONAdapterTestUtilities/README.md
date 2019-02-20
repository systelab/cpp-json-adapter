# Test utilities for C++ JSON Adapter
This folder contains Google test utilities for any library that implements the [C++ JSON adapter](https://github.com/systelab/cpp-json-adapter) interface.

The following types of utilities are available:
* *Interface mocks*: defined using Google Mock framework, allow mocking the JSON adapter
* *Entity comparators*: allow comparing two JSON documents and providing a detailed message with the first difference found
