/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/configuration/blob/main/LICENSE.txt
*/

#include "Configuration.hpp"

using namespace Ishiko;

size_t Configuration::size() const
{
    return m_options.size();
}

const std::string& Configuration::value(const std::string& name) const
{
    return m_options.at(name);
}

const std::string& Configuration::valueOrDefault(const std::string& name,
    const std::string& defaultValue) const noexcept
{
    std::map<std::string, std::string>::const_iterator  it = m_options.find(name);
    if (it != m_options.end())
    {
        return it->second;
    }
    else
    {
        return defaultValue;
    }
}

void Configuration::set(const std::string& name, const std::string& value)
{
    m_options[name] = value;
}
