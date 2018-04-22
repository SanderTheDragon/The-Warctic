#ifndef ENGINE_HPP_
#define ENGINE_HPP_

#include <OgreLogManager.h>
#include <OgreRoot.h>

class GameWindow;
class Input;

class Engine
{
public:
	Engine();
	~Engine();

	bool init();
	void stop();
	void loop();

	bool isRunning() { return running; }

private:
	Ogre::LogManager* logManager;
	Ogre::RenderSystem* renderSystem;
	Ogre::Root* root;

	GameWindow* window;
	Input* input;

	bool running;
};

#endif
