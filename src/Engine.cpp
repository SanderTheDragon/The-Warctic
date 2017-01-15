#include "Engine.hpp"

#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_ttf.h"

#include "Config.hpp"
#include "misc/Logger.hpp"
#include "misc/Errors.hpp"

#include "misc/utils/Version.hpp"

ConfigFile* configFile;

Engine::Engine()
{
    graphics = new Graphics();
    event = new Event();
}

int Engine::Initialize()
{
    uint error = ERR_OK;
    
    Log(LOG_INFO) << "Reading \'" << FILE_CONFIG << "\'" << NEWLINE;
    
    ::configFile = new ConfigFile();
    error = configFile->Read();
    
    if (error != ERR_OK)
    {
        Log(LOG_ERROR) << GetErrorMessage(error) << NEWLINE;
        return ERR_ENGINE_IO_CONFIG_READ;
    }
    
    Log(LOG_INFO) << "Done (config)" << NEWLINE;
    
    Log(LOG_INFO) << "Initializing engine" << NEWLINE;
    Log(LOG_INFO) << "Initializing SDL" << NEWLINE;
    
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
        return ERR_ENGINE_SDL_INIT;
    
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
        return ERR_ENGINE_SDL_MIXER_INIT;
    
    if (TTF_Init() < 0)
        return ERR_ENGINE_SDL_TTF_INIT;
    
    Utils::Version::PrintSDL();
    
    Log(LOG_INFO) << "Done (SDL)" << NEWLINE;
    
    Log(LOG_INFO) << "Initializing graphics engine" << NEWLINE;
    
    error = graphics->Initialize();
    
    if (error != ERR_OK)
    {
        Log(LOG_ERROR) << GetErrorMessage(error) << NEWLINE;
        return ERR_ENGINE_GRAPHICS_INIT;
    }
    
    Log(LOG_INFO) << "Done (graphics engine)" << NEWLINE;
    
    Log(LOG_INFO) << "Initializing event handler" << NEWLINE;
    
    error = event->Initialize();
    
    if (error != ERR_OK)
    {
        Log(LOG_ERROR) << GetErrorMessage(error) << NEWLINE;
        return ERR_ENGINE_EVENT_INIT;
    }
    
    Log(LOG_INFO) << "Done (event handler)" << NEWLINE;
    
    Log(LOG_INFO) << "Done (engine)" << NEWLINE;
    
    ::running = true;
    
    return ERR_OK;
}

int Engine::Loop()
{
    event->Loop();
    
    ::screen->Update(event->GetMouseX(), event->GetMouseY());
    
    graphics->Loop();
    
    return ERR_OK;
}

Engine::~Engine()
{
    delete event;
    delete graphics;
    
    TTF_Quit();
    Mix_Quit();
    SDL_Quit();
}
