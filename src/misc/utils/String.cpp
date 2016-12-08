#include "misc/utils/String.hpp"

#include <cstdarg>
#include <cstdlib>

#include <algorithm>

std::string Utils::String::Combine(int count, ...)
{
    va_list args;
    std::stringstream ss;
    
    va_start(args, count);
    
    for (int i = 0; i < count; i++)
        ss << va_arg(args, std::string);
    
    va_end(args);
    
    return ss.str();
}

std::string Utils::String::ToString(int number)
{
    std::stringstream ss;
    
    ss << number;
    
    return ss.str();
}

int Utils::String::ToInt(std::string string)
{   
    return std::stoi(string);
}

std::string Utils::String::ToHexString(int number)
{
    std::stringstream ss;
    
    ss << "0x" << std::setfill('0') << std::setw(6) << std::hex << number;
    
    return ss.str();
}

std::string Utils::String::PathToFile(std::string path)
{
    std::replace(path.begin(), path.end(), '/', '_');
    
    return path;
}

std::vector<std::string> Utils::String::Split(std::string string, char delim)
{
    std::vector<std::string> tokens;
    std::string item;
    std::stringstream ss(string);
    
    while (std::getline(ss, item, delim))
    {
        tokens.push_back(item);
    }
    
    return tokens;
}
