#include "game/graphics/Window.hpp"

#include "Config.hpp"
#include "misc/Logger.hpp"
#include "misc/Errors.hpp"

#include "misc/utils/String.hpp"

Window::Window()
{
    
}

int Window::Initialize()
{
    Log(LOG_INFO) << "Creating window" << NEWLINE;
    
    int w = Utils::String::ToInt(configFile->GetValue("Graphics_Window_Size_W"));
    int h = Utils::String::ToInt(configFile->GetValue("Graphics_Window_Size_H"));
    
    Log(LOG_DEBUG) << "Window size: " << w << "x" << h << NEWLINE;
    
    window = SDL_CreateWindow("The Warctic", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
    
    if (window == NULL)
        return ERR_WINDOW_SDL_CREATE;
    
    return ERR_OK;
}

Window::~Window()
{
    SDL_DestroyWindow(window);
}
