#ifndef ENGINE_HPP_
#define ENGINE_HPP_

#include "graphics/Graphics.hpp"
#include "event/Event.hpp"
#include "io/ConfigFile.hpp"

class Engine
{
private:
    Graphics* graphics;
    Event* event;
    
public:
    Engine();
    
    int Initialize();
    
    int Loop();
    
    virtual ~Engine();
};

#endif
