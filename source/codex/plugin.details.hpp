/**
 * \brief   plugin - details
 * \author  quosego
 * \contact https://github.com/quosego
 * \version 2020/MAY/23
 * \license Apache License 2.0 (Apache-2.0)
 */

#pragma once

//--------------------------------------------------------------------------------------------------

#ifdef _WIN64
#define HOST_NAME "X64DBG"
#else //x86
#define HOST_NAME "X32DBG"
#endif

#define PLUGIN_VERSION 1
#define PLUGIN_BUILD __DATE__ " @ " __TIME__
#define PLUGIN_NAME "Codex"

#define PLUGIN_AUTHOR			"quosego"
#define PLUGIN_AUTHOR_CONTACT	"https://github.com/" PLUGIN_AUTHOR
#define PLUGIN_BUILD_LINK		PLUGIN_AUTHOR_CONTACT "/x64dbg.plugin.codex"

#define PLUGIN_RESOURCES_PATH "plugins\\codex\\"
#define PLUGIN_RESOURCES_FOLDER "codex"
#define PLUGIN_RESOURCES_FOLDER_UI "gui"
#define PLUGIN_RESOURCES_SETTINGS "settings"
#define PLUGIN_RESOURCES_FOLDER_SCRIPTS "scripts"
#define PLUGIN_RESOURCES_SETTINGS_FILE PLUGIN_RESOURCES_SETTINGS ".json"

