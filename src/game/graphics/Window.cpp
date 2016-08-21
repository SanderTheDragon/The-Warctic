#include "game/graphics/Window.hpp"

#include "Config.hpp"
#include "misc/Error.hpp"
#include "misc/Logger.hpp"

Window::Window()
{
    
}

uint Window::Initialize()
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    
    Log(LOG_INFO) << "Creating window" << NEWLINE;
    
    window = glfwCreateWindow(1024, 768, "The Warctic", NULL, NULL);
    if (window == NULL)
    {
        Log(LOG_ERROR) << GetErrorString(ERR_WINDOW_NULL) << NEWLINE;
        return ERR_WINDOW_INITIALIZE;
    }
    
    glfwMakeContextCurrent(window);
    
    Log(LOG_INFO) << "Initializing GLEW" << NEWLINE;
    
    glewExperimental = true;
    if (glewInit() != GLEW_OK)
    {
        Log(LOG_ERROR) << GetErrorString(ERR_WINDOW_GLEW_INITIALIZE) << NEWLINE;
        return ERR_WINDOW_INITIALIZE;
    }
    
    return ERR_OK;
}

void Window::Show()
{
    if (!glfwGetWindowAttrib(window, GLFW_VISIBLE))
        glfwShowWindow(window);
}

Window::~Window()
{
    glfwDestroyWindow(window);
}
