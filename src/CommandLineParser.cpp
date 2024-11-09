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
        std::string option_name;
        std::string option_value;
        if (CString::StartsWith(arg, "--"))
        {
            size_t pos = CString::Find(arg, "=");
            if (pos != std::string::npos)
            {
                if (pos == 2)
                {
                    // TODO: error
                }
                option_name = CString::Substring(arg, 2, pos);
                // TODO: what if value is empty, maybe that is valid?
                option_value = CString::Substring(arg, pos + 1);
                configuration.set(option_name, option_value);
            }
            else
            {
                option_name = CString::Substring(arg, 2);
                // TODO: use spec to find value to assign
                option_value = "";
                configuration.set(option_name, option_value);
            }
        }
        else if (CString::StartsWith(arg, "-"))
        {
            std::string short_name;
            size_t pos = CString::Find(arg, "=");
            if (pos != std::string::npos)
            {
                if (pos == 1)
                {
                    // TODO: error
                }
                short_name = CString::Substring(arg, 1, pos);
                option_value = CString::Substring(arg, pos + 1);
            }
            else
            {
                short_name = CString::Substring(arg, 1);
                option_value = "";
            }
            CommandLineSpecification::OptionDetails details;
            if (specification.findShortNamedOption(short_name, option_name, details))
            {
                // TODO: what if value is empty, maybe that is valid?
                configuration.set(option_name, option_value);
            }
        }
        else
        {
            ++positional_option;
            
            CommandLineSpecification::OptionDetails details;
            if (specification.findPositionalOption(positional_option, option_name, details))
            {
                if (details.isValueAllowed(arg))
                {
                    option_value = arg;
                    configuration.set(option_name, arg);
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
        CommandLineSpecification::CommandDetails command_details;
        if (specification.findCommand(option_name, option_value, command_details))
        {
            // TODO
        }
    }
}

void CommandLineParser::parse(const CommandLineSpecification& specification, int argc, char* argv[],
    Configuration& configuration)
{
    parse(specification, argc, (const char**)(argv), configuration);
}
