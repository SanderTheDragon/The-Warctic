#include "Engine.hpp"

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "Config.hpp"
#include "Errors.hpp"
#include "utils/Logger.hpp"

uint Engine::Initialize()
{
	uint error = ERR_OK;
	
	Log(LOG_INFO) << "Initializing" << NEWLINE;
	
	Log(LOG_DEBUG) << "Initializing GLFW" << NEWLINE;
	
	if (!glfwInit())
		return ERR_INIT_GLFW;
	
	Log(LOG_DEBUG) << "Initializing window" << NEWLINE;
	
	window = new Window();
	
	if ((error = window->Initialize()) != ERR_OK)
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
	
	return error;
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
