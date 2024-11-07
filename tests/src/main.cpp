// SPDX-FileCopyrightText: 2000-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

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
