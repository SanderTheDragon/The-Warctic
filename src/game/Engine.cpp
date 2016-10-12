#include "game/Engine.hpp"

#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"

#include "Config.hpp"
#include "misc/Logger.hpp"
#include "misc/Errors.hpp"

#include "misc/utils/Version.hpp"

Ogre::Root* root;

Engine::Engine()
{
    graphics = new Graphics();
    event = new Event();
}

int Engine::Initialize()
{
    int error;
    
    Log(LOG_INFO) << "Initializing engine" << NEWLINE;
    Log(LOG_INFO) << "Initializing SDL" << NEWLINE;
    
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
        return ERR_ENGINE_SDL_INIT;
    
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
        return ERR_ENGINE_SDL_MIXER_INIT;
    
    Utils::Version::PrintSDL();
    
    Log(LOG_INFO) << "Done (SDL)" << NEWLINE;
    
    Log(LOG_INFO) << "Creating OGRE root" << NEWLINE;
    
    //Disable Ogre output
    Ogre::LogManager* ogLog = new Ogre::LogManager;
    ogLog->createLog("ogLog", true, false, true);
    
    ::root = new Ogre::Root(FILE_PLUGINS, FILE_CONFIG);
    
    Utils::Version::PrintOgre();
    
    Log(LOG_INFO) << "Done (Ogre)" << NEWLINE;
    
    Log(LOG_INFO) << "Initializing graphics engine" << NEWLINE;
    
    error = graphics->Initialize();
    
    if (error != ERR_OK)
    {
        Log(LOG_ERROR) << GetErrorMessage(error) << NEWLINE;
        return ERR_ENGINE_GRAPHICS_INIT;
    }
    
    Utils::Version::PrintOpenGL();
    
    Log(LOG_INFO) << "Done (graphics engine)" << NEWLINE;
    
    Log(LOG_INFO) << "Initializing event handler" << NEWLINE;
    
    event->Initialize();
    
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

void Engine::Loop()
{
    graphics->Loop();
    
    event->Loop();
}

Engine::~Engine()
{
    event->~Event();
    graphics->~Graphics();
    
    delete ::root;
    
    Mix_Quit();
    SDL_Quit();
}
