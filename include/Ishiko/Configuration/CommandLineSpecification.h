/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/config/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CONFIGURATION_COMMANDLINESPECIFICATION_H_
#define _ISHIKO_CONFIGURATION_COMMANDLINESPECIFICATION_H_

#include <map>
#include <string>

namespace Ishiko
{
namespace Configuration
{

class CommandLineSpecification
{
public:
    struct OptionDetails
    {
        std::string defaultValue;
    };

    void addNamedOption(const std::string& name, const OptionDetails& details);

    bool find(const std::string& name, OptionDetails& details) const;

private:
    std::map<std::string, OptionDetails> m_options;
};

}
}

#endif
