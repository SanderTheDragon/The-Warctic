#include "game/graphics/Window.hpp"

#include "Config.hpp"
#include "misc/Logger.hpp"
#include "misc/Errors.hpp"

Window::Window()
{
    
}

int Window::Initialize()
{
    Log(LOG_INFO) << "Creating window" << NEWLINE;
    
    window = SDL_CreateWindow("The Warctic", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 720, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    
    if (window == NULL)
        return ERR_WINDOW_SDL_CREATE;
    
    Log(LOG_INFO) << "Creating OpenGL context" << NEWLINE;
    
    oGLContext = SDL_GL_CreateContext(window);
    
    if (oGLContext == NULL)
        return ERR_WINDOW_OGL_CREATE;
    
    ::root->restoreConfig();
    
    Log(LOG_INFO) << "Starting Ogre" << NEWLINE;
    
    try
    {
        ::root->initialise(false);
    }
    catch (Ogre::InvalidStateException e)
    {
        Log(LOG_ERROR) << GetErrorMessage(ERR_OGRE_EXCEPTION) << e.what() << NEWLINE;
        return ERR_WINDOW_OGRE_INIT;
    }
    catch (Ogre::RenderingAPIException e)
    {
        Log(LOG_ERROR) << GetErrorMessage(ERR_OGRE_EXCEPTION) << e.what() << NEWLINE;
        return ERR_WINDOW_OGRE_INIT;
    }
    
    Log(LOG_INFO) << "Hooking Ogre into OpenGL context (created by SDL)" << NEWLINE;
    
    Ogre::NameValuePairList misc;
    
#if defined(WIN) //Windows is starting to annoy me
    SDL_SysWMinfo wmInfo;
    SDL_VERSION(&wmInfo.version);
    SDL_GetWMInfo(&wmInfo);
 
    size_t winHandle = reinterpret_cast<size_t>(wmInfo.window);
    size_t winGlContext = reinterpret_cast<size_t>(wmInfo.hglrc);
 
    misc["externalWindowHandle"] = Ogre::StringConverter::toString(winHandle);
    misc["externalGLContext"] = Ogre::StringConverter::toString(winGlContext);
#else
    misc["currentGLContext"] = Ogre::String("True");
#endif
    
    renderWindow = ::root->createRenderWindow("The Warctic", 720, 480, false, &misc);
    renderWindow->setVisible(true);
    
    return ERR_OK;
}

Window::~Window()
{
    SDL_GL_DeleteContext(oGLContext);
    SDL_DestroyWindow(window);
}
