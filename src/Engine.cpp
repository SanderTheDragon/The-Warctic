#include "Engine.hpp"

#include <Ogre.h>
#include <SDL2/SDL.h>

#include "Config.hpp"
#include "ConfigurationFile.hpp"
#include "GameWindow.hpp"
#include "Input.hpp"
#include "Log.hpp"
#include "Macro.hpp"
#include "Scene.hpp"
#include "Utils.hpp"

Engine::Engine() :
	logManager(nullptr),
	renderSystem(nullptr),
	root(nullptr),
	config(nullptr),
	input(nullptr),
	scene(nullptr),
	window(nullptr),
	running(false)
{
	config = new ConfigurationFile();
	window = new GameWindow(this);
	input = new Input(this);
	scene = new Scene(this);
}

Engine::~Engine()
{
	DELETE(scene);
	DELETE(input);
	DELETE(window);
	DELETE(root);
	DELETE(logManager);
	DELETE(config);

	SDL_Quit();
}

bool Engine::init()
{
	config->read();

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
	renderSystem->setConfigOption("Full Screen", (config->getValue<bool>("bFullscreen", false)) ? "Yes" : "No");
	renderSystem->setConfigOption("Video Mode", Utils::combine(3, Utils::toString(config->getValue<int>("iWindowWidth", 1024)), "x", Utils::toString(config->getValue<int>("iWindowHeight", 768))));
	root->setRenderSystem(renderSystem);
	root->initialise(false);

	if (!window->init(root))
	{
		Log(LOG_ERROR) << "Failed to create window";
		return false;
	}

	if (!scene->init())
	{
		Log(LOG_ERROR) << "Failed to create scene manager";
		return false;
	}

	config->write();

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
