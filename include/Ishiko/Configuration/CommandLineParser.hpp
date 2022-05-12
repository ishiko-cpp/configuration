/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/configuration/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CONFIGURATION_COMMANDLINEPARSER_HPP_
#define _ISHIKO_CONFIGURATION_COMMANDLINEPARSER_HPP_

#include "CommandLineSpecification.hpp"
#include "Configuration.hpp"

namespace Ishiko
{

class CommandLineParser
{
public:
    static void parse(const CommandLineSpecification& specification, int argc, const char* argv[],
        Configuration& configuration);
    static void parse(const CommandLineSpecification& specification, int argc, char* argv[],
        Configuration& configuration);
};

}

#endif
