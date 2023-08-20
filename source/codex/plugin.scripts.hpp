/**
 * \brief   plugin - settings
 * \author  dovezp
 * \contact https://github.com/dovezp
 * \version 2020/MAY/23
 * \license Apache License 2.0 (Apache-2.0)
 */

#pragma once

#include <vector>
#include <string>
#include <map>

//--------------------------------------------------------------------------------------------------

struct scripts
{
	std::string name;
	std::string folder;
	std::string file;
	size_t index = 0;
	scripts(std::string name, std::string folder, std::string file) :
		name(name), folder(folder), file(file) {}

	scripts(std::string name, std::string folder, std::string file, size_t index) :
		name(name), folder(folder), file(file), index(index) {}
};

struct _script_context
{
	std::map<std::string, uint32_t> folders;
	std::vector<scripts> entries;
};
