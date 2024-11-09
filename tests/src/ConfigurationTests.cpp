// SPDX-FileCopyrightText: 2000-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#include "ConfigurationTests.hpp"
#include "Ishiko/Configuration/Configuration.hpp"
#include <vector>
#include <string>

using namespace Ishiko;

ConfigurationTests::ConfigurationTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "Configuration tests", context)
{
    append<HeapAllocationErrorsTest>("Value constructor test 1", ValueConstructorTest1);
    append<HeapAllocationErrorsTest>("Value constructor test 2", ValueConstructorTest2);
    append<HeapAllocationErrorsTest>("Value constructor test 3", ValueConstructorTest3);
    append<HeapAllocationErrorsTest>("Value constructor test 4", ValueConstructorTest4);
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("set test 1", SetTest1);
    append<HeapAllocationErrorsTest>("set test 2", SetTest2);
    append<HeapAllocationErrorsTest>("set test 3", SetTest3);
    append<HeapAllocationErrorsTest>("set test 4", SetTest4);
    append<HeapAllocationErrorsTest>("set test 5", SetTest5);
    append<HeapAllocationErrorsTest>("valueOrDefault test 1", ValueOrDefaultTest1);
    append<HeapAllocationErrorsTest>("valueOrDefault test 2", ValueOrDefaultTest2);
    append<HeapAllocationErrorsTest>("valueOrDefault test 3", ValueOrDefaultTest3);
    append<HeapAllocationErrorsTest>("valueOrDefault test 4", ValueOrDefaultTest4);
    append<HeapAllocationErrorsTest>("valueOrNull test 1", ValueOrNullTest1);
}

void ConfigurationTests::ValueConstructorTest1(Test& test)
{
    Configuration::Value value;

    ISHIKO_TEST_FAIL_IF_NEQ(value.type(), Configuration::Value::Type::string);
    ISHIKO_TEST_FAIL_IF_NEQ(value.asString(), "");
    ISHIKO_TEST_PASS();
}

void ConfigurationTests::ValueConstructorTest2(Test& test)
{
    Configuration::Value value("text");

    ISHIKO_TEST_FAIL_IF_NEQ(value.type(), Configuration::Value::Type::string);
    ISHIKO_TEST_FAIL_IF_NEQ(value.asString(), "text");
    ISHIKO_TEST_PASS();
}

void ConfigurationTests::ValueConstructorTest3(Test& test)
{
    Configuration::Value value(std::string("text"));

    ISHIKO_TEST_FAIL_IF_NEQ(value.type(), Configuration::Value::Type::string);
    ISHIKO_TEST_FAIL_IF_NEQ(value.asString(), "text");
    ISHIKO_TEST_PASS();
}

void ConfigurationTests::ValueConstructorTest4(Test& test)
{
    Configuration::Value value(std::vector<std::string>({"item1", "item2"}));

    ISHIKO_TEST_FAIL_IF_NEQ(value.type(), Configuration::Value::Type::string_array);
    ISHIKO_TEST_FAIL_IF_NEQ(value.asStringArray(), std::vector<std::string>({"item1", "item2"}));
    ISHIKO_TEST_PASS();
}

void ConfigurationTests::ConstructorTest1(Test& test)
{
    Configuration configuration;

    ISHIKO_TEST_FAIL_IF_NEQ(configuration.size(), 0);
    ISHIKO_TEST_PASS();
}

void ConfigurationTests::SetTest1(Test& test)
{
    Configuration configuration;

    configuration.set("option1", "value1");

    ISHIKO_TEST_FAIL_IF_NEQ(configuration.size(), 1);
    ISHIKO_TEST_ABORT_IF_NEQ(configuration.value("option1").type(), Configuration::Value::Type::string);
    ISHIKO_TEST_FAIL_IF_NEQ(configuration.value("option1").asString(), "value1");
    ISHIKO_TEST_PASS();
}

void ConfigurationTests::SetTest2(Test& test)
{
    Configuration configuration;

    configuration.set("option1", std::vector<std::string>({"value1", "value2"}));

    ISHIKO_TEST_FAIL_IF_NEQ(configuration.size(), 1);
    ISHIKO_TEST_ABORT_IF_NEQ(configuration.value("option1").type(), Configuration::Value::Type::string_array);
    ISHIKO_TEST_FAIL_IF_NEQ(configuration.value("option1").asStringArray(),
        std::vector<std::string>({"value1", "value2"}));
    ISHIKO_TEST_PASS();
}

void ConfigurationTests::SetTest3(Test& test)
{
    Configuration configuration;

    configuration.set("option1", Configuration());

    ISHIKO_TEST_FAIL_IF_NEQ(configuration.size(), 1);
    ISHIKO_TEST_ABORT_IF_NEQ(configuration.value("option1").type(), Configuration::Value::Type::configuration);

    const Configuration& returnedConfiguration = configuration.value("option1").asConfiguration();

    ISHIKO_TEST_FAIL_IF_NEQ(returnedConfiguration.size(), 0);
    ISHIKO_TEST_PASS();
}

