#ifndef ENGINE_HPP_
#define ENGINE_HPP_

#include "game/graphics/Graphics.hpp"
#include "game/event/Event.hpp"

class Engine
{
private:
    bool running;
    
    Graphics* graphics;
    Event* event;
    
public:
    Engine();
    
    bool IsRunning() { return running; }
    
    void Loop();
    void SDLVersions();
    
    virtual ~Engine();
};

#endif
