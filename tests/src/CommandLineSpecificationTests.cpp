/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/config/blob/main/LICENSE.txt
*/

#include "CommandLineSpecificationTests.h"
#include "Ishiko/Config/CommandLineSpecification.h"

using namespace Ishiko::Configuration;
using namespace Ishiko::Tests;

CommandLineSpecificationTests::CommandLineSpecificationTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "CommandLineSpecification tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("addNamedOption test 1", AddNamedOptionTest1);
}

void CommandLineSpecificationTests::ConstructorTest1(Test& test)
{
    CommandLineSpecification spec;

    ISHIKO_PASS();
}

void CommandLineSpecificationTests::AddNamedOptionTest1(Test& test)
{
    CommandLineSpecification spec;

    spec.addNamedOption("option1", { "default" });

    CommandLineSpecification::OptionDetails details;
    bool found = spec.find("option1", details);

    ISHIKO_FAIL_IF_NOT(found);
    ISHIKO_FAIL_IF_NEQ(details.defaultValue, "default");
    ISHIKO_PASS();
}
