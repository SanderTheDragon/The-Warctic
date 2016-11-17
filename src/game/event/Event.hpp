#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <string>

#include "SDL2/SDL.h"

class Event
{
private:
    SDL_Event e;
    
    std::string ButtonName(uint button);
    
public:
    Event();
    
    int Initialize();
    
    int Loop();
    
    int HandleKeyup();
    int HandleKeydown();
    int HandleMouseup();
    int HandleMousedown();
    int HandleMousemove();
    int HandleMousewheel();
    int HandleWindow();
    
    ~Event();
};

#endif
