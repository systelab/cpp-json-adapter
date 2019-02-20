#pragma once

#include "JSONAdapterInterface/IJSONAdapter.h"
#include "JSONAdapterInterface/IJSONDocument.h"
#include "JSONAdapterInterface/IJSONRemoteSchemaProvider.h"
#include "JSONAdapterInterface/IJSONSchemaValidator.h"

namespace systelab { namespace json { namespace test_utility {

	class MockJSONAdapter : public IJSONAdapter
	{
	public:
		MockJSONAdapter();
		virtual ~MockJSONAdapter();

		MOCK_CONST_METHOD0(buildEmptyDocumentProxy, IJSONDocument*());
		std::unique_ptr<IJSONDocument> buildEmptyDocument() const override
		{
			return std::unique_ptr<IJSONDocument> (buildEmptyDocumentProxy());
		}

		MOCK_CONST_METHOD1(buildDocumentFromStringProxy, IJSONDocument*(const std::string&));
		std::unique_ptr<IJSONDocument> buildDocumentFromString(const std::string& param) const override
		{
			return std::unique_ptr<IJSONDocument> (buildDocumentFromStringProxy(param));
		}

		MOCK_CONST_METHOD1(buildSchemaValidatorProxy, IJSONSchemaValidator*(const IJSONDocument&));
		std::unique_ptr<IJSONSchemaValidator> buildSchemaValidator(const IJSONDocument& document) const override
		{
			return std::unique_ptr<IJSONSchemaValidator> (buildSchemaValidatorProxy(document));
		}

		MOCK_CONST_METHOD2(buildSchemaValidatorProxy, IJSONSchemaValidator*(const IJSONDocument&, const IJSONRemoteSchemaProvider&));
		std::unique_ptr<IJSONSchemaValidator> buildSchemaValidator(const IJSONDocument& document, const IJSONRemoteSchemaProvider& provider) const override
		{
			return std::unique_ptr<IJSONSchemaValidator> (buildSchemaValidatorProxy(document, provider));
		}

	};

}}}