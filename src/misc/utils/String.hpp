#ifndef UTILS_STRING_HPP_
#define UTILS_STRING_HPP_

#include <sstream>
#include <iomanip>
#include <iostream>

namespace Utils
{
    class String
    {
    public:
        static std::string Combine(int count, ...); //Combines strings
        
        static std::string ToString(int number);    //Int to String
        
        static std::string ToHexString(int number); //Int to Hex String
    };
};

#endif
