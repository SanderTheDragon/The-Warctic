#ifndef CONFIG_HPP_
#define CONFIG_HPP_

extern bool debug;  //Global variable, one is enough
extern bool colors; //It was not



//Version info
#define VER_MAJOR 0
#define VER_MINOR 1
#define VER_BUILD 1

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



#endif
