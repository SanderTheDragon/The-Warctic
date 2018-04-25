#ifndef ENGINE_HPP_
#define ENGINE_HPP_

#include <OgreLogManager.h>
#include <OgreRoot.h>

class ConfigurationFile;
class GameWindow;
class Input;
class Scene;

class Engine
{
public:
	Engine();
	~Engine();

	bool init();
	void stop();
	void loop();

	bool const isRunning() { return running; }

	Ogre::Root* const getRoot() { return root; }

	ConfigurationFile* const getConfig() { return config; }

private:
	Ogre::LogManager* logManager;
	Ogre::RenderSystem* renderSystem;
	Ogre::Root* root;

	ConfigurationFile* config;
	GameWindow* window;
	Input* input;
	Scene* scene;

	bool running;
};

#endif
