/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/configuration/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_CONFIGURATION_LINKOPTIONS_HPP_
#define _ISHIKO_CPP_CONFIGURATION_LINKOPTIONS_HPP_

#ifdef _DEBUG
#pragma comment(lib, "IshikoConfiguration-d.lib")
#else
#pragma comment(lib, "IshikoConfiguration.lib")
#endif

#endif
