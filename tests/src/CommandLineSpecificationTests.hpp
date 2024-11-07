// SPDX-FileCopyrightText: 2000-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#ifndef GUARD_ISHIKO_CPP_CONFIGURATION_TESTS_COMMANDLINESPECIFICATIONTESTS_HPP
#define GUARD_ISHIKO_CPP_CONFIGURATION_TESTS_COMMANDLINESPECIFICATIONTESTS_HPP

#include <Ishiko/TestFramework/Core.hpp>

class CommandLineSpecificationTests : public Ishiko::TestSequence
{
public:
    CommandLineSpecificationTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void AddPositionalOptionTest1(Ishiko::Test& test);
    static void AddNamedOptionTest1(Ishiko::Test& test);
    static void AddNamedOptionTest2(Ishiko::Test& test);
    static void SetDefaultValueTest1(Ishiko::Test& test);
    static void CreateDefaultConfigurationTest1(Ishiko::Test& test);
    static void CreateDefaultConfigurationTest2(Ishiko::Test& test);
    static void CreateDefaultConfigurationTest3(Ishiko::Test& test);
    static void CreateDefaultConfigurationTest4(Ishiko::Test& test);
};

#endif
