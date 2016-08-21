#ifndef ENGINE_HPP_
#define ENGINE_HPP_

#include <iostream>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "game/events/Events.hpp"
#include "game/graphics/Graphics.hpp"

class Engine
{
private:
    bool running;
    
    Graphics* graphics;
    
public:
    Engine();
    
    uint Initialize();
    bool IsRunning() { return running; }
    
    void Stop() { running = false; }
    void Loop();
    
    static void GLFW_Error(int code, const char* message);
    
    virtual ~Engine();
};

#endif
