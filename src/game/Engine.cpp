#include "game/Engine.hpp" 

#include "Config.hpp"
#include "misc/Error.hpp"
#include "misc/Logger.hpp"

Engine::Engine()
{
    glfwSetErrorCallback(GLFW_Error);
    
    graphics = new Graphics();
}

uint Engine::Initialize()
{
    int error = ERR_OK;
    
    Log(LOG_INFO) << "Initializing GLFW" << NEWLINE;
    
    if (!glfwInit())
    {
        Log(LOG_ERROR) << GetErrorString(ERR_ENGINE_GLFW_INITIALIZE) << NEWLINE;
        return ERR_ENGINE_INITIALIZE;
    }
    
    Log(LOG_INFO) << "Initializing graphics" << NEWLINE;
    
    error = graphics->Initialize();
    if (error != ERR_OK)
    {
        Log(LOG_ERROR) << GetErrorString(error) << NEWLINE;
        return ERR_ENGINE_INITIALIZE;
    }
    
    graphics->GetWindow()->Show();
    
    running = true;
    
    return ERR_OK;
}

void Engine::Loop()
{
    glfwSwapBuffers(graphics->GetWindow()->GetGLFWWindow());
    glfwPollEvents();
    
    if (glfwWindowShouldClose(graphics->GetWindow()->GetGLFWWindow()) > 0)
        running = false;
}

void Engine::GLFW_Error(int code, const char* message)
{
#ifdef DEBUG
    Log(LOG_DEBUG_ERROR) << message << NEWLINE;
#endif
}

Engine::~Engine()
{
    graphics->~Graphics();
}
