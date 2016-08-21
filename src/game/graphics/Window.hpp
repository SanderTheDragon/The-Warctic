#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <iostream>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

class Window
{
private:
    GLFWwindow* window;
    
public:
    Window();
    
    uint Initialize();
    GLFWwindow* GetGLFWWindow() { return window; }
    
    void Show();
    
    virtual ~Window();
};

#endif
