#include "misc/Errors.hpp"

#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_ttf.h"

#include "misc/utils/String.hpp"

//This returns the error message for a certain error code
std::string GetErrorMessage(uint error)
{
    switch (error)
    {
    case ERR_OK: //If there is no error, something still failed
    case ERR_UNKNOWN:
        return "Unknown error";
        break;
    
    case ERR_ENGINE_UNKNOWN:
        return "Unknown engine error";
        break;
    case ERR_ENGINE_INIT:
        return "Engine failed to initialize";
        break;
    case ERR_ENGINE_SDL_INIT:
        return Utils::String::Combine(2, "Engine failed to initialize, caused by SDL_Init(): ", SDL_GetError());
        break;
    case ERR_ENGINE_SDL_MIXER_INIT:
        return Utils::String::Combine(2, "Engine failed to initialize, caused by Mix_OpenAudio(): ", Mix_GetError());
        break;
    case ERR_ENGINE_GRAPHICS_INIT:
        return "Engine failed to initialize, caused by graphics->Initialize()";
        break;
    case ERR_ENGINE_EVENT_INIT:
        return "Engine failed to initialize, caused by event->Initialize()";
        break;
    case ERR_ENGINE_SDL_TTF_INIT:
        return Utils::String::Combine(2, "Engine failed to initialize, caused by Ttf_Init(): ", TTF_GetError());
        break;
    case ERR_ENGINE_IO_CONFIG_READ:
        return "Engine failed to initialize, caused by configFile->Read()";
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
        return Utils::String::Combine(2, "Graphics engine failed to initialize: caused by SDL_CreateRenderer(): ", SDL_GetError());
        break;
    case ERR_GRAPHICS_SCREEN_INIT:
        return "Graphics engine failed to initialize screen: caused by screen->Initialize()";
        break;
        
        
    case ERR_WINDOW_UNKNOWN:
        return "Unknown window error";
        break;
    case ERR_WINDOW_INIT:
        return "Window failed to initialize";
        break;
    case ERR_WINDOW_SDL_CREATE:
        return Utils::String::Combine(2, "Window failed to initialize, caused by SDL_CreateWindow(): ", SDL_GetError());
        break;
    
    case ERR_FILE_UNKNOWN:
        return "Unknown file error";
        break;
    case ERR_FILE_CONFIG_KEYNOTFOUND:
        return "Failed to find key: ";
        break;
    case ERR_FILE_CONFIG_OPEN:
        return "Failed to open configuration file";
        break;
        
    case ERR_RESOURCE_UNKNOWN:
        return "Unknown resource error";
        break;
    case ERR_RESOURCE_ARCHIVEOPEN:
        return "Failed to open resource archive";
        break;
    case ERR_RESOURCE_FILENOTFOUND:
        return "Failed to find file in resource archive";
        break;
    case ERR_RESOURCE_FILEINFO:
        return "Failed to get file info from resource archive";
        break;
    case ERR_RESOURCE_FILEOPEN:
        return "Failed to open file in resource archive";
        break;
    case ERR_RESOURCE_FILEREAD:
        return "Failed to read file from resource archive";
        break;
    case ERR_RESOURCE_LOAD:
        return "Failed to load important resources";
        break;
        
    default:
        return Utils::String::Combine(5, "Could not find message for error ", Utils::String::ToString(error).c_str(), " (", Utils::String::ToHexString(error).c_str(), ")");
        break;
    }
} 
