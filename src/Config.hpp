#ifndef CONFIG_HPP_
#define CONFIG_HPP_

#include "game/io/ConfigFile.hpp"
#include "game/ui/toolkit/Screen.hpp"



//I'll just live with them
extern bool debug;              //Debug mode
extern bool colors;             //Terminal colors
extern bool running;            //Should stop running if false
extern bool suppressed;         //Suppress event output
extern bool mouseSuppressed;    //Only suppress mouse motion event output
extern ConfigFile* configFile;  //Configuration read/write
extern Ui::Screen* screen;      //Current shown screen



//Macros
#define STR_H(x) #x     //Required for some reason
#define STR(x) STR_H(x)

#define WINDOW_W() configFile->GetIntValue("GraphicsWindowSizeW")
#define WINDOW_H() configFile->GetIntValue("GraphicsWindowSizeH")
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
//End Windows being special



//Directory definitions
#define DIR_ROOT "." DIR_SEP
#define DIR_RESOURCE DIR_ROOT "resources" DIR_SEP
//End directory definitions



//File definitions
#define FILE_CONFIG DIR_ROOT "warctic.cfg"

#define RESOURCE_OTHER DIR_RESOURCE "other.zip"
//End file definitions



#endif
