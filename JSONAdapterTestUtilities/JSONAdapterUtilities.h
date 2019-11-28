#pragma once

#include "JSONAdapterInterface/IJSONAdapter.h"
#include "JSONAdapterInterface/IJSONDocument.h"
#include "JSONAdapterInterface/IJSONRemoteSchemaProvider.h"
#include "JSONAdapterInterface/IJSONSchemaValidator.h"


namespace systelab { namespace json { namespace test_utility {

	// JSON comparison
	testing::AssertionResult compareJSONs(const std::string& expected, const std::string& toTest, const IJSONAdapter&);
	testing::AssertionResult compareJSONs(const std::string& expected, const IJSONDocument& toTest, const IJSONAdapter&);
	testing::AssertionResult compareJSONs(const IJSONDocument& expected, const IJSONDocument& toTest);

	// JSON schema validation
	testing::AssertionResult validateJSONSchema(const std::string& document, const std::string& schemaDocument, const IJSONAdapter&);
	testing::AssertionResult validateJSONSchema(const std::string& document, const IJSONDocument& schemaDocument, const IJSONAdapter&);
	testing::AssertionResult validateJSONSchema(const IJSONDocument& document, const std::string& schemaDocument, const IJSONAdapter&);
	testing::AssertionResult validateJSONSchema(const IJSONDocument& document, const IJSONDocument& schemaDocument, const IJSONAdapter&);
	testing::AssertionResult validateJSONSchema(const IJSONDocument& document, const IJSONSchemaValidator& schemaValidator);

	// Remote JSON schema validation
	testing::AssertionResult validateJSONSchema(const std::string& document, const std::string& schemaDocument, const IJSONRemoteSchemaProvider&, const IJSONAdapter&);
	testing::AssertionResult validateJSONSchema(const std::string& document, const IJSONDocument& schemaDocument, const IJSONRemoteSchemaProvider&, const IJSONAdapter&);
	testing::AssertionResult validateJSONSchema(const IJSONDocument& document, const std::string& schemaDocument, const IJSONRemoteSchemaProvider&, const IJSONAdapter&);
	testing::AssertionResult validateJSONSchema(const IJSONDocument& document, const IJSONDocument& schemaDocument, const IJSONRemoteSchemaProvider&, const IJSONAdapter&);

}}}
