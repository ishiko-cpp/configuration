/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/configuration/blob/main/LICENSE.txt
*/

#include "CommandLineParserTests.h"
#include "CommandLineSpecificationTests.h"
#include <Ishiko/Tests/Core.h>

using namespace Ishiko::Tests;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("IshikoConfiguration");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<CommandLineSpecificationTests>();
    theTests.append<CommandLineParserTests>();

    return theTestHarness.run();
}
