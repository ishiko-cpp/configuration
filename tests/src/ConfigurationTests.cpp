/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/configuration/blob/main/LICENSE.txt
*/

#include "ConfigurationTests.hpp"

using namespace Ishiko;

ConfigurationTests::ConfigurationTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "Configuration tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void ConfigurationTests::ConstructorTest1(Test& test)
{
}
