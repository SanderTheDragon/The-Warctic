#include "game/graphics/Graphics.hpp"

#include "GL/gl.h"

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
    
    glClearColor(0, 0, 0, 1);
    
    Log(LOG_INFO) << "Done (renderer)" << NEWLINE;
    
    return ERR_OK;
}

void Graphics::Loop()
{
    //SDL_RenderClear(renderer);
    glClear(GL_COLOR_BUFFER_BIT);
    
    
    
    ::root->renderOneFrame();
    SDL_GL_SwapWindow(window->GetWindow());
    //SDL_RenderPresent(renderer);
}

Graphics::~Graphics()
{
    SDL_DestroyRenderer(renderer);
    
    window->~Window();
}
