#include "Engine.hpp"

#include <fstream>

#include <OgrePrerequisites.h>
#include <SDL2/SDL_version.h>

#include "Config.hpp"
#include "ConfigurationFile.hpp"
#include "Log.hpp"

//Create a log file
std::ofstream Log::file("out.log");

int main(int argc, char* argv[])
{
	Log(LOG_INFO) << "Starting `The Warctic` version " << VERSION_STRING;
	Log(LOG_INFO) << "Using OGRE version " << OGRE_VERSION_MAJOR << "." << OGRE_VERSION_MINOR << "." << OGRE_VERSION_PATCH << "-" << OGRE_VERSION_SUFFIX;

	SDL_version compiled;
	SDL_VERSION(&compiled);
	Log(LOG_DEBUG) << "Compiled against SDL version " << (int)compiled.major << "." << (int)compiled.minor << "." << (int)compiled.patch;

	SDL_version linked;
	SDL_GetVersion(&linked);
	Log(LOG_INFO) << "Using SDL version " << (int)linked.major << "." << (int)linked.minor << "." << (int)linked.patch;

	Engine* const engine = new Engine();

	if (!engine->init())
	{
		Log(LOG_FATAL) << "Failed to initialize engine";
		return -1;
	}

	while (engine->isRunning())
	{
		engine->loop();
	}

	engine->getConfig()->write();

	delete engine;
}
