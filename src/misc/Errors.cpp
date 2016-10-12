#include "misc/Errors.hpp"

#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"

#include "misc/utils/String.hpp"

const char* GetErrorMessage(uint error)
{
    switch (error)
    {
    case ERR_UNKNOWN:
        return "Unknown error";
        break;
    case ERR_OGRE_EXCEPTION:
        return "Ogre has thrown an exception: ";
        break;
    
    case ERR_ENGINE_UNKNOWN:
        return "Unknown engine error";
        break;
    case ERR_ENGINE_INIT:
        return "Engine failed to initialize";
        break;
    case ERR_ENGINE_SDL_INIT:
        return Utils::String::Combine(2, "Engine failed to initialize, caused by SDL_Init(): ", SDL_GetError()).c_str();
        break;
    case ERR_ENGINE_SDL_MIXER_INIT:
        return Utils::String::Combine(2, "Engine failed to initialize, caused by Mix_OpenAudio(): ", Mix_GetError()).c_str();
        break;
    case ERR_ENGINE_GRAPHICS_INIT:
        return "Engine failed to initialize, caused by graphics->Initialize()";
        break;
    case ERR_ENGINE_EVENT_INIT:
        return "Engine failed to initialize, caused by event->Initialize()";
        break;
        
    case ERR_GRAPHICS_UNKNOWN:
        return "Unknown graphics engine error";
        break;
    case ERR_GRAPHICS_INIT:
        return "Graphics engine failed to initialize";
        break;
    case ERR_GRAPHICS_WINDOW_INIT:
        return "Graphics engine failed to initialize: caused by window->Initialize()";
        break;
    case ERR_GRAPHICS_RENDERER_CREATE:
        return Utils::String::Combine(2, "Graphics engine failed to initialize: caused by SDL_CreateRenderer(): ", SDL_GetError()).c_str();
        break;
        
        
    case ERR_WINDOW_UNKNOWN:
        return "Unknown window error";
        break;
    case ERR_WINDOW_INIT:
        return "Window failed to initialize";
        break;
    case ERR_WINDOW_SDL_CREATE:
        return Utils::String::Combine(2, "Window failed to initialize, caused by SDL_CreateWindow(): ", SDL_GetError()).c_str();
        break;
    case ERR_WINDOW_OGRE_INIT:
        return "Window failed to initialize, caused by root->initialise()";
        break;
    case ERR_WINDOW_OGL_CREATE:
        return Utils::String::Combine(2, "Window failed to initialize, caused by SDL_GL_CreateContext(): ", SDL_GetError()).c_str();
        break;
        
    default:
        std::string tmp = Utils::String::Combine(5, "Could not find message for error ", Utils::String::ToString(error).c_str(), " (", Utils::String::ToHexString(error).c_str(), ")");
        return tmp.c_str();
        break;
    }
} 
