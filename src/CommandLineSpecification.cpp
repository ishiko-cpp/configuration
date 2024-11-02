// SPDX-FileCopyrightText: 2000-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#include "CommandLineSpecification.hpp"

using namespace Ishiko;

CommandLineSpecification::OptionDetails::OptionDetails()
    : m_type(OptionType::uninitialized)
{
}

CommandLineSpecification::OptionDetails::OptionDetails(OptionType type)
    : m_type(type)
{
}

CommandLineSpecification::OptionDetails::OptionDetails(OptionType type, std::string defaultValue)
    : m_type(type), m_defaultValue(std::move(defaultValue))
{
}

CommandLineSpecification::OptionType CommandLineSpecification::OptionDetails::type() const noexcept
{
    return m_type;
}

const boost::optional<std::string>& CommandLineSpecification::OptionDetails::defaultValue() const noexcept
{
    return m_defaultValue;
}

void CommandLineSpecification::OptionDetails::setDefaultValue(const boost::optional<std::string>& value)
{
    m_defaultValue = value;
}

void CommandLineSpecification::OptionDetails::setDefaultValue(const char* value)
{
    if (value)
    {
        m_defaultValue = value;
    }
    else
    {
        m_defaultValue = boost::optional<std::string>();
    }
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

void CommandLineSpecification::addPositionalOption(size_t position, const OptionDetails& details)
{
    m_positional_options.emplace(position, details);
}

void CommandLineSpecification::addNamedOption(const std::string& name, const OptionDetails& details)
{
    m_named_options.emplace(name, details);
}

bool CommandLineSpecification::findPositionalOption(size_t position, OptionDetails& details) const
{
    std::map<size_t, OptionDetails>::const_iterator it = m_positional_options.find(position);
    if (it != m_positional_options.end())
    {
        details = it->second;
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
