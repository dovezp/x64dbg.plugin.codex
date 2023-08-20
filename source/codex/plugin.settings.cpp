/**
 * \brief   plugin - settings
 * \author  dovezp
 * \contact https://github.com/dovezp
 * \version 2020/MAY/23
 * \license Apache License 2.0 (Apache-2.0)
 */

#include "plugin.settings.hpp"
#include "plugin.details.hpp"
#include "plugin.hpp"

//--------------------------------------------------------------------------------------------------

static _script_context s_menu;
static _script_context s_disassembly;
static std::string s_script_path;

//--------------------------------------------------------------------------------------------------

bool settings::lookup(uint32_t script_index, std::string& script_path)
{
	for (auto &e : s_menu.entries)
	{
		if (script_index == e.index)
		{
			script_path = s_script_path + e.folder + "\\" + e.file;
			return true;
		}
	}
	
	for (auto &e : s_disassembly.entries)
	{
		if (script_index == e.index)
		{
			script_path = s_script_path + e.folder + "\\" + e.file;
			return true;
		}
	}
	
	return false;
}

//--------------------------------------------------------------------------------------------------

bool settings::load()
{
	char t_dir[MAX_PATH];
	GetModuleFileNameA(nullptr, t_dir, MAX_PATH);
	directory_ = t_dir;
	free(t_dir);

	directory_.resize(directory_.find_last_of(L'\\') + 1);
	directory_ += PLUGIN_RESOURCES_PATH;
	settings_ = directory_ + PLUGIN_RESOURCES_SETTINGS_FILE;
	scripts_ = directory_ + PLUGIN_RESOURCES_FOLDER_SCRIPTS + "\\";

	json_error_t error;
	file_ = json_load_file(settings_.c_str(), 0, &error);
	if (file_ == nullptr)
	{
		_plugin_logprintf("[PLUGIN, " PLUGIN_NAME "][ERROR!] failed to read settings.json on setup!\n");
		file_= static_cast<json_t*>(nullptr);
		unload();
		unmap();
		return false;
	}
	return true;
}

bool settings::unload()
{
	std::string().swap(directory_);
	std::string().swap(scripts_);
	std::string().swap(settings_);

	json_decref(file_);
	return true;
}

bool settings::get_context_at(const char* handle_name, _script_context& s)
{
	if (file_ != nullptr)
	{
		json_t* settings_element = json_object_get(file_, PLUGIN_RESOURCES_SETTINGS);
		if (settings_element != nullptr)
		{
			json_t* scripts_element = json_object_get(settings_element, PLUGIN_RESOURCES_FOLDER_SCRIPTS);
			if (scripts_element != nullptr)
			{
				json_t* scripts_menu_element = json_object_get(scripts_element, handle_name);
				if (scripts_menu_element != nullptr)
				{
					if (!json_is_array(scripts_menu_element))
					{
						_plugin_logprintf("[PLUGIN, " PLUGIN_NAME "][ERROR!] missing target: %s is not an array\n", handle_name);
						json_decref(settings_element);
						json_decref(scripts_element);
						json_decref(scripts_menu_element);
						return false;
					}
					for (size_t i = 0; i < json_array_size(scripts_menu_element); i++)
					{
						json_t *data = json_array_get(scripts_menu_element, i);
						if (!json_is_object(data))
						{
							_plugin_logprintf("[PLUGIN, " PLUGIN_NAME "][ERROR!] script entry is not a valid json object\n");
							json_decref(settings_element);
							json_decref(scripts_element);
							json_decref(scripts_menu_element);
							json_decref(data);
							unload();
							unmap();
							return false;
						}
						const char* script_name = json_string_value(json_object_get(data, "name"));
						const char* script_folder = json_string_value(json_object_get(data, "folder"));
						const char* script_file = json_string_value(json_object_get(data, "file"));
						unique_counter++;
						s.folders.insert(std::pair<std::string, int>(script_folder, 0));
						s.entries.emplace_back(script_name, script_folder, script_file, unique_counter);

						json_decref(data);
					}
				}
				json_decref(scripts_menu_element);
			}
			json_decref(scripts_element);
		}
		json_decref(settings_element);
		return true;
	}
	unload();
	unmap();
	return false;
}

bool settings::map()
{
	bool status = get_context_at("menu", menu) &&
				  get_context_at("disassembly", disassembly);

	s_menu = menu;
	s_disassembly = disassembly;
	s_script_path = scripts_;
	
	return status;
}

bool settings::unmap()
{
	std::vector<scripts>().swap(menu.entries);
	std::map<std::string, uint32_t>().swap(menu.folders);
	std::vector<scripts>().swap(disassembly.entries);
	std::map<std::string, uint32_t>().swap(disassembly.folders);
	return true;
}

bool settings::setup()
{
	if (load())
	{
		if (map())
		{
			return true;
		}
	}
	_plugin_logprintf("[PLUGIN, " PLUGIN_NAME "][ERROR!] issue with settings::setup\n");
	return false;
}

bool settings::cleanup()
{
	if (unload())
	{
		if (unmap())
		{
			return true;
		}
	}
	_plugin_logprintf("[PLUGIN, " PLUGIN_NAME "][ERROR!] issue with settings::cleanup\n");
	return false;
}

