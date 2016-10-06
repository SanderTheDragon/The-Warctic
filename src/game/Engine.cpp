#include "game/Engine.hpp"

#include "Config.hpp"
#include "misc/Logger.hpp"
#include "misc/utils/Version.hpp"

Engine::Engine()
{
    Log(LOG_INFO) << "Initializing engine" << NEWLINE;
    Log(LOG_INFO) << "Initializing SDL" << NEWLINE;
    
    
    
    graphics = new Graphics();
    event = new Event();
    
    Utils::Version::PrintSDL();
    
    bool running = true;
}

void Engine::Loop()
{
    event->Loop();
}

Engine::~Engine()
{
    graphics->~Graphics();
}
