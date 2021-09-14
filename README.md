[![Codacy Badge](https://app.codacy.com/project/badge/Grade/839900a576fe47458e10fae7441476b3)](https://www.codacy.com/gh/systelab/cpp-json-adapter/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=systelab/cpp-json-adapter&amp;utm_campaign=Badge_Grade)


# C++ JSON Adapter interface

This repository defines a library-agnostic API for C++ to work with JSON documents.

## Supported features

* JSON parsing
* String serialization
* JSON pointers
* JSON schema validation
* Unicode

## Available implementations

* [RapidJSONAdapter](https://github.com/systelab/cpp-rapidjson-json-adapter)

## Usage

Use of adapter features begins with an instance of `systelab::json::IJSONAdapter` class. See documentation of selected implementation for details about how to build one.

### JSON parsing

Build a document from a given string:

```cpp
std::unique_ptr<systelab::json::IJSONAdapter> jsonAdapter = ...;
std:string jsonToParse = "{\"att1\": true, \"att2\": 123, \"att3\":\"message\"}";
std::unique_ptr<systelab::json::IJSONDocument> jsonDocument =
    jsonAdapter->buildDocumentFromString(jsonToParse);
```

And then navigate through the values of the created document:

```cpp
systelab::json::IJSONValue& rootValue = jsonDocument->getRootValue();
std::vector<std::string> memberNames = root.getObjectMemberNames();
for (std::string memberName : memberNames)
{
    systelab::json::IJSONValue& memberValue = rootValue.getObjectMemberValue(memberName);
    std::cout << "Member name:" << memberName << " Type:" << (int) memberValue.getType() << std::endl;
}
```

### String serialization

Build an empty JSON document:

```cpp
std::unique_ptr<systelab::json::IJSONAdapter> jsonAdapter = ...;
std::unique_ptr<systelab::json::IJSONDocument> jsonDocument = jsonAdapter->buildEmptyDocument();
```

Add some members to it:

```cpp
systelab::json::IJSONValue& jsonRootValue = jsonDocument->getRootValue();
jsonRootValue.setType(systelab::json_adapter::OBJECT_TYPE);
jsonRootValue.addMember("att1", true);
jsonRootValue.addMember("att2", 123);
jsonRootValue.addMember("att3", "message");
```

Serialize the document into a string:

```cpp
std::string serializedJSON = jsonDocument->serialize();
std::cout << "Serialized JSON:" << serializedJSON << std::endl;
```

### JSON pointers

A value inside a JSON document can be found using the `getJSONPointerValue()` method with a [JSON pointer](https://tools.ietf.org/html/rfc6901) string argument:

```json
{
    "foo": ["bar", "baz"],
    "pi": 3.1416
}
```

```cpp
auto jsonValue1 = jsonRootValue.getJSONPointerValue("foo/1"); // "baz"
auto jsonValue2 = jsonRootValue.getJSONPointerValue("pi"); // 3.1416
auto jsonValue3 = jsonRootValue.getJSONPointerValue("not/found"); // null
```

### JSON schema validation

Build a JSON schema validator from a JSON document with a schema:

```cpp
std::string jsonSchema = "{"
                         "    \"type\": \"object\","
                         "    \"properties\":"
                         "    {"
                         "        \"id\": { \"type\": \"number\" },"
                         "        \"name\": { \"type\": \"string\" }"
                         "    },"
                         "    \"required\": [\"id\"]"
                         "}";

std::unique_ptr<systelab::json::IJSONAdapter> jsonAdapter = ...;
auto jsonSchemaDocument = jsonAdapter->buildDocumentFromString(jsonSchema);
auto jsonSchemaValidator = jsonAdapter->buildSchemaValidator(jsonSchemaDocument);
```

Use it to validate another JSON document:

```cpp
std::string jsonToValidate = "{ \"id\": 123 }";
auto jsonDocument = jsonAdapter->buildDocumentFromString(jsonToValidate);

std::string reason;
bool valid = jsonSchemaValidator->validate(*jsonDocument, reason);
if (!valid)
{
    std::cout << "JSON document does not satisfy schema: " << reason << std::endl;
}
```
