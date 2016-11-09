#ifndef ENGINE_HPP_
#define ENGINE_HPP_

#include "game/graphics/Graphics.hpp"
#include "game/event/Event.hpp"
#include "game/io/ConfigFile.hpp"

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
