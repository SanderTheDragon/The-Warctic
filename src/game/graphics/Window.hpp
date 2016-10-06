#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "SDL2/SDL.h"

class Window
{
private:
    SDL_Window* window;
    
public:
    Window();
    
    SDL_Window* GetWindow() { return window; }
    
    virtual ~Window();
};

#endif
