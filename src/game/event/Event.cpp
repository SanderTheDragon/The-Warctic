#include "game/event/Event.hpp"

#include "Config.hpp"
#include "misc/Logger.hpp"
#include "misc/Errors.hpp"

Event::Event()
{
    
}

int Event::Initialize() //Not needed for anything, it just sits here, I don't know why
{
    return ERR_OK;
}

int Event::Loop()
{
    while (SDL_PollEvent(&e))
    {
        switch (e.type)
        {
        case SDL_QUIT:
            ::running = false;
            return ERR_OK;
            break;
        case SDL_KEYUP:
            return HandleKeyup();
            break;
        case SDL_KEYDOWN:
            return HandleKeydown();
            break;
        case SDL_MOUSEBUTTONUP:
            return HandleMouseup();
            break;
        case SDL_MOUSEBUTTONDOWN:
            return HandleMousedown();
            break;
        case SDL_WINDOWEVENT:
            return HandleWindow();
            break;
        }
    }
    
    return ERR_OK;
}

int Event::HandleKeyup()
{
    Log(LOG_DEBUG) << "Key \'" << SDL_GetKeyName(e.key.keysym.sym) << "\' was released" << NEWLINE;
    
    switch (e.key.keysym.sym)
    {
    case SDLK_ESCAPE:
        ::running = false;
        return ERR_OK;
        break;
    }
    
    return ERR_OK;
}

int Event::HandleKeydown()
{
    Log(LOG_DEBUG) << "Key \'" << SDL_GetKeyName(e.key.keysym.sym) << "\' was pressed" << NEWLINE;
    
    switch (e.key.keysym.sym)
    {
        
    }
    
    return ERR_OK;
}

int Event::HandleMouseup()
{
    Log(LOG_DEBUG) << "\'" << e.button.button << "\' was released at (" << e.button.x << "," << e.button.y << ")" << NEWLINE;
    
    return ERR_OK;
}

int Event::HandleMousedown()
{
    Log(LOG_DEBUG) << "\'" << e.button.button << "\' was pressed at (" << e.button.x << "," << e.button.y << ")" << NEWLINE;
    
    return ERR_OK;
}

int Event::HandleWindow()
{
    switch (e.window.event)
    {
    case SDL_WINDOWEVENT_HIDDEN:
        Log(LOG_DEBUG) << "Window was hidden" << NEWLINE;
        return ERR_OK;
        break;
    case SDL_WINDOWEVENT_FOCUS_LOST:
        Log(LOG_DEBUG) << "Window lost focus" << NEWLINE;
        return ERR_OK;
        break;
        
    case SDL_WINDOWEVENT_SHOWN:
        Log(LOG_DEBUG) << "Window was shown" << NEWLINE;
        return ERR_OK;
        break;
    case SDL_WINDOWEVENT_FOCUS_GAINED:
        Log(LOG_DEBUG) << "Window gained focus" << NEWLINE;
        return ERR_OK;
        break;
    }
    
    return ERR_OK;
}

Event::~Event()
{
    
}
