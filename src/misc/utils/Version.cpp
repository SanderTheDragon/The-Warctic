#include "misc/utils/Version.hpp"

#include "GL/gl.h"
#include "OGRE/OgrePrerequisites.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"

#include "Config.hpp"
#include "misc/Logger.hpp"

void Utils::Version::PrintWarctic(bool tabbed)
{
    if (tabbed)
        Log(LOG_NONE) << "\tVersion " << VERSION << NEWLINE;
    else
        Log(LOG_NONE) << "Version " << VERSION << NEWLINE;
    
//Unstable version warning
#ifdef UNSTABLE
    Log(LOG_WARNING) << "This is an unstable release!" << NEWLINE;
    Log(LOG_WARNING) << "Please report bugs to make it stable" << NEWLINE;
#endif
}

void Utils::Version::PrintSDL()
{
    SDL_version bCompiled;
    SDL_version bLinked;
    SDL_version mCompiled;
    const SDL_version* mLinked;
    
    SDL_VERSION(&bCompiled);
    SDL_GetVersion(&bLinked);
    
    SDL_MIXER_VERSION(&mCompiled);
    mLinked = Mix_Linked_Version();
    
    Log(LOG_SYSTEM) << "Compiled against SDL version: " << (int)bCompiled.major << "." << (int)bCompiled.minor << "." << (int)bCompiled.patch << NEWLINE;
    Log(LOG_SYSTEM) << "Linked against SDL version: " << (int)bLinked.major << "." << (int)bLinked.minor << "." << (int)bLinked.patch << NEWLINE;
    
    if (bLinked.major < bCompiled.major || bLinked.minor < bCompiled.minor || bLinked.patch < bCompiled.patch)
        Log(LOG_WARNING) << "SDL was compiled against a higher version, consider updating SDL" << NEWLINE;
    
    Log(LOG_SYSTEM) << "Compiled against SDL_mixer version: " << (int)mCompiled.major << "." << (int)mCompiled.minor << "." << (int)mCompiled.patch << NEWLINE;
    Log(LOG_SYSTEM) << "Linked against SDL_mixer version: " << (int)mLinked->major << "." << (int)mLinked->minor << "." << (int)mLinked->patch << NEWLINE;
    
    if (mLinked->major < mCompiled.major || mLinked->minor < mCompiled.minor || mLinked->patch < mCompiled.patch)
        Log(LOG_WARNING) << "SDL_mixer was compiled against a higher version, consider updating SDL_mixer" << NEWLINE;
}

void Utils::Version::PrintOgre()
{
    Log(LOG_SYSTEM) << "Ogre3D version: " << OGRE_VERSION_MAJOR << "." << OGRE_VERSION_MINOR << "." << OGRE_VERSION_PATCH  << " (" << OGRE_VERSION_NAME ")" << NEWLINE;
}

void Utils::Version::PrintOpenGL()
{
    Log(LOG_SYSTEM) << "OpenGL version: " << glGetString(GL_VERSION) << NEWLINE;
    Log(LOG_SYSTEM) << "OpenGL vendor: " << glGetString(GL_VENDOR) << NEWLINE;
    Log(LOG_SYSTEM) << "OpenGL renderer: " << glGetString(GL_RENDERER) << NEWLINE;
    Log(LOG_SYSTEM) << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << NEWLINE;
}
