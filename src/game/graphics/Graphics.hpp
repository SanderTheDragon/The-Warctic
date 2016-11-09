#ifndef GRAPHICS_HPP_
#define GRAPHICS_HPP_

#include "SDL2/SDL.h"

#include "game/graphics/Window.hpp"

class Graphics
{
private:
    SDL_Renderer* renderer;
    
    Window* window;
    
public:
    Graphics();
    
    Window* GetWindow() { return window; }
    
    int Initialize();
    
    int Loop();
    
    virtual ~Graphics();
};

#endif
