/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/configuration/blob/main/LICENSE.txt
*/

#include "CommandLineParser.hpp"
#include <Ishiko/Text.hpp>

using namespace Ishiko;

void CommandLineParser::parse(const CommandLineSpecification& specification, int argc, const char* argv[],
    Configuration& configuration)
{
    // TODO: use spec to initialize all option with appropriate defaults

    // The first argument is the executable so we ignore it
    for (int i = 1; i < argc; ++i)
    {
        const char* arg = argv[i];
        if (CString::StartsWith(arg, "--"))
        {
            size_t pos = CString::Find(arg, "=");
            if (pos != std::string::npos)
            {
                if (pos == 2)
                {
                    // TODO: error
                }
                // TODO: what if value is empty, maybe that is valid?
                configuration.set(CString::Substring(arg, 2, pos), CString::Substring(arg, pos + 1));
            }
            else
            {
                // TODO: use spec to find value to assign
                configuration.set(CString::Substring(arg, 2), "");
            }
        }
    }
}

void CommandLineParser::parse(const CommandLineSpecification& specification, int argc, char* argv[],
    Configuration& configuration)
{
    parse(specification, argc, (const char**)(argv), configuration);
}
