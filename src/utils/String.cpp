#include "utils/String.hpp"

#include <cstdarg>
#include <cstdlib>

#include <algorithm>
#include <iomanip>
#include <sstream>
#include <vector>

std::string String::Combine(int count, ...)
{
	va_list args;
	std::stringstream ss;
	
	va_start(args, count); //If you wondered why count is needed, this is why
	
	for (int i = 0; i < count; i++) //Also this
	{
		ss << va_arg(args, const char*);
	}
	
	va_end(args);
	
	return ss.str();
}

std::string String::ToHexString(int number)
{
	std::stringstream ss;
	
	//Start with '0x' and convert the number to a uppercase hex string and then fill it with 0s until it's 6 characters long
	ss << "0x" << std::setfill('0') << std::setw(6) << std::hex << std::uppercase << number;
	
	return ss.str();
}

std::string String::ToString(int number)
{
	std::stringstream ss;
	
	ss << number;
	
	return ss.str();
}

int String::ToInt(std::string number)
{
	if (number.empty())
		return 0;
	
	if (!IsNumber(number))
		return 0;
	
	return std::stoi(number);
}

bool String::IsNumber(std::string number)
{
	for (uint i = 0; i < number.length(); i++)
	{
		if (!std::isdigit(number[i])) //If any character in the string isn't a number
			return false;
	}
	
	return true;
}
