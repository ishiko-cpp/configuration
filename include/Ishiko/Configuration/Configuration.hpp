/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/configuration/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CONFIGURATION_CONFIGURATION_HPP_
#define _ISHIKO_CONFIGURATION_CONFIGURATION_HPP_

#include <map>
#include <string>

namespace Ishiko
{

class Configuration
{
public:
    size_t size() const;

    const std::string& value(const std::string& name) const;
    const std::string& valueOrDefault(const std::string& name, const std::string& defaultValue) const noexcept;
    const std::string* valueOrNull(const std::string& name) const noexcept;

    void set(const std::string& name, const std::string& value);

private:
    std::map<std::string, std::string> m_options;
};

}

#endif
