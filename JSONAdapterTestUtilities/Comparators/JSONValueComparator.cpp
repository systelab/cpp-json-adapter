#include "stdafx.h"
#include "TestUtilitiesInterface/EntityComparator.h"
#include "TestUtilitiesInterface/EntityComparatorMacros.h"

#include "JSONAdapterInterface/IJSONDocument.h"
#include "JSONAdapterInterface/IJSONValue.h"


namespace systelab { namespace test_utility {

	template<>
	testing::AssertionResult EntityComparator::operator() (const json::IJSONValue& expected, const json::IJSONValue& toTest) const
	{
		COMPARATOR_ASSERT_EQUAL(expected, toTest, getType());

		auto valueType = expected.getType();
		if (valueType == json::BOOLEAN_TYPE)
		{
			COMPARATOR_ASSERT_EQUAL(expected, toTest, getBoolean());
		}
		else if (valueType == json::STRING_TYPE)
		{
			COMPARATOR_ASSERT_EQUAL(expected, toTest, getString());
		}
		else if (valueType == json::NUMBER_TYPE)
		{
			COMPARATOR_ASSERT_EQUAL(expected, toTest, isInteger());
			if (expected.isInteger())
			{
				COMPARATOR_ASSERT_EQUAL(expected, toTest, getInteger());
			}
			else
			{
				COMPARATOR_ASSERT_NEAR(expected, toTest, getDouble(), 1e-5);
			}
		}
		else if (valueType == json::OBJECT_TYPE)
		{
			COMPARATOR_ASSERT_EQUAL(expected, toTest, getObjectMemberCount());

			std::vector<std::string> expectedMemberNames = expected.getObjectMemberNames();
			for (auto memberName : expectedMemberNames)
			{
				if (!toTest.hasObjectMember(memberName))
				{
					return AssertionFailure() << "Expected member '" << memberName << "' not found.";
				}

				const auto& expectedMember = expected.getObjectMemberValue(memberName);
				const auto& toTestMember = toTest.getObjectMemberValue(memberName);
				testing::AssertionResult memberValueResult = EntityComparator()(expectedMember, toTestMember);
				if (!memberValueResult)
				{
					return AssertionFailure() << memberName << ": " << memberValueResult.message();
				}
			}
		}
		else if (valueType == json::ARRAY_TYPE)
		{
			COMPARATOR_ASSERT_EQUAL(expected, toTest, getArrayValueCount());

			unsigned int nItems = expected.getArrayValueCount();
			for (unsigned int i = 0; i < nItems; i++)
			{
				const auto& expectedItem = expected.getArrayValue(i);
				const auto& toTestItem = toTest.getArrayValue(i);
				testing::AssertionResult itemResult = EntityComparator()(expectedItem, toTestItem);
				if (!itemResult)
				{
					return AssertionFailure() << "[" << i << "]: " << itemResult.message();
				}
			}
		}

		return testing::AssertionSuccess();
	}

}}