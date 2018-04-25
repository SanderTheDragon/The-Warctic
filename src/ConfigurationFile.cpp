#include "ConfigurationFile.hpp"

#include <fstream>
#include <iostream>

void ConfigurationFile::read()
{
	std::ifstream stream("warctic.cfg");
	std::string line;

	while (std::getline(stream, line))
	{
		int pos = line.find('=');
		if (pos < 0)
		{
			continue;
		}

		std::string key = line.substr(0, pos);
		std::string value = line.substr(pos + 1);

		setValue<std::string>(key, value);
	}

	stream.close();
}

void ConfigurationFile::write()
{
	std::ofstream stream("warctic.cfg");

	for (std::map<std::string const, std::string>::iterator it = data.begin(); it != data.end(); it++)
	{
		stream << it->first << "=" << it->second << std::endl;
	}

	stream.close();
}
