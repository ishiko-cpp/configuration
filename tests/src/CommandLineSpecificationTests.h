/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/configuration/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CONFIGURATION_TEST_COMMANDLINESPECIFICATIONTESTS_H_
#define _ISHIKO_CONFIGURATION_TEST_COMMANDLINESPECIFICATIONTESTS_H_

#include <Ishiko/TestFramework/TestFrameworkCore.h>

class CommandLineSpecificationTests : public Ishiko::Tests::TestSequence
{
public:
    CommandLineSpecificationTests(const Ishiko::Tests::TestNumber& number,
        const Ishiko::Tests::TestEnvironment& environment);

private:
    static void ConstructorTest1(Ishiko::Tests::Test& test);
    static void AddNamedOptionTest1(Ishiko::Tests::Test& test);
};

#endif
