/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/configuration/blob/main/LICENSE.txt
*/

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

const Configuration::Value& Configuration::valueOrDefault(const std::string& name,
    const Value& defaultValue) const noexcept
{
    std::map<std::string, Value>::const_iterator  it = m_options.find(name);
    if (it != m_options.end())
    {
        return it->second;
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

void Configuration::set(const std::string& name, const Value& value)
{
    m_options[name] = value;
}
