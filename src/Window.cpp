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
	
	Log(LOG_DEBUG) << "Creating window" << NEWLINE;
	
	window = glfwCreateWindow(width, height, "The Warctic", NULL, NULL);
	
	if (window == NULL)
		return ERR_INIT_WINDOW;
	
	Log(LOG_TRACE) << "Configuring GLFW/GL" << NEWLINE;
	
	if (Config::Ref().GetAspectRatio() == ASPECT_16_9)
	{
		glfwSetWindowSizeLimits(window, 852, 480, GLFW_DONT_CARE, GLFW_DONT_CARE);
		glfwSetWindowAspectRatio(window, 16, 9);
	}
	else if (Config::Ref().GetAspectRatio() == ASPECT_16_10)
	{
		glfwSetWindowSizeLimits(window, 768, 480, GLFW_DONT_CARE, GLFW_DONT_CARE);
		glfwSetWindowAspectRatio(window, 16, 10);
	}
	else if (Config::Ref().GetAspectRatio() == ASPECT_4_3) //Almost everyone uses 16:9 or 16:10 but 4:3 users probably exist
	{
		glfwSetWindowSizeLimits(window, 640, 480, GLFW_DONT_CARE, GLFW_DONT_CARE);
		glfwSetWindowAspectRatio(window, 4, 3);
	}
	
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	
	return ERR_OK;
}

Window::~Window()
{
	glfwDestroyWindow(window);
}
