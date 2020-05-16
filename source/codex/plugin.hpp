/**
 * \brief   plugin
 * \author  quosego
 * \contact https://github.com/quosego
 * \version 2020/MAY/21
 * \license Apache License 2.0 (Apache-2.0)
 */

#pragma once

#include "plugin.dependencies.hpp"
#include "plugin.settings.hpp"
#include "plugin.controls.hpp"
#include "plugin.scripts.hpp"

//--------------------------------------------------------------------------------------------------

class plugin
{
	public:
	settings settings;
	controls controls;

	struct _handles
	{
		HINSTANCE instance;
		int plugin;
		int menu;
		int disassembly;
		int dump;
		int stack;
		int dialog;
	} handles;

	plugin(HINSTANCE instance)
	{
		handles.instance = instance;
		settings = ::settings();
		controls = ::controls();
	}
	private:
};

static plugin plug = {0};

//--------------------------------------------------------------------------------------------------

extern "C"
{
	__declspec(dllexport) bool _cdecl pluginit(PLUG_INITSTRUCT* init_struct);
	__declspec(dllexport) void _cdecl plugsetup(PLUG_SETUPSTRUCT* setup_struct);
	__declspec(dllexport) bool _cdecl plugstop();
}
