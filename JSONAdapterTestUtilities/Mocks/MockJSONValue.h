#pragma once

#include "JSONAdapterInterface/IJSONDocument.h"
#include "JSONAdapterInterface/IJSONValue.h"


namespace systelab { namespace json { namespace test_utility {

	class MockJSONValue : public IJSONValue
	{
	public:
		MockJSONValue();
		virtual ~MockJSONValue();

		MOCK_CONST_METHOD0(getType, Type());
		MOCK_METHOD1(setType, void(Type));

		MOCK_CONST_METHOD0(getBoolean, bool());
		MOCK_METHOD1(setBoolean, void(bool));

		MOCK_CONST_METHOD0(getString, std::string());
		MOCK_METHOD1(setString, void(const std::string&));

		MOCK_CONST_METHOD0(isInteger, bool());
		MOCK_CONST_METHOD0(getInteger, int());
		MOCK_CONST_METHOD0(getDouble, double());

		MOCK_METHOD1(setInteger, void(int));
		MOCK_METHOD1(setLong, void(long));
		MOCK_METHOD1(setLongLong, void(long long));
		MOCK_METHOD1(setDouble, void(double));

		MOCK_CONST_METHOD0(isNull, bool());
		MOCK_METHOD0(setNull, void());

		MOCK_CONST_METHOD0(getObjectMemberCount, unsigned int());
		MOCK_CONST_METHOD1(hasObjectMember, bool(const std::string&));
		MOCK_CONST_METHOD0(getObjectMemberNames, std::vector<std::string>());
		MOCK_CONST_METHOD1(getObjectMemberValue, IJSONValue&(const std::string&));

		MOCK_METHOD2(addMember, void(const std::string&, bool));
		MOCK_METHOD2(addMember, void(const std::string&, int));
		MOCK_METHOD2(addMember, void(const std::string&, long));
		MOCK_METHOD2(addMember, void(const std::string&, long long));
		MOCK_METHOD2(addMember, void(const std::string&, double));
		MOCK_METHOD2(addMember, void(const std::string&, const char*));
		MOCK_METHOD2(addMember, void(const std::string&, const std::string&));

		MOCK_METHOD2(addMemberProxy, void(const std::string&, IJSONValue*));
		void addMember(const std::string& name, std::unique_ptr<IJSONValue> value)
		{
			addMemberProxy(name, value.release());
		}

		MOCK_METHOD1(removeMember, void(const std::string&));

		MOCK_CONST_METHOD0(getArrayValueCount, unsigned int());
		MOCK_CONST_METHOD1(getArrayValue, IJSONValue&(unsigned int));

		MOCK_CONST_METHOD1(addArrayValueProxy, void(IJSONValue*));
		void addArrayValue(std::unique_ptr<IJSONValue> value)
		{
			addArrayValueProxy(value.release());
		}

		MOCK_METHOD0(clearArray, void());

		MOCK_METHOD1(getJSONPointerValue, IJSONValue*(const std::string&));
		MOCK_CONST_METHOD1(getJSONPointerValue, const IJSONValue*(const std::string&));

		MOCK_CONST_METHOD1(buildValueProxy, IJSONValue*(Type));
		std::unique_ptr<IJSONValue> buildValue(Type type) const
		{
			return std::unique_ptr<IJSONValue>(buildValueProxy(type));
		}

		MOCK_CONST_METHOD0(buildDocumentProxy, IJSONDocument*());
		std::unique_ptr<IJSONDocument> buildDocument() const
		{
			return std::unique_ptr<IJSONDocument>(buildDocumentProxy());
		}
	};

}}}
