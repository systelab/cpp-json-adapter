#pragma once

#include "JSONAdapterInterface/IJSONDocument.h"
#include "JSONAdapterInterface/IJSONValue.h"


namespace systelab { namespace json { namespace test_utility {

	class MockJSONDocument : public IJSONDocument
	{
	public:
		MockJSONDocument();
		virtual ~MockJSONDocument();

		MOCK_METHOD0(getRootValue, IJSONValue&());
		MOCK_CONST_METHOD0(getRootValue, IJSONValue&());

		MOCK_CONST_METHOD1(serialize, std::string(bool));
	};

}}}
