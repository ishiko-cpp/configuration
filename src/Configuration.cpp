/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/configuration/blob/main/LICENSE.txt
*/

#include "Configuration.hpp"

using namespace Ishiko;

const std::string& Configuration::value(const std::string& name) const
{
    return m_options.at(name);
}

void Configuration::set(const std::string& name, const std::string& value)
{
    m_options[name] = value;
}
