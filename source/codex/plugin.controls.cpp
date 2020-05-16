/**
 * \brief   plugin - controls
 * \author  quosego
 * \contact https://github.com/quosego
 * \version 2020/MAY/21
 * \license Apache License 2.0 (Apache-2.0)
 */

#include "plugin.controls.hpp"
#include "plugin.details.hpp"

#include "plugin.controls.callback.hpp"

#include "plugin.gui.hpp"
#include "resource.h"

//--------------------------------------------------------------------------------------------------

extern "C" __declspec(dllexport) void CBMENUENTRY(CBTYPE cbType, PLUG_CB_MENUENTRY* info)
{
	switch (info->hEntry)
	{
		//------------------------------------------------------------------------------------------
		// MENU OPTIONS
		//
		default: // 1 - (MAXINT - 2) scripts supported
		case controls::MENU_INDEX:
		{
			callback::on_script(info->hEntry);
			break;
		}

		case controls::MENU_BUG:
		{
			callback::on_bug();
			break;
		}
		
		case controls::MENU_ABOUT:
		{
			callback::on_about();
			break;
		}
		//------------------------------------------------------------------------------------------
	
	}
}

//--------------------------------------------------------------------------------------------------

bool controls::init(PLUG_INITSTRUCT* init_struct)
{
	plugin_handle = init_struct->pluginHandle;
	init_struct->pluginVersion = PLUGIN_VERSION;
	init_struct->sdkVersion = PLUG_SDKVERSION;
	strncpy_s(init_struct->pluginName, PLUGIN_NAME, _TRUNCATE);
	_plugin_registercallback(plugin_handle, CB_MENUENTRY, (CBPLUGIN)CBMENUENTRY);
	return true;
}

bool controls::setup(PLUG_SETUPSTRUCT* setup_struct)
{
	plugin_menu = setup_struct->hMenu;
	plugin_disassembly = setup_struct->hMenuDisasm;
	return true;
}

bool controls::stop()
{
	_plugin_unregistercallback(plugin_handle, CB_MENUENTRY);
	return true;
}

//--------------------------------------------------------------------------------------------------

bool controls::create()
{
	bool status = _plugin_menuaddseparator(plugin_menu);
	if (status)
	{
		gui::add_menu_icon(plugin_menu, MAKEINTRESOURCEW(IDB_PNG1), L"PNG");
		gui::add_menu_icon(plugin_disassembly, MAKEINTRESOURCEW(IDB_PNG1), L"PNG");
		
		status = _plugin_menuaddentry(plugin_menu, MENU_BUG, "Report Bug");
		if (status)
		{
			status = _plugin_menuaddseparator(plugin_menu);
			if (status)
			{
				status = _plugin_menuaddentry(plugin_menu, MENU_ABOUT, "About");
				if (status)
				{
					return true;
				}
			}
		}
	}
	if (!status)
	{
		_plugin_logprintf("[PLUGIN, " PLUGIN_NAME "][ERROR!] failed to create additional menu entries on setup!\n");
	}
	return false;
}