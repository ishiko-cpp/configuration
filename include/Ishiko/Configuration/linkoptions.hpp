/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/config/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_CONFIG_LINKOPTIONS_HPP_
#define _ISHIKO_CPP_CONFIG_LINKOPTIONS_HPP_

#ifdef _DEBUG
#pragma comment(lib, "IshikoConfig-d.lib")
#else
#pragma comment(lib, "IshikoConfig.lib")
#endif

#endif
