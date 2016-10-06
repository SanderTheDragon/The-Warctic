#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include <fstream>
#include <iostream>

#include "Config.hpp"

enum LogLevel { LOG_DEFAULT, LOG_NONE, LOG_DEBUG, LOG_DEBUG_ERROR, LOG_INFO, LOG_SYSTEM, LOG_WARNING, LOG_ERROR }; //Log levels

//Ansi colors
#define LOG_COLOR_BRED "\033[1;31m"
#define LOG_COLOR_BGREEN "\033[1;32m"
#define LOG_COLOR_BYELLOW "\033[1;33m"
#define LOG_COLOR_BBLUE "\033[1;34m"
#define LOG_COLOR_BMAGENTA "\033[1;35m"
#define LOG_COLOR_BCYAN "\033[1;36m"
#define LOG_COLOR_BWHITE "\033[1;37m"
#define LOG_COLOR_RED "\033[31m"
#define LOG_COLOR_GREEN "\033[32m"
#define LOG_COLOR_YELLOW "\033[33m"
#define LOG_COLOR_BLUE "\033[34m"
#define LOG_COLOR_MAGENTA "\033[35m"
#define LOG_COLOR_CYAN "\033[36m"
#define LOG_COLOR_WHITE "\033[37m"
#define LOG_COLOR_RESET "\033[0m"
//End ansi colors

class Log
{
private:
    std::ofstream file;
    char* levelColoredString;
    char* levelString;
    int part;
    bool writeToFile;
    bool reqDebug;
    
public:
    Log(LogLevel level, bool writeFile = true)
    {
        part = 0;
        
        //Give all log levels a prefix and colored prefix
        switch (level)
        {
        case LOG_DEFAULT:
            levelColoredString = (char*)LOG_COLOR_RESET LOG_COLOR_WHITE "";
            levelString = (char*)"";
            break;
        case LOG_NONE:
            levelColoredString = (char*)LOG_COLOR_RESET LOG_COLOR_BWHITE "";
            levelString = (char*)"";
            break;
        case LOG_DEBUG:
            levelColoredString = (char*)LOG_COLOR_RESET LOG_COLOR_BGREEN "[DEBUG]" LOG_COLOR_RESET LOG_COLOR_GREEN;
            levelString = (char*)"[DEBUG]";
            break;
        case LOG_DEBUG_ERROR:
            levelColoredString = (char*)LOG_COLOR_RESET LOG_COLOR_BMAGENTA "[DEBUG ERROR]" LOG_COLOR_RESET LOG_COLOR_MAGENTA;
            levelString = (char*)"[DEBUG ERROR]";
            break;
        case LOG_INFO:
            levelColoredString = (char*)LOG_COLOR_RESET LOG_COLOR_BBLUE "[INFO]" LOG_COLOR_RESET LOG_COLOR_BLUE;
            levelString = (char*)"[INFO]";
            break;
        case LOG_SYSTEM:
            levelColoredString = (char*)LOG_COLOR_RESET LOG_COLOR_BCYAN "[SYSTEM]" LOG_COLOR_RESET LOG_COLOR_CYAN;
            levelString = (char*)"[SYSTEM]";
            break;
        case LOG_WARNING:
            levelColoredString = (char*)LOG_COLOR_RESET LOG_COLOR_BYELLOW "[WARNING]" LOG_COLOR_RESET LOG_COLOR_YELLOW;
            levelString = (char*)"[WARNING]";
            break;
        case LOG_ERROR:
            levelColoredString = (char*)LOG_COLOR_RESET LOG_COLOR_RED "[ERROR]" LOG_COLOR_RESET LOG_COLOR_RED;
            levelString = (char*)"[ERROR]";
            break;
        }
        
        if (level == LOG_DEBUG || level == LOG_DEBUG_ERROR || !writeFile) //If log level is debug or debug error, then debug mode is required, also if data won't be written to log file
            reqDebug = true;
        
        writeToFile = writeFile;
    }
    
    template<typename T>
    Log &operator<<(const T &in)
    {
        if ((reqDebug && ::debug) || !reqDebug) //If debug is required and debug is enabled or debug is not required, print to terminal (and file)
        {
            if (!file.is_open())
            {
                file.open("." DIR_SEP "out.log", std::ios::app);
                if (!file.is_open())
                {
                    if (::colors)
                        std::cout << LOG_COLOR_RESET << LOG_COLOR_BRED << "[ERROR]" << LOG_COLOR_RESET << LOG_COLOR_RED << "Could not open \'out.log\'" << NEWLINE;
                    else
                        std::cout << "[ERROR]Could not open \'out.log\'" << NEWLINE;
                        
                    std::cout.flush();
                }
            }
            
            if (part == 0)
            {
                if (::colors)
                    std::cout << levelColoredString;
                else
                    std::cout << levelString;
            }
            std::cout << in;
            std::cout.flush();
            
            if (writeToFile && file.is_open()) //Also write to file if file is opened
            {
                if (part == 0)
                    file << levelString;
                file << in;
                file.flush();
            }
            
            part++;
        }
        
        return *this;
    }
};

#endif
 
