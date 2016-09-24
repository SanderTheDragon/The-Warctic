#ifndef CONFIG_HPP_
#define CONFIG_HPP_

#define VER_MAJOR 0
#define VER_MINOR 1
#define VER_BUILD 1

#if defined(WIN)
#define PATH_SEP "\\"
#define NEWLINE "\r\n"
#else
#define PATH_SEP "/"
#define NEWLINE "\n"
#endif

#define RES "res"
#define RES_OBJECTS RES PATH_SEP "objects"
#define RES_TEXTURES RES PATH_SEP "textures"
#define RES_SOUNDS RES PATH_SEP "sounds"

#endif
