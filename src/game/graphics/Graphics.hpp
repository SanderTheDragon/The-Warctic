#ifndef GRAPHICS_HPP_
#define GRAPHICS_HPP_

#include "game/graphics/Window.hpp"

class Graphics
{
private:
    Window* window;
    
public:
    Graphics();
    
    Window* GetWindow() { return window; }
    
    virtual ~Graphics();
};

#endif
