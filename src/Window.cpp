#include "Window.hpp"

#include "Errors.hpp"
#include "utils/Logger.hpp"

Window::Window()
{
	
}

uint Window::Initialize(ushort width, ushort height)
{
	Log(LOG_TRACE) << "Adding window hints" << NEWLINE;
	
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	
#if defined(MAC) //It's not Windows this time
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	
	Log(LOG_DEBUG) << "Creating window" << NEWLINE;
	
	window = glfwCreateWindow(width, height, "The Warctic", NULL, NULL);
	
	if (window == NULL)
		return ERR_INIT_WINDOW;
	
	Log(LOG_TRACE) << "Configuring GLFW/GL" << NEWLINE;
	
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	
	return ERR_OK;
}

Window::~Window()
{
	glfwDestroyWindow(window);
}
