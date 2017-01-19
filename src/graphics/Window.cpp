#include "graphics/Window.hpp"

#include "Config.hpp"
#include "misc/Logger.hpp"
#include "misc/Errors.hpp"

Window::Window()
{
    
}

int Window::Initialize()
{
    uint error = ERR_OK;
    
    Log(LOG_INFO) << "Creating window" << NEWLINE;
    
    int w = ::configFile->GetIntValue("iGraphicsWindowSizeW");
    int h = ::configFile->GetIntValue("iGraphicsWindowSizeH");
    
    if (w < 640)
    {
        Log(LOG_WARNING) << "Window width is too small, setting it to default" << NEWLINE;
        ::configFile->SetValue("iGraphicsWindowSizeW", "720");
        
        error = ::configFile->Write();
        
        if (error != ERR_OK)
            Log(LOG_ERROR) << GetErrorMessage(error) << NEWLINE;
        
        w = ::configFile->GetIntValue("iGraphicsWindowSizeW");
    }
    
    if (h < 480)
    {
        Log(LOG_WARNING) << "Window heigth is too small, setting it to default" << NEWLINE;
        ::configFile->SetValue("iGraphicsWindowSizeH", "480");
        
        error = ::configFile->Write();
        
        if (error != ERR_OK)
            Log(LOG_ERROR) << GetErrorMessage(error) << NEWLINE;
        
        h = ::configFile->GetIntValue("iGraphicsWindowSizeH");
    }
    
    Log(LOG_DEBUG) << "Window size: " << w << "x" << h << NEWLINE;
    
    window = SDL_CreateWindow("The Warctic", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
    
    if (window == NULL)
        return ERR_WINDOW_SDL_CREATE;
    
    return error;
}

Window::~Window()
{
    SDL_DestroyWindow(window);
}
