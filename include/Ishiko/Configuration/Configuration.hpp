/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/configuration/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CONFIGURATION_CONFIGURATION_HPP_
#define _ISHIKO_CONFIGURATION_CONFIGURATION_HPP_

#include <boost/variant.hpp>
#include <map>
#include <string>
#include <vector>

namespace Ishiko
{

class Configuration
{
public:
    class Value : public boost::variant<std::string, std::vector<std::string>>
    {
    public:
        enum class Type
        {
            string = 0,
            stringArray = 1
        };

        Value() = default;
        Value(const char* value);
        Value(const std::string& value);
        Value(std::string&& value);
        Value(const std::vector<std::string>& value);

        Type type() const;
        const std::string& asString() const;
        const std::vector<std::string>& asStringArray() const;
    };

    size_t size() const;

    const Value& value(const std::string& name) const;
    const Value& valueOrDefault(const std::string& name, const Value& defaultValue) const noexcept;
    const Value* valueOrNull(const std::string& name) const noexcept;

    void set(const std::string& name, const Value& value);

private:
    std::map<std::string, Value> m_options;
};

}

#endif
