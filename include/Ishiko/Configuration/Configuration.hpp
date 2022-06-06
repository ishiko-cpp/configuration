/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/configuration/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CONFIGURATION_CONFIGURATION_HPP_
#define _ISHIKO_CONFIGURATION_CONFIGURATION_HPP_

#include <boost/variant.hpp>
#include <map>
#include <memory>
#include <string>
#include <vector>

namespace Ishiko
{

class Configuration
{
public:
    class Value : public boost::variant<std::string, std::vector<std::string>, boost::recursive_wrapper<Configuration>>
    {
    public:
        enum class Type
        {
            string = 0,
            stringArray = 1,
            configuration = 2,
        };

        Value() = default;
        explicit Value(const char* value);
        explicit Value(const std::string& value);
        explicit Value(std::string&& value);
        explicit Value(const std::vector<std::string>& value);
        explicit Value(const Configuration& value);

        Type type() const;
        const std::string& asString() const;
        const std::vector<std::string>& asStringArray() const;
        const Configuration& asConfiguration() const;
    };

    size_t size() const;

    const Value& value(const std::string& name) const;
    const std::string& valueOrDefault(const std::string& name, const std::string& defaultValue) const noexcept;
    const std::vector<std::string>& valueOrDefault(const std::string& name,
        const std::vector<std::string>& defaultValue) const noexcept;
    const Configuration& valueOrDefault(const std::string& name, const Configuration& defaultValue) const noexcept;
    const Value* valueOrNull(const std::string& name) const noexcept;

    void set(const std::string& name, const std::string& value);
    void set(const std::string& name, const std::vector<std::string>& value);
    void set(const std::string& name, const Configuration& value);
    void set(const std::string& name, const Value& value);

private:
    std::map<std::string, Value> m_options;
};

}

#endif
