// SPDX-FileCopyrightText: 2000-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#ifndef GUARD_ISHIKO_CPP_CONFIGURATION_COMMANDLINESPECIFICATION_HPP
#define GUARD_ISHIKO_CPP_CONFIGURATION_COMMANDLINESPECIFICATION_HPP

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
        single_value,
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

    void addPositionalOption(size_t position, const OptionDetails& details);

    void addNamedOption(const std::string& name, const OptionDetails& details);

    bool findPositionalOption(size_t position, OptionDetails& details) const;

    bool findNamedOption(const std::string& name, OptionDetails& details) const;

    void setDefaultValue(const std::string& name, const boost::optional<std::string>& value);
    void setDefaultValue(const std::string& name, const char* value);

private:
    std::map<size_t, OptionDetails> m_positional_options;
    std::map<std::string, OptionDetails> m_named_options;
};

}

#endif
