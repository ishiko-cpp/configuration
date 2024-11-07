// SPDX-FileCopyrightText: 2000-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#include "CommandLineParser.hpp"
#include <Ishiko/Text.hpp>

using namespace Ishiko;

void CommandLineParser::parse(const CommandLineSpecification& specification, int argc, const char* argv[],
    Configuration& configuration)
{
    // The first argument is the executable so we ignore it
    size_t positional_option = 0;
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
        else
        {
            ++positional_option;
            
            std::string name;
            CommandLineSpecification::OptionDetails details;
            if (specification.findPositionalOption(positional_option, name, details))
            {
                if (details.isValueAllowed(arg))
                {
                    configuration.set(name, arg);
                }
                else
                {
                    // TODO: error
                }
            }
            else
            {
                // TODO
            }
        }
    }
}

void CommandLineParser::parse(const CommandLineSpecification& specification, int argc, char* argv[],
    Configuration& configuration)
{
    parse(specification, argc, (const char**)(argv), configuration);
}
