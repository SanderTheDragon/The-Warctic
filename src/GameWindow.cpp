#include "GameWindow.hpp"

#include <Ogre.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>

#include "Config.hpp"
#include "ConfigurationFile.hpp"
#include "Engine.hpp"
#include "Log.hpp"
#include "Utils.hpp"

GameWindow::GameWindow(Engine* engine) :
	engine(engine),
	renderWindow(nullptr),
	window(nullptr)
{

}

GameWindow::~GameWindow()
{
	if (renderWindow != nullptr)
	{
		renderWindow->destroy();
	}

	SDL_GL_DeleteContext(context);

	if (window != nullptr)
	{
		SDL_DestroyWindow(window);
	}
}

bool GameWindow::init(Ogre::Root* root)
{
	int glMajor = engine->getConfig()->getValue<int>("iOpenGLMajor", 3);
	int glMinor = engine->getConfig()->getValue<int>("iOpenGLMinor", 3);
	if (glMajor > 4 || glMajor < 3 || (glMajor == 3 && glMinor > 3) || (glMajor == 4 && glMinor > 6))
	{
		Log(LOG_WARNING) << glMajor << "." << glMinor << " is not a valid OpenGL version, using 3.3";

		glMajor = glMinor = 3;
		engine->getConfig()->setValue<int>("iOpenGLMajor", glMajor);
		engine->getConfig()->setValue<int>("iOpenGLMinor", glMinor);
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, glMajor);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, glMinor);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	int const windowWidth = engine->getConfig()->getValue<int>("iWindowWidth", 1024);
	int const windowHeight = engine->getConfig()->getValue<int>("iWindowHeight", 768);
	window = SDL_CreateWindow("The Warctic " VERSION_STRING, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_OPENGL);
	if (window == nullptr)
	{
		Log(LOG_ERROR) << "Failed to create SDL_Window: " << SDL_GetError();
		return false;
	}

	context = SDL_GL_CreateContext(window);
	if (context == NULL)
	{
		Log(LOG_ERROR) << "Failed to create OpenGL context: " << SDL_GetError();
		return false;
	}
	SDL_GL_MakeCurrent(window, context);

	int gl_major, gl_minor, gl_profile;
	SDL_GL_GetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, &gl_major);
	SDL_GL_GetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, &gl_minor);
	SDL_GL_GetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, &gl_profile);

	Ogre::String profile;
	if (gl_profile == SDL_GL_CONTEXT_PROFILE_CORE)
	{
		profile = "Core";
	}
	else if (gl_profile == SDL_GL_CONTEXT_PROFILE_COMPATIBILITY)
	{
		profile = "Compat";
	}
	else if (gl_profile == SDL_GL_CONTEXT_PROFILE_ES)
	{
		profile = "ES";
	}
	else
	{
		profile = Utils::toString(gl_profile);
	}

	Log(LOG_INFO) << "Using OpenGL " << profile << " " << gl_major << "." << gl_minor;

	SDL_SysWMinfo wmInfo;
	SDL_GetVersion(&wmInfo.version);
	if (!SDL_GetWindowWMInfo(window, &wmInfo))
	{
		Log(LOG_ERROR) << "Failed to get WM info: " << SDL_GetError();
		return false;
	}

#ifdef LINUX
	windowHandle = Utils::toString((unsigned long)wmInfo.info.x11.window);
#elif MAC
	options["macAPI"] = "cocoa";
	options["macAPICocoaUseNSView"] = "true";

	winHandle = Utils::toString(WindowContentViewHandle(wmInfo));
#elif WINDOWS
	windowHandle = Utils::toString((unsigned long)wmInfo.info.win.window);
#endif

	if (windowHandle.empty())
	{
		Log(LOG_ERROR) << "Unable to get window handle";
		return false;
	}

	Ogre::NameValuePairList options;
	options["externalWindowHandle"] = windowHandle;
	renderWindow = root->createRenderWindow("The Warctic " VERSION_STRING, windowWidth, windowHeight, false, &options);
	if (renderWindow == nullptr)
	{
		Log(LOG_ERROR) << "Failed to create RenderWindow";
		return false;
	}

	return true;
}
