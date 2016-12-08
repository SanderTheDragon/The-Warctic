#include "game/event/Event.hpp"

#include "Config.hpp"
#include "misc/Logger.hpp"
#include "misc/Errors.hpp"

#include "misc/utils/String.hpp"

Event::Event()
{
    
}

std::string Event::ButtonName(uint button)
{
    switch (button)
    {
    case SDL_BUTTON_LEFT:
        return "Left button";
        break;
    case SDL_BUTTON_MIDDLE:
        return "Middle button";
        break;
    case SDL_BUTTON_RIGHT:
        return "Right button";
        break;
    case SDL_BUTTON_X1:
        return "Extra button 1";
        break;
    case SDL_BUTTON_X2:
        return "Extra button 2";
        break;
    }
    
    return GetErrorMessage(ERR_UNKNOWN);
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
            Log(LOG_DEBUG) << "Window close button was clicked" << NEWLINE;
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
        case SDL_MOUSEMOTION:
            return HandleMousemove();
            break;
        case SDL_MOUSEWHEEL:
            return HandleMousewheel();
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
    if (!::suppressed)
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
    if (!::suppressed)
        Log(LOG_DEBUG) << "Key \'" << SDL_GetKeyName(e.key.keysym.sym) << "\' was pressed" << NEWLINE;
    
    switch (e.key.keysym.sym)
    {
        
    }
    
    return ERR_OK;
}

int Event::HandleMouseup()
{
    if (!::suppressed)
        Log(LOG_DEBUG) << "\'" << ButtonName(e.button.button) << "\' was released at (" << e.button.x << "," << e.button.y << ")" << NEWLINE;
    
    return ERR_OK;
}

int Event::HandleMousedown()
{
    if (!::suppressed)
        Log(LOG_DEBUG) << "\'" << ButtonName(e.button.button) << "\' was pressed " << Utils::String::ToString(e.button.clicks) << " times at (" << e.button.x << "," << e.button.y << ")" << NEWLINE;
    
    Ui::Button* button = screen->GetButtonAt(e.button.x, e.button.y);
    
    if (button)
        button->GetCallback()();
    
    return ERR_OK;
}

int Event::HandleMousemove()
{
    if (!::suppressed && !::mouseSuppressed)
        Log(LOG_DEBUG) << "Mouse moved to (" << e.motion.x << "," << e.motion.y << ") = (" << e.motion.xrel << "," << e.motion.yrel << ")" << NEWLINE;
    
    return ERR_OK;
}

int Event::HandleMousewheel()
{
    int x = e.wheel.x;
    int y = e.wheel.y;
    
    if (e.wheel.direction == SDL_MOUSEWHEEL_FLIPPED)
    {
        x *= -1;
        y *= -1;
    }
    
    if (!::suppressed && !::mouseSuppressed)
        Log(LOG_DEBUG) << "Mouse wheel moved " << Utils::String::ToString(x) << " right and " << Utils::String::ToString(y) << " up" << NEWLINE;
    
    return ERR_OK;
}

int Event::HandleWindow()
{
    switch (e.window.event)
    {
    case SDL_WINDOWEVENT_HIDDEN:
        if (!::suppressed)
            Log(LOG_DEBUG) << "Window was hidden" << NEWLINE;
        return ERR_OK;
        break;
    case SDL_WINDOWEVENT_FOCUS_LOST:
        if (!::suppressed)
            Log(LOG_DEBUG) << "Window lost focus" << NEWLINE;
        return ERR_OK;
        break;
        
    case SDL_WINDOWEVENT_SHOWN:
        if (!::suppressed)
            Log(LOG_DEBUG) << "Window was shown" << NEWLINE;
        return ERR_OK;
        break;
    case SDL_WINDOWEVENT_FOCUS_GAINED:
        if (!::suppressed)
            Log(LOG_DEBUG) << "Window gained focus" << NEWLINE;
        return ERR_OK;
        break;
    
    case SDL_WINDOWEVENT_CLOSE:
        if (!::suppressed)
            Log(LOG_DEBUG) << "Window was closed" << NEWLINE;
        return ERR_OK;
        break;
    }
    
    return ERR_OK;
}

Event::~Event()
{
    
}
