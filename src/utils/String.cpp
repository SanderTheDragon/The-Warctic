#include "utils/String.hpp"

#include <cstdarg>
#include <cstdlib>

#include <algorithm>
#include <iomanip>
#include <sstream>

std::string String::Combine(int count, ...)
{
	va_list args;
	std::stringstream ss;
	
	va_start(args, count);
	
	for (int i = 0; i < count; i++)
	{
		ss << va_arg(args, const char*);
	}
	
	va_end(args);
	
	return ss.str();
}

std::string String::ToHexString(int number)
{
	std::stringstream ss;
	
	ss << "0x" << std::setfill('0') << std::setw(6) << std::hex << std::uppercase << number;
	
	return ss.str();
}

int String::ToInt(std::string number)
{
	if (number.empty())
		return 0;
	
	return std::stoi(number);
}
