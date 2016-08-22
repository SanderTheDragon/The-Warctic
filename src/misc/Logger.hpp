#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include <fstream>
#include <iostream>

#include "Config.hpp"
#include "misc/Error.hpp"

enum LogLevel { LOG_NONE, LOG_DEBUG, LOG_DEBUG_ERROR, LOG_INFO, LOG_SYSTEM, LOG_WARNING, LOG_ERROR };

class Log
{
private:
    std::ofstream file;
    char* levelColoredString;
    char* levelString;
    int part;
    
public:
    Log(LogLevel level)
    {
        part = 0;
        
        switch (level)
        {
        case LOG_NONE:
            levelColoredString = (char*)"\033[1;37m";
            levelString = (char*)"";
            break;
        case LOG_DEBUG:
            levelColoredString = (char*)"\033[0m\033[1;32m[DEBUG]\033[0m\033[32m";
            levelString = (char*)"[DEBUG]";
            break;
        case LOG_DEBUG_ERROR:
            levelColoredString = (char*)"\033[0m\033[1;35m[DEBUG ERROR]\033[0m\033[35m";
            levelString = (char*)"[DEBUG ERROR]";
            break;
        case LOG_INFO:
            levelColoredString = (char*)"\033[0m\033[1;34m[INFO]\033[0m\033[34m";
            levelString = (char*)"[INFO]";
            break;
        case LOG_SYSTEM:
            levelColoredString = (char*)"\033[0m\033[1;36m[SYSTEM]\033[0m\033[36m";
            levelString = (char*)"[SYSTEM]";
            break;
        case LOG_WARNING:
            levelColoredString = (char*)"\033[0m\033[1;33m[WARNING]\033[0m\033[33m";
            levelString = (char*)"[WARNING]";
            break;
        case LOG_ERROR:
            levelColoredString = (char*)"\033[0m\033[1;31m[ERROR]\033[0m\033[31m";
            levelString = (char*)"[ERROR]";
            break;
        }
    }
    
    template<typename T>
    Log &operator<<(const T &in)
    {
        int error = ERR_OK;
            
        if (!file.is_open())
        {
            file.open("./out.log", std::ios::app);
            if (!file.is_open())
            {
                std::cout << "\033[31m[ERROR]\033[0m\033[1;31m" << GetErrorString(ERR_FILE_NOT_OPEN) << NEWLINE;
                std::cout.flush();
            }
        }
        
        if (part == 0)
            std::cout << levelColoredString;
        std::cout << in;
        std::cout.flush();
        
        if (error == ERR_OK)
        {
            if (part == 0)
                file << levelString;
            file << in;
            file.flush();
        }
        
        part++;
        
        return *this;
    }
};

#endif
 
