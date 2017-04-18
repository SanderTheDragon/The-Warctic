#ifndef LOGGER_HPP_
#define LOGGER_HPP_

//Log levels
#define LOG_OFF       0x0C00
#define LOG_NONE      0x0C01
#define LOG_FATAL     0x0C02
#define LOG_ERROR     0x0C03
#define LOG_WARNING   0x0C04
#define LOG_INFO      0x0C05
#define LOG_DEBUG     0x0C06
#define LOG_TRACE     0x0C07
//End log levels

//Ansi colors
#define LOG_COLOR_BRED      "\033[1;31m"
#define LOG_COLOR_BGREEN    "\033[1;32m"
#define LOG_COLOR_BYELLOW   "\033[1;33m"
#define LOG_COLOR_BBLUE     "\033[1;34m"
#define LOG_COLOR_BMAGENTA  "\033[1;35m"
#define LOG_COLOR_BCYAN     "\033[1;36m"
#define LOG_COLOR_BWHITE    "\033[1;37m"
#define LOG_COLOR_RED       "\033[31m"
#define LOG_COLOR_GREEN     "\033[32m"
#define LOG_COLOR_YELLOW    "\033[33m"
#define LOG_COLOR_BLUE      "\033[34m"
#define LOG_COLOR_MAGENTA   "\033[35m"
#define LOG_COLOR_CYAN      "\033[36m"
#define LOG_COLOR_WHITE     "\033[37m"
#define LOG_COLOR_RESET     "\033[0m"
//End ansi colors

#include <fstream>
#include <iostream>

#include "Config.hpp"

class Logger
{
private:
	bool canWriteTerm = true;
	bool canWriteFile = true;
	
	std::ofstream logFile;
	
public:
	Logger(ushort level, bool noFileOut = false)
	{
		//Check if the message should be written to the terminal or log file or both (or neither)
		canWriteTerm = (level <= Config::Ref().GetLogLevelTerm());
		canWriteFile = (noFileOut) ? !noFileOut : (level <= Config::Ref().GetLogLevelFile());
		
		//No need to go on if it won't be written anyway
		if (!canWriteTerm && !canWriteFile)
			return;
		
		//Try to open the log file
		if (canWriteFile)
		{
			if (!logFile.is_open())
				logFile.open(FILE_LOG, std::ios::app);
			
			if (!logFile.is_open()) //If logfile still not open
			{
				canWriteFile = false;
				Config::Ref().SetLogLevelFile(LOG_OFF); //Don't try to log anything to the log file again
				
				Logger(LOG_ERROR) << "Could not open `" << FILE_LOG << "`" << NEWLINE;
				Logger(LOG_INFO) << "Disabled log file writing" << NEWLINE;
			}
		}
		
		//Print prefix for message
		switch (level)
		{
		case LOG_NONE:
			if (canWriteTerm)
			{
				if (Config::Ref().GetLogTermColor())
					std::cout << LOG_COLOR_RESET;
			}
			break;
		case LOG_FATAL:
			if (canWriteTerm)
			{
				if (Config::Ref().GetLogTermColor())
					std::cout << LOG_COLOR_RESET << LOG_COLOR_BMAGENTA << "[FATAL]" << LOG_COLOR_RESET << LOG_COLOR_MAGENTA;
				else
					std::cout << "[FATAL]";
			}
			
			if (canWriteFile)
				logFile << "[FATAL]";
			break;
		case LOG_ERROR:
			if (canWriteTerm)
			{
				if (Config::Ref().GetLogTermColor())
					std::cout << LOG_COLOR_RESET << LOG_COLOR_BRED << "[ERROR]" << LOG_COLOR_RESET << LOG_COLOR_RED;
				else
					std::cout << "[ERROR]";
			}
			
			if (canWriteFile)
				logFile << "[ERROR]";
			break;
		case LOG_WARNING:
			if (canWriteTerm)
			{
				if (Config::Ref().GetLogTermColor())
					std::cout << LOG_COLOR_RESET << LOG_COLOR_BYELLOW << "[WARNING]" << LOG_COLOR_RESET << LOG_COLOR_YELLOW;
				else
					std::cout << "[WARNING]";
			}
			
			if (canWriteFile)
				logFile << "[WARNING]";
			break;
		case LOG_INFO:
			if (canWriteTerm)
			{
				if (Config::Ref().GetLogTermColor())
					std::cout << LOG_COLOR_RESET << LOG_COLOR_BBLUE << "[INFO]" << LOG_COLOR_RESET << LOG_COLOR_BLUE;
				else
					std::cout << "[INFO]";
			}
			
			if (canWriteFile)
				logFile << "[INFO]";
			break;
		case LOG_DEBUG:
			if (canWriteTerm)
			{
				if (Config::Ref().GetLogTermColor())
					std::cout << LOG_COLOR_RESET << LOG_COLOR_BGREEN << "[DEBUG]" << LOG_COLOR_RESET << LOG_COLOR_GREEN;
				else
					std::cout << "[DEBUG]";
			}
			
			if (canWriteFile)
				logFile << "[DEBUG]";
			break;
		case LOG_TRACE:
			if (canWriteTerm)
			{
				if (Config::Ref().GetLogTermColor())
					std::cout << LOG_COLOR_RESET << LOG_COLOR_BCYAN << "[TRACE]" << LOG_COLOR_RESET << LOG_COLOR_CYAN;
				else
					std::cout << "[TRACE]";
			}
			
			if (canWriteFile)
				logFile << "[TRACE]";
			break;
		}
		
		if (canWriteTerm)
			std::cout.flush();
		
		if (canWriteFile)
			logFile.flush();
	}
	
	template<typename T>
	Logger &operator<<(const T &in)
	{
		//Append message parts to the streams
		if (canWriteTerm)
		{
			std::cout << in;
			
			std::cout.flush();
		}
		
		if (canWriteFile)
		{
			logFile << in;
			
			logFile.flush();
		}
		
		return *this;
	}
};

#define Log Logger //Log() is better

#endif
