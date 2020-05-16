/**
* \brief   plugin - helpers
* \author  quosego
* \contact https://github.com/quosego
* \version 2020/MAY/24
* \license Apache License 2.0 (Apache-2.0)
*/

#pragma once

#include <Windows.h>

//--------------------------------------------------------------------------------------------------

namespace helpers
{
	HMODULE get_current_module_handle()
	{
		HMODULE hMod = nullptr;
		GetModuleHandleExW(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, reinterpret_cast<LPCWSTR>(&get_current_module_handle), &hMod);
		return hMod;
	}
}