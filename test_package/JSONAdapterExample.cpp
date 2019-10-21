#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING  1

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>

#include "JSONAdapterTestUtilities/Mocks/MockJSONAdapter.h"


int main(int argc, char *argv[])
{
    systelab::json::test_utility::MockJSONAdapter jsonAdapter;
    std::cout << "JSON adapter test utilities work as expected" << std::endl;

    return 0;
}
