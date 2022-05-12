/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/configuration/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CONFIGURATION_COMMANDLINESPECIFICATION_HPP_
#define _ISHIKO_CONFIGURATION_COMMANDLINESPECIFICATION_HPP_

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
        OptionDetails(OptionType type, std::string defaultValue);

        OptionType type() const;
        const std::string& defaultValue() const;

    private:
        OptionType m_type;
        std::string m_defaultValue;
    };

    void addNamedOption(const std::string& name, const OptionDetails& details);

    bool find(const std::string& name, OptionDetails& details) const;

private:
    std::map<std::string, OptionDetails> m_options;
};

}

#endif
