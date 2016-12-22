#include "game/graphics/Window.hpp"

#include "Config.hpp"
#include "misc/Logger.hpp"
#include "misc/Errors.hpp"

Window::Window()
{
    
}

int Window::Initialize()
{
    Log(LOG_INFO) << "Creating window" << NEWLINE;
    
    int w = configFile->GetIntValue("GraphicsWindowSizeW");
    int h = configFile->GetIntValue("GraphicsWindowSizeH");
    
    if (w < 640)
    {
        Log(LOG_WARNING) << "Window width is too small, setting it to default" << NEWLINE;
        configFile->SetValue("GraphicsWindowSizeW", "720");
        
        uint error = configFile->Write();
        if (error != ERR_OK)
            Log(LOG_ERROR) << GetErrorMessage(error) << NEWLINE;
        
        w = configFile->GetIntValue("GraphicsWindowSizeW");
    }
    
    if (h < 480)
    {
        Log(LOG_WARNING) << "Window heigth is too small, setting it to default" << NEWLINE;
        configFile->SetValue("GraphicsWindowSizeH", "480");
        
        uint error = configFile->Write();
        if (error != ERR_OK)
            Log(LOG_ERROR) << GetErrorMessage(error) << NEWLINE;
        
        h = configFile->GetIntValue("GraphicsWindowSizeH");
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
