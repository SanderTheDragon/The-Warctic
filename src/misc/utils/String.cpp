#include "misc/utils/String.hpp"

#include <stdarg.h>

std::string Utils::String::Combine(int count, ...)
{
    va_list args;
    std::stringstream ss;
    
    va_start(args, count);
    
    for (int i = 0; i < count; i++)
        ss << va_arg(args, const char*);
    
    va_end(args);
    
    return ss.str();
}

std::string Utils::String::ToString(int number)
{
    std::stringstream ss;
    
    ss << number;
    
    return ss.str();
}

std::string Utils::String::ToHexString(int number)
{
    std::stringstream ss;
    
    ss << "0x" << std::setfill('0') << std::setw(6) << std::hex << number;
    
    return ss.str();
}
