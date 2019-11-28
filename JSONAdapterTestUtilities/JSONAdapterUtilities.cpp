#include "stdafx.h"
#include "JSONAdapterUtilities.h"

#include "TestUtilitiesInterface/EntityComparator.h"


namespace systelab { namespace json { namespace test_utility {

	// JSON comparison
	testing::AssertionResult compareJSONs(const std::string& expected,
										  const std::string& toTest,
										  const IJSONAdapter& jsonAdapter)
	{
		
		auto expectedDocument = jsonAdapter.buildDocumentFromString(expected);
		if (!expectedDocument)
		{
			return testing::AssertionFailure() << "Expected string is not valid JSON document";
		}

		auto toTestDocument = jsonAdapter.buildDocumentFromString(toTest);
		if (!toTestDocument)
		{
			return testing::AssertionFailure() << "Actual string is not valid JSON document";
		}

		return compareJSONs(*expectedDocument, *toTestDocument);
	}

	testing::AssertionResult compareJSONs(const std::string& expected,
										  const IJSONDocument& toTestDocument,
										  const IJSONAdapter& jsonAdapter)
	{
		auto expectedDocument = jsonAdapter.buildDocumentFromString(expected);
		if (!expectedDocument)
		{
			return testing::AssertionFailure() << "Expected string is not valid JSON document";
		}

		return compareJSONs(*expectedDocument, toTestDocument);
	}

	testing::AssertionResult compareJSONs(const IJSONDocument& expectedDocument,
										  const IJSONDocument& toTestDocument)
	{
		testing::AssertionResult comparisonResult = systelab::test_utility::EntityComparator()(expectedDocument, toTestDocument);
		if (!comparisonResult)
		{
			return testing::AssertionFailure() << "JSON objects are different: " << comparisonResult.message();
		}

		return testing::AssertionSuccess();
	}


	// Schema validation
	testing::AssertionResult validateJSONSchema(const std::string& document,
												const std::string& schemaDocument,
												const IJSONAdapter& jsonAdapter)
	{
		auto documentJSON = jsonAdapter.buildDocumentFromString(document);
		if (!documentJSON)
		{
			return testing::AssertionFailure() << "Document is not a valid JSON";
		}

		return validateJSONSchema(*documentJSON, schemaDocument, jsonAdapter);
	}

	testing::AssertionResult validateJSONSchema(const std::string& document,
												const IJSONDocument& schemaDocument,
												const IJSONAdapter& jsonAdapter)
	{
		auto documentJSON = jsonAdapter.buildDocumentFromString(document);
		if (!documentJSON)
		{
			return testing::AssertionFailure() << "Document is not a valid JSON";
		}

		return validateJSONSchema(*documentJSON, schemaDocument, jsonAdapter);
	}

	testing::AssertionResult validateJSONSchema(const IJSONDocument& document,
												const std::string& schemaDocument,
												const IJSONAdapter& jsonAdapter)
	{
		auto schemaDocumentJSON = jsonAdapter.buildDocumentFromString(schemaDocument);
		if (!schemaDocumentJSON)
		{
			return testing::AssertionFailure() << "Schema is not a valid JSON";
		}

		return validateJSONSchema(document, *schemaDocumentJSON, jsonAdapter);
	}

	testing::AssertionResult validateJSONSchema(const IJSONDocument& document,
												const IJSONDocument& schemaDocument,
												const IJSONAdapter& jsonAdapter)
	{
		auto schemaValidator = jsonAdapter.buildSchemaValidator(schemaDocument);
		return validateJSONSchema(document, *schemaValidator);
	}

	testing::AssertionResult validateJSONSchema(const IJSONDocument& document,
												const IJSONSchemaValidator& schemaValidator)
	{
		std::string reason;
		if (!schemaValidator.validate(document, reason))
		{
			return testing::AssertionFailure() << reason;
		}

		return testing::AssertionSuccess();
	}


	// Remote schema validation
	testing::AssertionResult validateJSONSchema(const std::string& document,
												const std::string& schemaDocument,
												const IJSONRemoteSchemaProvider& remoteSchemaProvider,
												const IJSONAdapter& jsonAdapter)
	{
		auto documentJSON = jsonAdapter.buildDocumentFromString(document);
		if (!documentJSON)
		{
			return testing::AssertionFailure() << "Document is not a valid JSON";
		}

		return validateJSONSchema(*documentJSON, schemaDocument, remoteSchemaProvider, jsonAdapter);
	}

	testing::AssertionResult validateJSONSchema(const std::string& document,
												const IJSONDocument& schemaDocument,
												const IJSONRemoteSchemaProvider& remoteSchemaProvider,
												const IJSONAdapter& jsonAdapter)
	{
		auto documentJSON = jsonAdapter.buildDocumentFromString(document);
		if (!documentJSON)
		{
			return testing::AssertionFailure() << "Document is not a valid JSON";
		}

		return validateJSONSchema(*documentJSON, schemaDocument, remoteSchemaProvider, jsonAdapter);
	}

	testing::AssertionResult validateJSONSchema(const IJSONDocument& document,
												const std::string& schemaDocument,
												const IJSONRemoteSchemaProvider& remoteSchemaProvider,
												const IJSONAdapter& jsonAdapter)
	{
		auto schemaDocumentJSON = jsonAdapter.buildDocumentFromString(schemaDocument);
		if (!schemaDocumentJSON)
		{
			return testing::AssertionFailure() << "Schema is not a valid JSON";
		}

		return validateJSONSchema(document, *schemaDocumentJSON, remoteSchemaProvider, jsonAdapter);
	}

	testing::AssertionResult validateJSONSchema(const IJSONDocument& document,
												const IJSONDocument& schemaDocument,
												const IJSONRemoteSchemaProvider& remoteSchemaProvider,
												const IJSONAdapter& jsonAdapter)
	{
		auto schemaValidator = jsonAdapter.buildSchemaValidator(schemaDocument, remoteSchemaProvider);
		return validateJSONSchema(document, *schemaValidator);
	}

}}}

