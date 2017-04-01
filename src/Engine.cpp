#include "Engine.hpp"

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "Config.hpp"
#include "Errors.hpp"
#include "utils/Logger.hpp"

uint Engine::Initialize()
{
	uint error;
	
	Log(LOG_INFO) << "Initializing" << NEWLINE;
	
	Log(LOG_DEBUG) << "Initializing GLFW" << NEWLINE;
	
	if (!glfwInit())
		return ERR_INIT_GLFW;
	
	Log(LOG_DEBUG) << "Initializing window" << NEWLINE;
	
	window = new Window();
	
	uint winW = 852;
	
	if (Config::Ref().GetAspectRatio() == ASPECT_16_10)
		winW = 768;
	if (Config::Ref().GetAspectRatio() == ASPECT_4_3)
		winW = 640;
	
	if ((error = window->Initialize(winW, 480)) != ERR_OK)
	{
		Log(LOG_ERROR) << GetErrorMessage(error) << NEWLINE;
		
		return ERR_INIT_WINDOW;
	}
	
	Log(LOG_DEBUG) << "Initializing GLEW" << NEWLINE;
	
	glewExperimental = GL_TRUE;
	
	if (glewInit() != GLEW_OK)
		return ERR_INIT_GLEW;
	
	Log(LOG_INFO) << "Initializing done" << NEWLINE;
	
	running = true;
	
	return ERR_OK;
}

void Engine::Loop()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glfwSwapBuffers(*window->GetWindow());
	
	glfwPollEvents();
	
	if (glfwWindowShouldClose(*window->GetWindow()))
		Stop();
}

void Engine::Stop()
{
	running = false;
	
	delete window;
	
	glfwTerminate();
}
