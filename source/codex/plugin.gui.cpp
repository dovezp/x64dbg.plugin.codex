/**
 * \brief   plugin - gui
 * \author  quosego
 * \contact https://github.com/quosego
 * \version 2020/MAY/21
 * \license Apache License 2.0 (Apache-2.0)
 */

#include "plugin.gui.hpp"
#include "plugin.helpers.hpp"
#include "resource.h"

//--------------------------------------------------------------------------------------------------

void gui::add_menu_icon(int plugin_handle, LPCWSTR resource_name, LPWSTR resource_type)
{
	const HINSTANCE h_instance = (HINSTANCE)helpers::get_current_module_handle();
	HRSRC h_resource = FindResourceW(h_instance, resource_name, resource_type);
	HGLOBAL h_memory = LoadResource(h_instance, h_resource);
	ICONDATA icondata = { 0 };
	icondata.data = LockResource(h_memory);
	icondata.size = SizeofResource(h_instance, h_resource);
	_plugin_menuseticon(plugin_handle, &icondata);
	FreeResource(h_memory);
	FreeResource(h_resource);
}

void gui::add_menus(int handle, _script_context& context)
{
	for (auto &e : context.folders)
	{
		int submenu = _plugin_menuadd(handle, e.first.c_str());
		if (submenu >= 0)
		{
			e.second = (uint32_t)submenu;
		}
	}
}

void gui::add_menu_entries(_script_context& context)
{
	for (auto &e : context.entries)
	{
		std::map<std::string, uint32_t>::iterator i = context.folders.find(e.folder);
		if (i != context.folders.end())
		{
			_plugin_menuaddentry(i->second, e.index, e.name.c_str());
		}
	}
}
