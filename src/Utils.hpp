#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <cstdarg>
#include <sstream>
#include <string>

namespace Utils
{
	template<typename T>
	inline std::string toString(T const value)
	{
		std::stringstream ss;
		ss << value;
		return ss.str();
	}



	inline int toInt(std::string &value)
	{
		return atoi(value.c_str());
	}

	inline bool toBool(std::string &value)
	{
		return value.compare("True") == 0 || value.compare("true") == 0 || value.compare("On") == 0 || value.compare("on") == 0 || value.compare("1") == 0;
	}

	template<typename T>
	inline T fromString(std::string &value)
	{
		if (std::is_same<T, int>::value)
		{
			return toInt(value);
		}

		if (std::is_same<T, bool>::value)
		{
			return toBool(value);
		}

		return (T)NULL;
	}



	inline std::string combine(int count, ...)
	{
		va_list args;
		std::stringstream ss;

		va_start(args, count);

		for (int i = 0; i < count; i++)
		{
			ss << va_arg(args, char const*);
		}

		va_end(args);

		return ss.str();
	}
}

#endif
