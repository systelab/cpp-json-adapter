#pragma once

#include "JSONAdapterInterface/IJSONAdapter.h"
#include "JSONAdapterInterface/IJSONDocument.h"


namespace systelab { namespace json { namespace test_utility {

	testing::AssertionResult compareJSONs(const std::string& expected, const std::string& toTest, const IJSONAdapter&);
	testing::AssertionResult compareJSONs(const std::string& expected, const IJSONDocument& toTest, const IJSONAdapter&);
	testing::AssertionResult compareJSONs(const IJSONDocument& expected, const IJSONDocument& toTest);

}}}
