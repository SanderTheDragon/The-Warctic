#ifndef GRAPHICS_HPP_
#define GRAPHICS_HPP_

#include <iostream>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "game/graphics/Window.hpp"

class Graphics
{
private:
    Window* window;
    
public:
    Graphics();
    
    uint Initialize();
    Window* GetWindow() { return window; }
    
    virtual ~Graphics();
};

#endif
