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
    
    int w = Utils::String::ToInt(configFile->GetValue("GraphicsWindowSizeW"));
    int h = Utils::String::ToInt(configFile->GetValue("GraphicsWindowSizeH"));
    
    if (w == 0)
    {
        Log(LOG_WARNING) << "Window width is too small, setting it to default" << NEWLINE;
        configFile->SetValue("GraphicsWindowSizeW", "720");
        
        uint error = configFile->Write();
        if (error != ERR_OK)
            Log(LOG_ERROR) << GetErrorMessage(error) << NEWLINE;
    }
    
    if (h == 0)
    {
        Log(LOG_WARNING) << "Window heigth is too small, setting it to default" << NEWLINE;
        configFile->SetValue("GraphicsWindowSizeH", "480");
        
        uint error = configFile->Write();
        if (error != ERR_OK)
            Log(LOG_ERROR) << GetErrorMessage(error) << NEWLINE;
    }
    
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
