/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/configuration/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CONFIGURATION_COMMANDLINESPECIFICATION_HPP_
#define _ISHIKO_CONFIGURATION_COMMANDLINESPECIFICATION_HPP_

#include "Configuration.hpp"
#include <boost/optional.hpp>
#include <map>
#include <string>

namespace Ishiko
{

class CommandLineSpecification
{
public:
    enum class OptionType
    {
        uninitialized,
        singleValue,
        toggle
    };

    class OptionDetails
    {
    public:
        OptionDetails();
        OptionDetails(OptionType type);
        OptionDetails(OptionType type, std::string defaultValue);

        OptionType type() const noexcept;
        const boost::optional<std::string>& defaultValue() const noexcept;
        void setDefaultValue(const boost::optional<std::string>& value);
        void setDefaultValue(const char* value);

    private:
        OptionType m_type;
        boost::optional<std::string> m_defaultValue;
    };

    Configuration createDefaultConfiguration() const;

    void addNamedOption(const std::string& name, const OptionDetails& details);

    bool find(const std::string& name, OptionDetails& details) const;

    void setDefaultValue(const std::string& name, const boost::optional<std::string>& value);
    void setDefaultValue(const std::string& name, const char* value);

private:
    std::map<std::string, OptionDetails> m_options;
};

}

#endif
