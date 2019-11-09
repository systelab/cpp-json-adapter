#pragma once

#include "../JSONAdapterUtilities.h"
#include "TestUtilitiesInterface/EntityComparator.h"


namespace systelab { namespace json { namespace test_utility {

	MATCHER_P2(serializesTo, expectedJSON, jsonAdapter, "JSONAdapterComparison") \
	{ \
		AssertionResult rc = compareJSONs(expectedJSON, arg, jsonAdapter); \
		*result_listener << rc.message(); \
		return rc; \
	};

}}}
