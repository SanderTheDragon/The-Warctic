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

void Event::Loop()
{
    while (SDL_PollEvent(&e))
    {
        switch (e.type)
        {
        case SDL_QUIT:
            ::running = false;
            break;
        case SDL_KEYUP:
            HandleKeyup();
            break;
        }
    }
}

void Event::HandleKeyup()
{
    switch (e.key.keysym.sym)
    {
    case SDLK_ESCAPE:
        ::running = false;
        break;
    }
}

Event::~Event()
{
    
}
