#include "game/graphics/Graphics.hpp"

#include "Config.hpp"
#include "misc/Logger.hpp"
#include "misc/Errors.hpp"

Graphics::Graphics()
{
    window = new Window();
}

int Graphics::Initialize()
{
    int error;
    
    Log(LOG_INFO) << "Initializing window" << NEWLINE;
    
    error = window->Initialize();
    
    if (error != ERR_OK)
    {
        Log(LOG_ERROR) << GetErrorMessage(error) << NEWLINE;
        return ERR_GRAPHICS_WINDOW_INIT;
    }
    
    Log(LOG_INFO) << "Done (window)" << NEWLINE;
    
    Log(LOG_INFO) << "Creating renderer" << NEWLINE;
    
    renderer = SDL_CreateRenderer(window->GetWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    if (renderer == NULL)
        return ERR_GRAPHICS_RENDERER_CREATE;
    
    Log(LOG_INFO) << "Done (renderer)" << NEWLINE;
    
    return ERR_OK;
}

int Graphics::Loop()
{
    SDL_RenderClear(renderer);
    
    SDL_RenderPresent(renderer);
    
    return ERR_OK;
}

Graphics::~Graphics()
{
    SDL_DestroyRenderer(renderer);
    
    window->~Window();
}
