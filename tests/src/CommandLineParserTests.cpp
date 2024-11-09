// SPDX-FileCopyrightText: 2000-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

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
    append<HeapAllocationErrorsTest>("parse test 4", ParseTest4);
    append<HeapAllocationErrorsTest>("parse test 5", ParseTest5);
    append<HeapAllocationErrorsTest>("parse test 6", ParseTest6);
    append<HeapAllocationErrorsTest>("parse test 7", ParseTest7);
}

void CommandLineParserTests::ConstructorTest1(Test& test)
{
    CommandLineParser parser;

    ISHIKO_TEST_PASS();
}

void CommandLineParserTests::ParseTest1(Test& test)
{
    CommandLineSpecification spec;
    spec.addPositionalOption(1, "option1", {CommandLineSpecification::OptionType::single_value});

    CommandLineParser parser;
    int argc = 2;
    const char* argv[] = {"dummy", "value1"};
    Configuration configuration;
    parser.parse(spec, argc, argv, configuration);

    ISHIKO_TEST_FAIL_IF_NEQ(configuration.value("option1").asString(), "value1");
    ISHIKO_TEST_PASS();
}

void CommandLineParserTests::ParseTest2(Test& test)
{
    CommandLineSpecification spec;
    spec.addNamedOption("option1", {CommandLineSpecification::OptionType::single_value, "default"});

    CommandLineParser parser;
    int argc = 2;
    const char* argv[] = {"dummy", "--option1=value1"};
    Configuration configuration;
    parser.parse(spec, argc, argv, configuration);

    ISHIKO_TEST_FAIL_IF_NEQ(configuration.value("option1").asString(), "value1");
    ISHIKO_TEST_PASS();
}

void CommandLineParserTests::ParseTest3(Test& test)
{
    CommandLineSpecification spec;
    spec.addNamedOption("option1", {CommandLineSpecification::OptionType::single_value, "default"});

    CommandLineParser parser;
    int argc = 3;
    const char* argv[] = {"dummy", "--option1=value1", "--option2=value2"};
    Configuration configuration;
    parser.parse(spec, argc, argv, configuration);

    ISHIKO_TEST_FAIL_IF_NEQ(configuration.value("option1").asString(), "value1");
    ISHIKO_TEST_FAIL_IF_NEQ(configuration.value("option2").asString(), "value2");
    ISHIKO_TEST_PASS();
}

void CommandLineParserTests::ParseTest4(Test& test)
{
    CommandLineSpecification spec;

    CommandLineParser parser;
    int argc = 2;
    const char* argv[] = {"dummy", "--option1"};
    Configuration configuration;
    parser.parse(spec, argc, argv, configuration);

    ISHIKO_TEST_FAIL_IF_NEQ(configuration.value("option1").asString(), "");
    ISHIKO_TEST_PASS();
}

void CommandLineParserTests::ParseTest5(Test& test)
{
    CommandLineSpecification spec;
    spec.addNamedOption("option1", "o", {CommandLineSpecification::OptionType::single_value, "default"});

    CommandLineParser parser;
    int argc = 2;
    const char* argv[] = {"dummy", "-o=value1"};
    Configuration configuration;
    parser.parse(spec, argc, argv, configuration);

    ISHIKO_TEST_FAIL_IF_NEQ(configuration.value("option1").asString(), "value1");
    ISHIKO_TEST_PASS();
}

void CommandLineParserTests::ParseTest6(Test& test)
{
    CommandLineSpecification spec;
    spec.addPositionalOption(1, "command", {CommandLineSpecification::OptionType::single_value});
    spec.addCommand("command", "command1");

    CommandLineParser parser;
    int argc = 2;
    const char* argv[] = {"dummy", "command1"};
    Configuration configuration;
    parser.parse(spec, argc, argv, configuration);

    ISHIKO_TEST_FAIL_IF_NEQ(configuration.value("command").asString(), "command1");
    ISHIKO_TEST_PASS();
}

void CommandLineParserTests::ParseTest7(Test& test)
{
    CommandLineSpecification spec;
    spec.addPositionalOption(1, "command", {CommandLineSpecification::OptionType::single_value});
    CommandLineSpecification::CommandDetails command_details = spec.addCommand("command", "command1");
    command_details.addPositionalOption(1, "command1_option1", {CommandLineSpecification::OptionType::single_value});

    CommandLineParser parser;
    int argc = 2;
    const char* argv[] = {"dummy", "command1", "value1"};
    Configuration configuration;
    parser.parse(spec, argc, argv, configuration);

    ISHIKO_TEST_FAIL_IF_NEQ(configuration.value("command").asString(), "command1");
    ISHIKO_TEST_PASS();
}
