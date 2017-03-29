#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#define ERR_OK          0x0F0000 //No errors
#define ERR_UNKNOWN     0x0F0001 //An error code which should not be returned
#define ERR_EXIT        0x0F0002 //If the program has to exit without errors

#define ERR_INIT        0x0F0100 //Game failed to initialize for some reason
#define ERR_INIT_GLFW   0x0F0101 //Game failed to initialize, caused by glfwInit
#define ERR_INIT_GLEW   0x0F0102 //Game failed to initialize, caused by glewInit
#define ERR_INIT_WINDOW 0x0F0103 //Game failed to initialize, caused by glfwCreateWindow

#include <string>

extern std::string GetErrorMessage(uint code); //For error messages

#endif
