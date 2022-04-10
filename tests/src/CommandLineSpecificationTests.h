/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/config/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_CONFIGURATION_TEST_COMMANDLINESPECIFICATIONTESTS_H_
#define _ISHIKO_CPP_CONFIGURATION_TEST_COMMANDLINESPECIFICATIONTESTS_H_

#include <Ishiko/TestFramework/Core.hpp>

class CommandLineSpecificationTests : public Ishiko::TestSequence
{
public:
    CommandLineSpecificationTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void AddNamedOptionTest1(Ishiko::Test& test);
};

#endif
