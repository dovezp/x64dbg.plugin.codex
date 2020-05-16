/**
 * \brief   plugin
 * \author  quosego
 * \contact https://github.com/quosego
 * \version 2020/MAY/21
 * \license Apache License 2.0 (Apache-2.0)
 */

#include "plugin.hpp"
#include "plugin.controls.hpp"
#include "plugin.gui.hpp"

//--------------------------------------------------------------------------------------------------

#pragma optimize("gsy", on)

//--------------------------------------------------------------------------------------------------

extern "C" __declspec(dllexport) bool _cdecl pluginit(PLUG_INITSTRUCT* init_struct)
{ 
	plug.handles.plugin = init_struct->pluginHandle;
	return plug.controls.init(init_struct);
}

extern "C" __declspec(dllexport) void _cdecl plugsetup(PLUG_SETUPSTRUCT* setup_struct)
{
	plug.handles.menu = setup_struct->hMenu;
	plug.handles.disassembly = setup_struct->hMenuDisasm;
	plug.handles.dump = setup_struct->hMenuDump;
	plug.handles.stack = setup_struct->hMenuStack;
	plug.handles.dialog = (int)setup_struct->hwndDlg;
	plug.controls.setup(setup_struct);
	plug.settings.setup();

	gui::add_menus(plug.handles.menu, plug.settings.menu);
	gui::add_menu_entries(plug.settings.menu);
	gui::add_menus(plug.handles.disassembly, plug.settings.disassembly);
	gui::add_menu_entries(plug.settings.disassembly);

	// required information is now held in static members
	plug.settings.cleanup(); 
	// create helper information controls
	plug.controls.create(); 
}

extern "C" __declspec(dllexport) bool _cdecl plugstop()
{
	_plugin_menuclear(plug.handles.menu);
	_plugin_menuclear(plug.handles.disassembly);
	_plugin_menuclear(plug.handles.dump);
	_plugin_menuclear(plug.handles.stack);
	return plug.settings.cleanup() && plug.controls.stop();
}

//--------------------------------------------------------------------------------------------------

extern "C" __declspec(dllexport) BOOL APIENTRY DllMain(HINSTANCE hinst_dll, DWORD fdw_reason, LPVOID lpv_reserved)
{
	switch(fdw_reason)
	{
		default:
		case DLL_PROCESS_DETACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_ATTACH:
		{
			plug = plugin(hinst_dll);
			return TRUE;
		}
	}
}
