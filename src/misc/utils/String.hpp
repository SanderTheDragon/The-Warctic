#ifndef UTILS_STRING_HPP_
#define UTILS_STRING_HPP_

#include <vector>
#include <sstream>
#include <iomanip>
#include <iostream>

namespace Utils
{
    class String
    {
    public:
        static std::string Combine(int count, ...);                                 //Combines strings
        
        static std::string ToString(int number);                                    //Int to String
        static int ToInt(std::string string);                                       //String to Int
        
        static std::string ToHexString(int number);                                 //Int to Hex String
        
        static std::string PathToFile(std::string path);                            //Path to file, like fonts/freemono.ttf to fonts_freemono.ttf
        
        static std::vector<std::string> Split(std::string string, char delim);      //Splits String
    };
};

#endif
