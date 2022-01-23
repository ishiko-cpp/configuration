/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/config/blob/main/LICENSE.txt
*/

#include "CommandLineParserTests.h"
#include "Ishiko/Config/CommandLineParser.h"

using namespace Ishiko::Configuration;
using namespace Ishiko::Tests;

CommandLineParserTests::CommandLineParserTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "CommandLineParser tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void CommandLineParserTests::ConstructorTest1(Test& test)
{
    CommandLineParser parser;

    ISHIKO_PASS();
}
