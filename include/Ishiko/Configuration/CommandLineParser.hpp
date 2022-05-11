/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/configuration/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_PROCESS_COMMANDLINEPARSER_HPP_
#define _ISHIKO_PROCESS_COMMANDLINEPARSER_HPP_

#include "CommandLineSpecification.hpp"

namespace Ishiko
{

class CommandLineParser
{
public:
    static void parse(const CommandLineSpecification& specification, int argc, char* argv[]);
};

}

#endif
