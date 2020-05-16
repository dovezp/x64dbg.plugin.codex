/**
 * \brief   plugin - gui
 * \author  quosego
 * \contact https://github.com/quosego
 * \version 2020/MAY/21
 * \license Apache License 2.0 (Apache-2.0)
 */

#pragma once
#include "plugin.dependencies.hpp"
#include "plugin.scripts.hpp"

//--------------------------------------------------------------------------------------------------

namespace gui
{
	void add_menu_icon(int plugin_handle, LPCWSTR resource_name, LPWSTR resource_type);
	void add_menus(int handle, _script_context& context);
	void add_menu_entries(_script_context& context);
};