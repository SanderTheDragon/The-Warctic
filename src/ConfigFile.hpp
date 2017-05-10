#ifndef CONFIGFILE_HPP_
#define CONFIGFILE_HPP_

#include <string>
#include <vector>

#include "misc/Types.hpp"

class ConfigFile
{
public:
	static uint Read();
	static uint Check();
	
	static uint Write();
	static uint Create();
};

#endif
