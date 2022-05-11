/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/configuration/blob/main/LICENSE.txt
*/

#include "CommandLineSpecification.hpp"

using namespace Ishiko;

void CommandLineSpecification::addNamedOption(const std::string& name, const OptionDetails& details)
{
    m_options.emplace(name, details);
}

bool CommandLineSpecification::find(const std::string& name, OptionDetails& details) const
{
    std::map<std::string, OptionDetails>::const_iterator it = m_options.find(name);
    if (it != m_options.end())
    {
        details = it->second;
        return true;
    }
    else
    {
        return false;
    }
}
