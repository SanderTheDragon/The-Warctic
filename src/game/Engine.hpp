#ifndef ENGINE_HPP_
#define ENGINE_HPP_

#include "OGRE/OgreRoot.h"

#include "game/graphics/Graphics.hpp"
#include "game/event/Event.hpp"

class Engine
{
private:
    Graphics* graphics;
    Event* event;
    
public:
    Engine();
    
    int Initialize();
    
    void Loop();
    
    virtual ~Engine();
};

#endif
