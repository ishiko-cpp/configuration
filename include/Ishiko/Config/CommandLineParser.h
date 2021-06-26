/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/configuration/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_PROCESS_COMMANDLINEPARSER_H_
#define _ISHIKO_PROCESS_COMMANDLINEPARSER_H_

#include "CommandLineSpecification.h"

namespace Ishiko
{
namespace Configuration
{

class CommandLineParser
{
public:
    static void parse(const CommandLineSpecification& specification, int argc, char* argv[]);
};

}
}

#endif
