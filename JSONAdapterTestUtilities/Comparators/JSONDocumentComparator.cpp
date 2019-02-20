#include "stdafx.h"
#include "TestUtilitiesInterface/EntityComparator.h"

#include "JSONAdapterInterface/IJSONDocument.h"
#include "JSONAdapterInterface/IJSONValue.h"

using testing::AssertionResult;
using testing::AssertionFailure;
using testing::AssertionSuccess;

namespace systelab { namespace test_utility {

	template<>
	testing::AssertionResult EntityComparator::operator() (const json::IJSONDocument& expected, const json::IJSONDocument& toTest) const
	{
		const json::IJSONValue& expectedRootValue = expected.getRootValue();
		const json::IJSONValue& toTestRootValue = toTest.getRootValue();
		return EntityComparator()(expectedRootValue, toTestRootValue);
	}

}}