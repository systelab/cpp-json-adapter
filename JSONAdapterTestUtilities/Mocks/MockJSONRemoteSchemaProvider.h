#pragma once

#include "JSONAdapterInterface/IJSONRemoteSchemaProvider.h"
#include "JSONAdapterInterface/IJSONDocument.h"


namespace systelab { namespace json { namespace test_utility {

	class MockJSONRemoteSchemaProvider : public IJSONRemoteSchemaProvider
	{
	public:
		MockJSONRemoteSchemaProvider();
		virtual ~MockJSONRemoteSchemaProvider();

		MOCK_CONST_METHOD1(getRemoteSchemaDocumentProxy, IJSONDocument*(const std::string&));
		virtual std::unique_ptr<IJSONDocument> getRemoteSchemaDocument(const std::string& uri) const
		{
			return std::unique_ptr<IJSONDocument>(getRemoteSchemaDocumentProxy(uri));
		}
	};

}}}
