// SPDX-FileCopyrightText: 2000-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#include "CommandLineSpecification.hpp"
#include <algorithm>

using namespace Ishiko;

CommandLineSpecification::OptionDetails::OptionDetails()
    : m_type(OptionType::uninitialized)
{
}

CommandLineSpecification::OptionDetails::OptionDetails(OptionType type)
    : m_type(type)
{
}

CommandLineSpecification::OptionDetails::OptionDetails(OptionType type, std::string default_value)
    : m_type(type), m_default_value(std::move(default_value))
{
}

CommandLineSpecification::OptionType CommandLineSpecification::OptionDetails::type() const noexcept
{
    return m_type;
}

const boost::optional<std::string>& CommandLineSpecification::OptionDetails::defaultValue() const noexcept
{
    return m_default_value;
}

bool CommandLineSpecification::OptionDetails::isValueAllowed(const std::string& value) const noexcept
{
    if (m_allowed_values.empty())
    {
        return true;
    }
    else
    {
        return (std::find(m_allowed_values.begin(), m_allowed_values.end(), value) != m_allowed_values.end());
    }
}

void CommandLineSpecification::OptionDetails::setDefaultValue(const boost::optional<std::string>& value)
{
    m_default_value = value;
}

void CommandLineSpecification::OptionDetails::setDefaultValue(const char* value)
{
    if (value)
    {
        m_default_value = value;
    }
    else
    {
        m_default_value = boost::optional<std::string>();
    }
}

void CommandLineSpecification::OptionDetails::setAllowedValues(const std::vector<std::string>& values)
{
    m_allowed_values = values;
}


void CommandLineSpecification::CommandDetails::addPositionalOption(size_t position, const std::string& name,
    const OptionDetails& details)
{
    m_positional_options.emplace(position, std::pair<std::string, OptionDetails>(name, details));
}

bool CommandLineSpecification::CommandDetails::findPositionalOption(size_t position, std::string& name,
    OptionDetails& details) const
{
    std::map<size_t, std::pair<std::string, OptionDetails>>::const_iterator it = m_positional_options.find(position);
    if (it != m_positional_options.end())
    {
        name = it->second.first;
        details = it->second.second;
        return true;
    }
    else
    {
        return false;
    }
}


CommandLineSpecification::CommandDetails& CommandLineSpecification::CommandDetails::addCommand(
    const std::string& option_name, const std::string& command_name)
{
    return m_commands[option_name].emplace(command_name, CommandDetails()).first->second;
}

bool CommandLineSpecification::CommandDetails::findCommand(const std::string& option_name,
    const std::string& command_name, CommandDetails& details) const
{
    std::map<std::string, std::map<std::string, CommandDetails>>::const_iterator option_it = m_commands.find(option_name);
    if (option_it != m_commands.end())
    {
        std::map<std::string, CommandDetails>::const_iterator command_it = option_it->second.find(command_name);
        if (command_it != option_it->second.end())
        {
            details = command_it->second;
            return true;
        }
    }
    return false;
}

Configuration CommandLineSpecification::createDefaultConfiguration() const
{
    Configuration result;

    for (const std::pair<std::string, OptionDetails>& option : m_named_options)
    {
        boost::optional<std::string> defaultValue = option.second.defaultValue();
        if (defaultValue.has_value())
        {
            result.set(option.first, *defaultValue);
        }
    }

    return result;
}

CommandLineSpecification::CommandDetails& CommandLineSpecification::addCommand(const std::string& option_name,
    const std::string& command_name)
{
    return m_commands[option_name].emplace(command_name, CommandDetails()).first->second;
}

CommandLineSpecification::CommandDetails& CommandLineSpecification::addCommand(const std::string& option_name,
    const std::string& command_name, const std::string& subcommand_name)
{
    CommandLineSpecification::CommandDetails& command_details = addCommand(option_name, command_name);
    // TODO: should be position of option_name + 1 and not a hardcoded 2
    command_details.addPositionalOption(2, "subcommand", {CommandLineSpecification::OptionType::single_value});
    return command_details.addCommand("subcommand", subcommand_name);
}

void CommandLineSpecification::addPositionalOption(size_t position, const std::string& name,
    const OptionDetails& details)
{
    m_positional_options.emplace(position, std::pair<std::string, OptionDetails>(name, details));
}

void CommandLineSpecification::addNamedOption(const std::string& name, const OptionDetails& details)
{
    m_named_options.emplace(name, details);
}

void CommandLineSpecification::addNamedOption(const std::string& name, const std::string& short_name,
    const OptionDetails& details)
{
    m_named_options.emplace(name, details);
    m_short_named_options.emplace(short_name, name);
}

bool CommandLineSpecification::findCommand(const std::string& option_name, const std::string& command_name,
    CommandDetails& details) const
{
    std::map<std::string, std::map<std::string, CommandDetails>>::const_iterator option_it = m_commands.find(option_name);
    if (option_it != m_commands.end())
    {
        std::map<std::string, CommandDetails>::const_iterator command_it = option_it->second.find(command_name);
        if (command_it != option_it->second.end())
        {
            details = command_it->second;
            return true;
        }
    }
    return false;
}

bool CommandLineSpecification::findPositionalOption(size_t position, std::string& name, OptionDetails& details) const
{
    std::map<size_t, std::pair<std::string, OptionDetails>>::const_iterator it = m_positional_options.find(position);
    if (it != m_positional_options.end())
    {
        name = it->second.first;
        details = it->second.second;
        return true;
    }
    else
    {
        return false;
    }
}

bool CommandLineSpecification::findNamedOption(const std::string& name, OptionDetails& details) const
{
    std::map<std::string, OptionDetails>::const_iterator it = m_named_options.find(name);
    if (it != m_named_options.end())
    {
        details = it->second;
        return true;
    }
    else
    {
        return false;
    }
}

bool CommandLineSpecification::findShortNamedOption(const std::string& short_name, std::string& name,
    OptionDetails& details) const
{
    std::map<std::string, std::string>::const_iterator name_it = m_short_named_options.find(short_name);
    if (name_it != m_short_named_options.end())
    {
        name = name_it->second;
        return findNamedOption(name, details);
    }
    else
    {
        return false;
    }
}

void CommandLineSpecification::setDefaultValue(const std::string& name, const boost::optional<std::string>& value)
{
    // TODO: what if the option doesn't exist
    std::map<std::string, OptionDetails>::iterator it = m_named_options.find(name);
    if (it != m_named_options.end())
    {
        it->second.setDefaultValue(value);
    }
}

void CommandLineSpecification::setDefaultValue(const std::string& name, const char* value)
{
    // TODO: what if the option doesn't exist
    std::map<std::string, OptionDetails>::iterator it = m_named_options.find(name);
    if (it != m_named_options.end())
    {
        it->second.setDefaultValue(value);
    }
}
