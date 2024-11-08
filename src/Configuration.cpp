// SPDX-FileCopyrightText: 2000-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#include "Configuration.hpp"

using namespace Ishiko;

Configuration::Value::Value(const char* value)
    : boost::variant<std::string, std::vector<std::string>, boost::recursive_wrapper<Configuration>>(value)
{
}

Configuration::Value::Value(const std::string& value)
    : boost::variant<std::string, std::vector<std::string>, boost::recursive_wrapper<Configuration>>(value)
{
}

Configuration::Value::Value(std::string&& value)
    : boost::variant<std::string, std::vector<std::string>, boost::recursive_wrapper<Configuration>>(value)
{
}

Configuration::Value::Value(const std::vector<std::string>& value)
    : boost::variant<std::string, std::vector<std::string>, boost::recursive_wrapper<Configuration>>(value)
{
}

Configuration::Value::Value(const Configuration& value)
    : boost::variant<std::string, std::vector<std::string>, boost::recursive_wrapper<Configuration>>(value)
{
}

Configuration::Value::Type Configuration::Value::type() const
{
    return static_cast<Configuration::Value::Type>(which());
}

const std::string& Configuration::Value::asString() const
{
    return boost::get<std::string>(*this);
}

const std::vector<std::string>& Configuration::Value::asStringArray() const
{
    return boost::get<std::vector<std::string>>(*this);
}

const Configuration& Configuration::Value::asConfiguration() const
{
    return boost::get<Configuration>(*this);
}

size_t Configuration::size() const
{
    return m_options.size();
}

const Configuration::Value& Configuration::value(const std::string& name) const
{
    return m_options.at(name);
}

const std::string& Configuration::valueOrDefault(const std::string& name,
    const std::string& defaultValue) const noexcept
{
    std::map<std::string, Value>::const_iterator it = m_options.find(name);
    if (it != m_options.end())
    {
        return it->second.asString();
    }
    else
    {
        return defaultValue;
    }
}

const std::vector<std::string>& Configuration::valueOrDefault(const std::string& name,
    const std::vector<std::string>& defaultValue) const noexcept
{
    std::map<std::string, Value>::const_iterator it = m_options.find(name);
    if (it != m_options.end())
    {
        return it->second.asStringArray();
    }
    else
    {
        return defaultValue;
    }
}

const Configuration& Configuration::valueOrDefault(const std::string& name,
    const Configuration& defaultValue) const noexcept
{
    std::map<std::string, Value>::const_iterator it = m_options.find(name);
    if (it != m_options.end())
    {
        return it->second.asConfiguration();
    }
    else
    {
        return defaultValue;
    }
}

const Configuration::Value* Configuration::valueOrNull(const std::string& name) const noexcept
{
    std::map<std::string, Value>::const_iterator it = m_options.find(name);
    if (it != m_options.end())
    {
        return &it->second;
    }
    else
    {
        return nullptr;
    }
}

void Configuration::set(const std::string& name, const std::string& value)
{
    m_options[name] = Value(value);
}

void Configuration::set(const std::string& name, const std::vector<std::string>& value)
{
    m_options[name] = Value(value);
}

void Configuration::set(const std::string& name, const Configuration& value)
{
    m_options[name] = Value(value);
}

void Configuration::set(const std::string& name, const Value& value)
{
    m_options[name] = value;
}
