#pragma once

#include "JSONAdapterInterface/IJSONSchemaValidator.h"
#include "JSONAdapterInterface/IJSONDocument.h"


namespace systelab { namespace json { namespace test_utility {

	class MockJSONSchemaValidator : public IJSONSchemaValidator
	{
	public:
		MockJSONSchemaValidator();
		virtual ~MockJSONSchemaValidator();

		MOCK_CONST_METHOD2(validate, bool(const IJSONDocument&, std::string&));
	};

}}}
