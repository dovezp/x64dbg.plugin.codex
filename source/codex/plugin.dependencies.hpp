/**
 * \brief   plugin - dependencies
 * \author  quosego
 * \contact https://github.com/quosego
 * \version 2020/MAY/23
 * \license Apache License 2.0 (Apache-2.0)
 */

#pragma once

#include <Windows.h>

#include "pluginsdk/_plugins.h"
#include "pluginsdk/bridgemain.h"
//#include "pluginsdk/capstone/capstone.h"
#include "pluginsdk/DeviceNameResolver/DeviceNameResolver.h"
#include "pluginsdk/jansson/jansson.h"
#include "pluginsdk/lz4/lz4file.h"
#include "pluginsdk/TitanEngine/TitanEngine.h"
#include "pluginsdk/XEDParse/XEDParse.h"
//#include "pluginsdk/yara/yara.h"

//--------------------------------------------------------------------------------------------------

#ifdef _WIN64
#pragma comment(lib, "pluginsdk/x64dbg.lib")
#pragma comment(lib, "pluginsdk/x64bridge.lib")
//#pragma comment(lib, "pluginsdk/capstone/capstone_x64.lib")
#pragma comment(lib, "pluginsdk/DeviceNameResolver/DeviceNameResolver_x64.lib")
#pragma comment(lib, "pluginsdk/jansson/jansson_x64.lib")
#pragma comment(lib, "pluginsdk/lz4/lz4_x64.lib")
#pragma comment(lib, "pluginsdk/TitanEngine/TitanEngine_x64.lib")
#pragma comment(lib, "pluginsdk/XEDParse/XEDParse_x64.lib")
//#pragma comment(lib, "pluginsdk/yara/yara_x64.lib")
#else //x86
#pragma comment(lib, "pluginsdk/x32dbg.lib")
#pragma comment(lib, "pluginsdk/x32bridge.lib")
//#pragma comment(lib, "pluginsdk/capstone/capstone_x86.lib")
#pragma comment(lib, "pluginsdk/DeviceNameResolver/DeviceNameResolver_x86.lib")
#pragma comment(lib, "pluginsdk/jansson/jansson_x86.lib")
#pragma comment(lib, "pluginsdk/lz4/lz4_x86.lib")
#pragma comment(lib, "pluginsdk/TitanEngine/TitanEngine_x86.lib")
#pragma comment(lib, "pluginsdk/XEDParse/XEDParse_x86.lib")
//#pragma comment(lib, "pluginsdk/yara/yara_x86.lib")
#endif
