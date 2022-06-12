/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/configuration/blob/main/LICENSE.txt
*/

#include "CommandLineSpecificationTests.hpp"
#include "Ishiko/Configuration/CommandLineSpecification.hpp"

using namespace Ishiko;

CommandLineSpecificationTests::CommandLineSpecificationTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "CommandLineSpecification tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("addNamedOption test 1", AddNamedOptionTest1);
    append<HeapAllocationErrorsTest>("addNamedOption test 2", AddNamedOptionTest2);
    append<HeapAllocationErrorsTest>("createDefaultConfiguration test 1", CreateDefaultConfigurationTest1);
    append<HeapAllocationErrorsTest>("createDefaultConfiguration test 2", CreateDefaultConfigurationTest2);
    append<HeapAllocationErrorsTest>("createDefaultConfiguration test 3", CreateDefaultConfigurationTest3);
    append<HeapAllocationErrorsTest>("createDefaultConfiguration test 4", CreateDefaultConfigurationTest4);
}

void CommandLineSpecificationTests::ConstructorTest1(Test& test)
{
    CommandLineSpecification spec;

    ISHIKO_TEST_PASS();
}

void CommandLineSpecificationTests::AddNamedOptionTest1(Test& test)
{
    CommandLineSpecification spec;

    spec.addNamedOption("option1", { CommandLineSpecification::OptionType::singleValue });

    CommandLineSpecification::OptionDetails details;
    bool found = spec.find("option1", details);

    ISHIKO_TEST_FAIL_IF_NOT(found);
    ISHIKO_TEST_FAIL_IF(details.defaultValue().has_value());
    ISHIKO_TEST_PASS();
}

void CommandLineSpecificationTests::AddNamedOptionTest2(Test& test)
{
    CommandLineSpecification spec;

    spec.addNamedOption("option1", { CommandLineSpecification::OptionType::singleValue, "default" });

    CommandLineSpecification::OptionDetails details;
    bool found = spec.find("option1", details);

    ISHIKO_TEST_FAIL_IF_NOT(found);
    ISHIKO_TEST_FAIL_IF_NOT(details.defaultValue().has_value());
    ISHIKO_TEST_FAIL_IF_NEQ(*details.defaultValue(), "default");
    ISHIKO_TEST_PASS();
}

void CommandLineSpecificationTests::CreateDefaultConfigurationTest1(Test& test)
{
    CommandLineSpecification spec;

    Configuration configuration = spec.createDefaultConfiguration();

    ISHIKO_TEST_FAIL_IF_NEQ(configuration.size(), 0);
    ISHIKO_TEST_PASS();
}

void CommandLineSpecificationTests::CreateDefaultConfigurationTest2(Test& test)
{
    CommandLineSpecification spec;
    spec.addNamedOption("option1", { CommandLineSpecification::OptionType::singleValue });

    Configuration configuration = spec.createDefaultConfiguration();

    ISHIKO_TEST_FAIL_IF_NEQ(configuration.size(), 0);
    ISHIKO_TEST_PASS();
}

void CommandLineSpecificationTests::CreateDefaultConfigurationTest3(Test& test)
{
    CommandLineSpecification spec;
    spec.addNamedOption("option1", { CommandLineSpecification::OptionType::singleValue, "default" });

    Configuration configuration = spec.createDefaultConfiguration();

    ISHIKO_TEST_FAIL_IF_NEQ(configuration.size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(configuration.value("option1").asString(), "default");
    ISHIKO_TEST_PASS();
}

void CommandLineSpecificationTests::CreateDefaultConfigurationTest4(Test& test)
{
    CommandLineSpecification spec;
    spec.addNamedOption("option1", { CommandLineSpecification::OptionType::singleValue, "default" });
    spec.addNamedOption("option2", { CommandLineSpecification::OptionType::toggle, "true" });

    Configuration configuration = spec.createDefaultConfiguration();

    ISHIKO_TEST_FAIL_IF_NEQ(configuration.size(), 2);
    ISHIKO_TEST_FAIL_IF_NEQ(configuration.value("option1").asString(), "default");
    ISHIKO_TEST_FAIL_IF_NEQ(configuration.value("option2").asString(), "true");
    ISHIKO_TEST_PASS();
}
