#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "OGRE/OgreString.h"
#include "OGRE/OgreRenderWindow.h"
#include "OGRE/OgreStringConverter.h"
#include "SDL2/SDL.h"

class Window
{
private:
    SDL_Window* window;
    SDL_GLContext oGLContext;
    
    Ogre::RenderWindow* renderWindow;
    
public:
    Window();
    
    SDL_Window* GetWindow() { return window; }
    
    int Initialize();
    
    virtual ~Window();
};

#endif
