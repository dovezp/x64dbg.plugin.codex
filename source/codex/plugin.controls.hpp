/**
 * \brief   plugin - controls
 * \author  quosego
 * \contact https://github.com/quosego
 * \version 2020/MAY/21
 * \license Apache License 2.0 (Apache-2.0)
 */

#pragma once

#include "plugin.dependencies.hpp"

//--------------------------------------------------------------------------------------------------

class controls
{
	public:
	enum MENU
	{
		MENU_INDEX = 0,
		// 1 - (MAXINT - 2) scripts supported
		MENU_BUG = MAXINT - 1,
		MENU_ABOUT = MAXINT
	};
	
	controls() {};

	bool init(PLUG_INITSTRUCT* init_struct);
	bool setup(PLUG_SETUPSTRUCT* setup_struct);
	bool stop();
	
	bool create();
	
	private:
	int plugin_handle;
	int plugin_menu;
	int plugin_disassembly;
};
