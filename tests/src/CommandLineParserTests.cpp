/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/configuration/blob/main/LICENSE.txt
*/

#include "CommandLineParserTests.hpp"
#include "Ishiko/Configuration/CommandLineParser.hpp"

using namespace Ishiko;

CommandLineParserTests::CommandLineParserTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "CommandLineParser tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("parse test 1", ParseTest1);
    append<HeapAllocationErrorsTest>("parse test 2", ParseTest2);
    append<HeapAllocationErrorsTest>("parse test 3", ParseTest3);
}

void CommandLineParserTests::ConstructorTest1(Test& test)
{
    CommandLineParser parser;

    ISHIKO_TEST_PASS();
}

void CommandLineParserTests::ParseTest1(Test& test)
{
    CommandLineSpecification spec;
    spec.addNamedOption("option1", { CommandLineSpecification::OptionType::singleValue, "default" });

    CommandLineParser parser;
    int argc = 2;
    const char* argv[] = { "dummy", "--option1=value1" };
    Configuration configuration;
    parser.parse(spec, argc, argv, configuration);

    ISHIKO_TEST_FAIL_IF_NEQ(configuration.value("option1"), "value1");
    ISHIKO_TEST_PASS();
}

void CommandLineParserTests::ParseTest2(Test& test)
{
    CommandLineSpecification spec;
    spec.addNamedOption("option1", { CommandLineSpecification::OptionType::singleValue, "default" });

    CommandLineParser parser;
    int argc = 3;
    const char* argv[] = { "dummy", "--option1=value1", "--option2=value2" };
    Configuration configuration;
    parser.parse(spec, argc, argv, configuration);

    ISHIKO_TEST_FAIL_IF_NEQ(configuration.value("option1"), "value1");
    ISHIKO_TEST_FAIL_IF_NEQ(configuration.value("option2"), "value2");
    ISHIKO_TEST_PASS();
}

void CommandLineParserTests::ParseTest3(Test& test)
{
    CommandLineSpecification spec;

    CommandLineParser parser;
    int argc = 2;
    const char* argv[] = { "dummy", "--option1" };
    Configuration configuration;
    parser.parse(spec, argc, argv, configuration);

    ISHIKO_TEST_FAIL_IF_NEQ(configuration.value("option1"), "");
    ISHIKO_TEST_PASS();
}
