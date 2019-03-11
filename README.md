[![Build Status](https://travis-ci.org/systelab/cpp-json-adapter.svg?branch=master)](https://travis-ci.org/systelab/cpp-json-adapter)
[![Build status](https://ci.appveyor.com/api/projects/status/00ule8oushf91ehi?svg=true)](https://ci.appveyor.com/project/systelab/cpp-json-adapter)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/7e19c714d00244419ea2bdc5401e7cc6)](https://www.codacy.com/app/systelab/cpp-json-adapter?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=systelab/cpp-json-adapter&amp;utm_campaign=Badge_Grade)

# C++ JSON Adapter interface

This repository defines a library-agnostic API for C++ to work with JSON documents.

## Supported features

* JSON parsing
* String serialization
* JSON schema validation
* Unicode

## Available implementations

* [RapidJSONAdapter](https://github.com/systelab/cpp-rapidjson-json-adapter)

## Usage

Use of adapter features begins with an instance of `systelab::json::IJSONAdapter` class. See documentation of selected implementation for details about how to build one.

### JSON parsing

```cpp
#include "JSONAdapterInterface/IJSONAdapter.h"
#include "JSONAdapterInterface/IJSONDocument.h"
#include "JSONAdapterInterface/IJSONValue.h"

std:string jsonToParse = "{\"att1\": true, \"att2\": 123, \"att3\":\"message\"}";

std::unique_ptr<systelab::json::IJSONAdapter> jsonAdapter = ...
auto jsonDocument = jsonAdapter->buildDocumentFromString(jsonToParse);

systelab::json::IJSONValue& rootValue = jsonDocument->getRootValue();
std::vector<std::string> memberNames = root.getObjectMemberNames();
for (std::string memberName : memberNames)
{
    systelab::json::IJSONValue& memberValue = rootValue.getObjectMemberValue(memberName);
    std::cout << "Member name:" << memberName << " Type:" << (int) memberValue.getType() << std::endl;
}
```

### String serialization

```cpp

```

### JSON schema validation

`Add code snipped here`
