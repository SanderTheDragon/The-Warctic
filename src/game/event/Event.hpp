#ifndef EVENT_HPP_
#define EVENT_HPP_

#include "SDL2/SDL.h"

class Event
{
private:
    SDL_Event e;
    
public:
    Event();
    
    int Initialize();
    
    void Loop();
    void HandleKeyup();
    
    ~Event();
};

#endif
