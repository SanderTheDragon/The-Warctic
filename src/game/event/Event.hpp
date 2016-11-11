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
    
    int Loop();
    
    int HandleKeyup();
    int HandleKeydown();
    int HandleMouseup();
    int HandleMousedown();
    int HandleMousemove();
    int HandleWindow();
    
    ~Event();
};

#endif
