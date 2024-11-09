// SPDX-FileCopyrightText: 2000-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#ifndef GUARD_ISHIKO_CPP_CONFIGURATION_TESTS_COMMANDLINEPARSERTESTS_HPP
#define GUARD_ISHIKO_CPP_CONFIGURATION_TESTS_COMMANDLINEPARSERTESTS_HPP

#include <Ishiko/TestFramework/Core.hpp>

class CommandLineParserTests : public Ishiko::TestSequence
{
public:
    CommandLineParserTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void ParseTest1(Ishiko::Test& test);
    static void ParseTest2(Ishiko::Test& test);
    static void ParseTest3(Ishiko::Test& test);
    static void ParseTest4(Ishiko::Test& test);
    static void ParseTest5(Ishiko::Test& test);
    static void ParseTest6(Ishiko::Test& test);
    static void ParseTest7(Ishiko::Test& test);
    static void ParseTest8(Ishiko::Test& test);
    static void ParseTest9(Ishiko::Test& test);
};

#endif
