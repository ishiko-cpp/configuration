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
    // TODO: document the fact that callers needs to call specification.createDefaultConfiuration to populate
    // configuration with the defaults before calling this function. This is because options may be initialized in
    // several steps so we can't assume creating the default in this function is the right place.
    static void parse(const CommandLineSpecification& specification, int argc, const char* argv[],
        Configuration& configuration);
    // TODO: document the fact that callers needs to call specification.createDefaultConfiuration to populate
    // configuration with the defaults before calling this function. This is because options may be initialized in
    // several steps so we can't assume creating the default in this function is the right place.
    static void parse(const CommandLineSpecification& specification, int argc, char* argv[],
        Configuration& configuration);
};

}

#endif
