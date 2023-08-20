/**
 * \brief   plugin - settings
 * \author  dovezp
 * \contact https://github.com/dovezp
 * \version 2020/MAY/23
 * \license Apache License 2.0 (Apache-2.0)
 */

#pragma once

#include "plugin.dependencies.hpp"
#include "plugin.scripts.hpp"

//--------------------------------------------------------------------------------------------------

class settings
{
public:
	settings() {};

	bool setup();
	bool cleanup();
	
	_script_context menu;
	_script_context disassembly;

	static bool lookup(uint32_t script_index, std::string& script_path);

	private:
	json_t* file_ = nullptr;
	std::string directory_;
	std::string settings_;
	std::string scripts_;
	size_t unique_counter = 0;

	bool load();
	bool unload();
	bool get_context_at(const char* handle_name, _script_context &s);
	bool map();
	bool unmap();

};