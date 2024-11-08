// SPDX-FileCopyrightText: 2000-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#ifndef GUARD_ISHIKO_CPP_CONFIGURATION_COMMANDLINEPARSER_HPP
#define GUARD_ISHIKO_CPP_CONFIGURATION_COMMANDLINEPARSER_HPP

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
