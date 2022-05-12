/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/configuration/blob/main/LICENSE.txt
*/

#include "CommandLineParserTests.hpp"
#include "CommandLineSpecificationTests.hpp"
#include "ConfigurationTests.hpp"
#include "Ishiko/Configuration/linkoptions.hpp"
#include <Ishiko/TestFramework/Core.hpp>

using namespace Ishiko;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("IshikoConfiguration");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<ConfigurationTests>();
    theTests.append<CommandLineSpecificationTests>();
    theTests.append<CommandLineParserTests>();

    return theTestHarness.run();
}
