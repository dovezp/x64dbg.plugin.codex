/**
 * \brief   plugin - controls - callback
 * \author  dovezp
 * \contact https://github.com/dovezp
 * \version 2020/MAY/21
 * \license Apache License 2.0 (Apache-2.0)
 */

#include "plugin.controls.callback.hpp"
#include "plugin.controls.hpp"
#include "plugin.details.hpp"
#include "plugin.settings.hpp"

#include "form_about.h"

#include "x64dbgpy/x64dbgpy.h"

//--------------------------------------------------------------------------------------------------

void callback::on_script(int index)
{
	std::string path;
	if (settings::lookup(index, path))
	{
		try
		{
			ExecutePythonScriptA(path.c_str());
		}
		catch (const std::exception& e)
		{
			_plugin_logprintf("[PLUGIN, " PLUGIN_NAME "][ERROR!] failed to execute script: %s\n", e.what());
		}
	}
}

void callback::on_bug()
{
	_plugin_logprintf("[PLUGIN, " PLUGIN_NAME "][BUG!] report your issue to: " PLUGIN_BUILD_LINK "/issues/new?body=bug+found\n");
	ShellExecute(nullptr, nullptr, PLUGIN_BUILD_LINK L"/issues/new?body=bug+found", nullptr, nullptr, SW_SHOW);
}

void callback::on_about()
{
	_plugin_logprintf("[" HOST_NAME "] Plugin: " PLUGIN_NAME ", Build: " PLUGIN_BUILD ", Author: " PLUGIN_AUTHOR ", Contact: " PLUGIN_AUTHOR_CONTACT ", Repository: " PLUGIN_BUILD_LINK "\n");

	codex::form_about^ window_about = gcnew codex::form_about;
	System::Windows::Forms::Application::Run(window_about);
}

//--------------------------------------------------------------------------------------------------
