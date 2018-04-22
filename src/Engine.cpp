#include "Engine.hpp"

#include <Ogre.h>
#include <SDL2/SDL.h>

#include "Config.hpp"
#include "GameWindow.hpp"
#include "Input.hpp"
#include "Log.hpp"
#include "Macro.hpp"

Engine::Engine() :
	logManager(nullptr),
	renderSystem(nullptr),
	root(nullptr),
	window(nullptr),
	input(nullptr),
	running(false)
{
	window = new GameWindow();
	input = new Input(this);
}

Engine::~Engine()
{
	DELETE(window);
	DELETE(root);
	DELETE(logManager);

	SDL_Quit();
}

bool Engine::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		Log(LOG_ERROR) << "Failed to intialize SDL2";
		return false;
	}

	//Disable logging in OGRE
	logManager = new Ogre::LogManager();
	logManager->createLog("", true, false, true);

	root = new Ogre::Root("", "", "");

	root->loadPlugin(PATH_PLUGINS "RenderSystem_GL3Plus.so");
	renderSystem = root->getRenderSystemByName("OpenGL 3+ Rendering Subsystem");
	renderSystem->setConfigOption("Full Screen", "No");
	renderSystem->setConfigOption("Video Mode", "1024x768");
	root->setRenderSystem(renderSystem);
	root->initialise(false);

	if (!window->init(root))
	{
		Log(LOG_ERROR) << "Failed to create window";
		return false;
	}

	return (running = true);
}

void Engine::stop()
{
	running = false;
}

void Engine::loop()
{
	input->loop();

	root->renderOneFrame();
	SDL_GL_SwapWindow(window->getSDL_Window());
}
