#ifndef EVENTS_HPP_
#define EVENTS_HPP_

#include "GL/glew.h"
#include "GLFW/glfw3.h"

class Events
{
private:
    static const char* KeyName(int key);
    
    static double mouseX, mouseY;
    
public:
    static void KeyHandle(GLFWwindow* window, int key, int scancode, int action, int mods);
    
    static void MouseButtonHandle(GLFWwindow* window, int button, int action, int mods);
    static void MouseMoveHandle(GLFWwindow* window, double x, double y);
};

#endif
