#ifndef CONFIG_HPP_
#define CONFIG_HPP_

//Macros
#define STR_H(x) #x     //Required for some reason
#define STR(x) STR_H(x)
//End macros



//Version info
#define VER_MAJOR 0
#define VER_MINOR 1
#define VER_BUILD 1

#define VERSION STR(VER_MAJOR) "." STR(VER_MINOR) "." STR(VER_BUILD)

#if defined(LIN)
#define PLAT "Linux"
#elif defined(MAC)
#define PLAT "Mac"
#elif defined(WIN)
#define PLAT "Windows"
#else
#define PLAT "Unknown platform"
#endif

#if defined(X64)
#define ARCH "x64_86"
#elif defined(X86)
#define ARCH "x86"
#else
#define ARCH "Unknown architecture"
#endif

#define SYSTEM PLAT " " ARCH
//End version info



//Platform specific stuff, because Windows wants to be special
#if defined(WIN)
#define NEWLINE "\r\n"
#define DIR_SEP "\\"
#else
#define NEWLINE "\n"
#define DIR_SEP "/"
#endif
//End Windows being special, also end of platform specific stuff



//Directory and file definitions
#define DIR_ROOT "." DIR_SEP

#define FILE_LOG DIR_ROOT "warctic.log"
//End directory and file definitions



#include "utils/Singleton.hpp"

class Config : public Singleton<Config>
{
private:
	uint logLevelTerm = 0x0F10; //Minimal log level to print in the terminal, default LOG_INFO
	uint logLevelFile = 0x0F20; //Minimal log level to print to the log file, default LOG_DEBUG
	
	bool logTermColor = true;
	
public:
	uint GetLogLevelTerm() { return logLevelTerm; }
	void SetLogLevelTerm(uint level) { logLevelTerm = level; }
	
	uint GetLogLevelFile() { return logLevelFile; }
	void SetLogLevelFile(uint level) { logLevelFile = level; }
	
	bool GetLogTermColor() { return logTermColor; }
	void SetLogTermColor(bool color) { logTermColor = color; }
};

#endif
