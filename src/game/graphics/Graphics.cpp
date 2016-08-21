#include "game/graphics/Graphics.hpp" 

#include "Config.hpp"
#include "misc/Error.hpp"
#include "misc/Logger.hpp"

Graphics::Graphics()
{
    window = new Window();
}

uint Graphics::Initialize()
{
    int error = ERR_OK;
    
    Log(LOG_INFO) << "Initializing window" << NEWLINE;
    
    error = window->Initialize();
    if (error != ERR_OK)
    {
        Log(LOG_ERROR) << GetErrorString(error) << NEWLINE;
        return ERR_GRAPHICS_INITIALIZE;
    }
    
    return ERR_OK;
}

Graphics::~Graphics()
{
    window->~Window();
    
    glfwTerminate();
}
