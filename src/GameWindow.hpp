#ifndef GAMEWINDOW_HPP_
#define GAMEWINDOW_HPP_

#include <OgreRenderWindow.h>
#include <OgreRoot.h>
#include <SDL2/SDL.h>

class Engine;

class GameWindow
{
public:
	GameWindow(Engine* engine);
	~GameWindow();

	bool init(Ogre::Root* root);

	Ogre::RenderWindow* getRenderWindow() { return renderWindow; }
	SDL_Window* getSDL_Window() { return window; }

private:
	Ogre::RenderWindow* renderWindow;
	SDL_Window* window;
	SDL_GLContext context;

	Ogre::String windowHandle;

	Engine* engine;
};

#endif
