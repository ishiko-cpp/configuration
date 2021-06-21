/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/configuration/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CONFIGURATION_TEST_COMMANDLINEPARSERTESTS_H_
#define _ISHIKO_CONFIGURATION_TEST_COMMANDLINEPARSERTESTS_H_

#include <Ishiko/TestFramework/TestFrameworkCore.h>

class CommandLineParserTests : public Ishiko::Tests::TestSequence
{
public:
    CommandLineParserTests(const Ishiko::Tests::TestNumber& number, const Ishiko::Tests::TestEnvironment& environment);

private:
    static void ConstructorTest1(Ishiko::Tests::Test& test);
};

#endif
