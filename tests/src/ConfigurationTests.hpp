/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/configuration/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_CONFIGURATION_TESTS_CONFIGURATIONTESTS_HPP_
#define _ISHIKO_CPP_CONFIGURATION_TESTS_CONFIGURATIONTESTS_HPP_

#include <Ishiko/TestFramework/Core.hpp>

class ConfigurationTests : public Ishiko::TestSequence
{
public:
    ConfigurationTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ValueConstructorTest1(Ishiko::Test& test);
    static void ValueConstructorTest2(Ishiko::Test& test);
    static void ValueConstructorTest3(Ishiko::Test& test);
    static void ValueConstructorTest4(Ishiko::Test& test);
    static void ConstructorTest1(Ishiko::Test& test);
    static void SetTest1(Ishiko::Test& test);
    static void SetTest2(Ishiko::Test& test);
    static void SetTest3(Ishiko::Test& test);
    static void SetTest4(Ishiko::Test& test);
    static void SetTest5(Ishiko::Test& test);
    static void ValueOrDefaultTest1(Ishiko::Test& test);
    static void ValueOrDefaultTest2(Ishiko::Test& test);
    static void ValueOrDefaultTest3(Ishiko::Test& test);
    static void ValueOrNullTest1(Ishiko::Test& test);
};

#endif
