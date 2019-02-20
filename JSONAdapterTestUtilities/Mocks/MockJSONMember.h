#pragma once

#include "JSONAdapterInterface/IJSONMember.h"
#include "JSONAdapterInterface/IJSONValue.h"


namespace systelab { namespace json { namespace test_utility {

	class MockJSONMember : public IJSONMember
	{
	public:
		MockJSONMember();
		virtual ~MockJSONMember();

		MOCK_CONST_METHOD0(getName, std::string());
		MOCK_CONST_METHOD0(getValue, IJSONValue&());
	};

}}}
