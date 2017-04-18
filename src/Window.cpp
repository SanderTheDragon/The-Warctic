#include "Window.hpp"

#include "Config.hpp"
#include "Errors.hpp"
#include "utils/Logger.hpp"

#include "utils/Math.hpp"

Window::Window()
{
	
}

uint Window::Initialize()
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
	
	window = glfwCreateWindow(Math::CalculateWinWidth(Config::Ref().GetAspectRatio(), Config::Ref().GetStartResolution()), Config::Ref().GetStartResolution(), "The Warctic", (Config::Ref().GetFullscreen()) ? glfwGetPrimaryMonitor() : NULL, NULL);
	
	if (window == NULL)
		return ERR_INIT_WINDOW;
	
	Log(LOG_TRACE) << "Configuring GLFW/GL" << NEWLINE;
	
	if (Config::Ref().GetAspectRatio() == ASPECT_16_9)
	{
		glfwSetWindowSizeLimits(window, Math::CalculateMinWinWidth(ASPECT_16_9), MIN_WIN_HEIGHT, GLFW_DONT_CARE, GLFW_DONT_CARE);
		glfwSetWindowAspectRatio(window, 16, 9);
	}
	else if (Config::Ref().GetAspectRatio() == ASPECT_16_10)
	{
		glfwSetWindowSizeLimits(window, Math::CalculateMinWinWidth(ASPECT_16_10), MIN_WIN_HEIGHT, GLFW_DONT_CARE, GLFW_DONT_CARE);
		glfwSetWindowAspectRatio(window, 16, 10);
	}
	else if (Config::Ref().GetAspectRatio() == ASPECT_4_3) //Almost everyone uses 16:9 or 16:10 but 4:3 users probably exist
	{
		glfwSetWindowSizeLimits(window, Math::CalculateMinWinWidth(ASPECT_4_3), MIN_WIN_HEIGHT, GLFW_DONT_CARE, GLFW_DONT_CARE);
		glfwSetWindowAspectRatio(window, 4, 3);
	}
	
	//Set GLFW stuff
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	
	//Set GL stuff
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	
	return ERR_OK;
}

Window::~Window()
{
	glfwDestroyWindow(window);
}