void ConfigurationTests::SetTest4(Test& test)
{
    Configuration configuration;

    Configuration innerConfiguration;
    innerConfiguration.set("name", "John");
    configuration.set("option1", innerConfiguration);

    ISHIKO_TEST_FAIL_IF_NEQ(configuration.size(), 1);
    ISHIKO_TEST_ABORT_IF_NEQ(configuration.value("option1").type(), Configuration::Value::Type::configuration);

    const Configuration& returnedConfiguration = configuration.value("option1").asConfiguration();

    ISHIKO_TEST_ABORT_IF_NEQ(returnedConfiguration.size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(returnedConfiguration.value("name").asString(), "John");
    ISHIKO_TEST_PASS();
}

void ConfigurationTests::SetTest5(Test& test)
{
    Configuration configuration;

    Configuration inner2Configuration;
    inner2Configuration.set("name", "John");
    inner2Configuration.set("age", "45");

    Configuration innerConfiguration;
    innerConfiguration.set("person", inner2Configuration);

    configuration.set("option1", innerConfiguration);

    ISHIKO_TEST_FAIL_IF_NEQ(configuration.size(), 1);
    ISHIKO_TEST_ABORT_IF_NEQ(configuration.value("option1").type(), Configuration::Value::Type::configuration);

    const Configuration& returnedConfiguration1 = configuration.value("option1").asConfiguration();

    ISHIKO_TEST_ABORT_IF_NEQ(returnedConfiguration1.size(), 1);

    const Configuration& returnedConfiguration2 = returnedConfiguration1.value("person").asConfiguration();

    ISHIKO_TEST_ABORT_IF_NEQ(returnedConfiguration2.size(), 2);
    ISHIKO_TEST_FAIL_IF_NEQ(returnedConfiguration2.value("name").asString(), "John");
    ISHIKO_TEST_FAIL_IF_NEQ(returnedConfiguration2.value("age").asString(), "45");
    ISHIKO_TEST_PASS();
}

void ConfigurationTests::ValueOrDefaultTest1(Test& test)
{
    Configuration configuration;

    const char* default_value = "default";
    configuration.set("option1", "value1");

    ISHIKO_TEST_FAIL_IF_NEQ(configuration.size(), 1);
    ISHIKO_TEST_FAIL_IF_STR_NEQ(configuration.valueOrDefault("option1", default_value), "value1");
    ISHIKO_TEST_FAIL_IF_STR_NEQ(configuration.valueOrDefault("option2", default_value), "default");
    ISHIKO_TEST_PASS();
}

void ConfigurationTests::ValueOrDefaultTest2(Test& test)
{
    Configuration configuration;

    const std::string defaultValue = "default";
    configuration.set("option1", "value1");

    ISHIKO_TEST_FAIL_IF_NEQ(configuration.size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(configuration.valueOrDefault("option1", defaultValue), "value1");
    ISHIKO_TEST_FAIL_IF_NEQ(configuration.valueOrDefault("option2", defaultValue), "default");
    ISHIKO_TEST_PASS();
}

void ConfigurationTests::ValueOrDefaultTest3(Test& test)
{
    Configuration configuration;

    const std::vector<std::string> defaultValue = std::vector<std::string>({ "default" });
    configuration.set("option1", std::vector<std::string>({ "value1", "value2" }));

    ISHIKO_TEST_FAIL_IF_NEQ(configuration.size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(configuration.valueOrDefault("option1", defaultValue),
        std::vector<std::string>({ "value1", "value2" }));
    ISHIKO_TEST_FAIL_IF_NEQ(configuration.valueOrDefault("option2", defaultValue),
        std::vector<std::string>({ "default" }));
    ISHIKO_TEST_PASS();
}

void ConfigurationTests::ValueOrDefaultTest4(Test& test)
{
    Configuration configuration;

    Configuration defaultValue;
    defaultValue.set("name", "John");
    configuration.set("option1", Configuration());

    ISHIKO_TEST_FAIL_IF_NEQ(configuration.size(), 1);

    const Configuration& returnedConfiguration1 = configuration.valueOrDefault("option1", defaultValue);
    const Configuration& returnedConfiguration2 = configuration.valueOrDefault("option2", defaultValue);

    ISHIKO_TEST_FAIL_IF_NEQ(returnedConfiguration1.size(), 0);
    ISHIKO_TEST_ABORT_IF_NEQ(returnedConfiguration2.size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(returnedConfiguration2.value("name").asString(), "John");
    ISHIKO_TEST_PASS();
}

void ConfigurationTests::ValueOrNullTest1(Test& test)
{
    Configuration configuration;

    configuration.set("option1", "value1");

    ISHIKO_TEST_FAIL_IF_NEQ(configuration.size(), 1);

    const Configuration::Value* valuePointer1 = configuration.valueOrNull("option1");

    ISHIKO_TEST_ABORT_IF_EQ(valuePointer1, nullptr);
    ISHIKO_TEST_FAIL_IF_NEQ(valuePointer1->asString(), "value1");

    const Configuration::Value* valuePointer2 = configuration.valueOrNull("option2");

    ISHIKO_TEST_FAIL_IF_NEQ(valuePointer2, nullptr);
    ISHIKO_TEST_PASS();
}
