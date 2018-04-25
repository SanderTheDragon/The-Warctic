#ifndef CONFIGURATIONFILE_HPP_
#define CONFIGURATIONFILE_HPP_

#include <any>
#include <map>
#include <string>

#include "Utils.hpp"

class ConfigurationFile
{
public:
	void read();
	void write();

	template<typename T>
	void setValue(std::string const &key, T const value)
	{
		data[key] = Utils::toString(value);
	}

	template<typename T>
	T const getValue(std::string const &key, T const fallback)
	{
		if (data.find(key) == data.end())
		{
			setValue<T>(key, fallback);
			return fallback;
		}

		T const value = Utils::fromString<T>(data.at(key));
		if (value == (T)NULL)
		{
			setValue<T>(key, fallback);
			return fallback;
		}

		return value;
	}

private:
	std::map<std::string const, std::string> data;
};

#endif
