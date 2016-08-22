#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <iostream>

#define ERR_OK                      0x0000

#define ERR_ENGINE_UNKNOWN          0x0100
#define ERR_ENGINE_INITIALIZE       0x0101
#define ERR_ENGINE_GLFW_INITIALIZE  0x0102

#define ERR_GRAPHICS_UNKNOW         0x0200
#define ERR_GRAPHICS_INITIALIZE     0x0201

#define ERR_WINDOW_UNKNOWN          0x0300
#define ERR_WINDOW_INITIALIZE       0x0301
#define ERR_WINDOW_NULL             0x0302
#define ERR_WINDOW_GLEW_INITIALIZE  0x0303

#define ERR_FILE_UNKNOWN            0x0400
#define ERR_FILE_NOT_OPEN           0x0401

extern const char* GetErrorString(uint err);

#endif
