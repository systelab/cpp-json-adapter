#include "stdafx.h"
#include "JSONAdapterUtilities.h"

#include "TestUtilitiesInterface/EntityComparator.h"


namespace systelab { namespace json { namespace test_utility {

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

}}}


