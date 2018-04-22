#ifndef LOG_HPP_
#define LOG_HPP_

enum LogLevel { LOG_DEBUG, LOG_INFO, LOG_WARNING, LOG_ERROR, LOG_FATAL };

#define CONSOLE_COLOR_BRED      "\033[1;31m"
#define CONSOLE_COLOR_BGREEN    "\033[1;32m"
#define CONSOLE_COLOR_BYELLOW   "\033[1;33m"
#define CONSOLE_COLOR_BBLUE     "\033[1;34m"
#define CONSOLE_COLOR_BMAGENTA  "\033[1;35m"
#define CONSOLE_COLOR_BCYAN     "\033[1;36m"
#define CONSOLE_COLOR_BWHITE    "\033[1;37m"
#define CONSOLE_COLOR_RED       "\033[31m"
#define CONSOLE_COLOR_GREEN     "\033[32m"
#define CONSOLE_COLOR_YELLOW    "\033[33m"
#define CONSOLE_COLOR_BLUE      "\033[34m"
#define CONSOLE_COLOR_MAGENTA   "\033[35m"
#define CONSOLE_COLOR_CYAN      "\033[36m"
#define CONSOLE_COLOR_WHITE     "\033[37m"
#define CONSOLE_COLOR_RESET     "\033[0m"

#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

class Log
{
public:
	Log(LogLevel level = LOG_DEBUG)
	{
		std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		std::stringstream ss;
		ss << std::put_time(std::localtime(&now), "%Y-%m-%d %H:%M:%S");
		std::string time = ss.str();

		switch (level)
		{
		case LOG_DEBUG:
			std::cout << CONSOLE_COLOR_BGREEN << "[" << time << " DEBUG] " << CONSOLE_COLOR_RESET << CONSOLE_COLOR_GREEN;
			file << "[" << time << " DEBUG] ";
			break;
		case LOG_INFO:
			std::cout << CONSOLE_COLOR_BBLUE << "[" << time << " INFO] " << CONSOLE_COLOR_RESET << CONSOLE_COLOR_BLUE;
			file << "[" << time << " INFO] ";
			break;
		case LOG_WARNING:
			std::cout << CONSOLE_COLOR_BYELLOW << "[" << time << " WARNING] " << CONSOLE_COLOR_RESET << CONSOLE_COLOR_YELLOW;
			file << "[" << time << " WARNING] ";
			break;
		case LOG_ERROR:
			std::cout << CONSOLE_COLOR_BRED << "[" << time << " ERROR] " << CONSOLE_COLOR_RESET << CONSOLE_COLOR_RED;
			file << "[" << time << " ERROR] ";
			break;
		case LOG_FATAL:
			std::cout << CONSOLE_COLOR_BMAGENTA << "[" << time << " FATAL] " << CONSOLE_COLOR_RESET << CONSOLE_COLOR_MAGENTA;
			file << "[" << time << " FATAL] ";
			break;
		}
	}

	~Log()
	{
		std::cout << CONSOLE_COLOR_RESET << std::endl;
		file << std::endl;
	}

	template<typename T>
	Log& operator<<(T message)
	{
		std::cout << message;
		file << message;

		return *this;
	}

private:
	static std::ofstream file;
};

#endif
