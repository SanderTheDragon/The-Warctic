#include "misc/Error.hpp"

const char* GetErrorString(uint err)
{
    switch (err)
    {
    case ERR_ENGINE_UNKNOWN:
        return "Engine error";
        break;
    case ERR_ENGINE_INITIALIZE:
        return "Engine could not initialize";
        break;
    case ERR_ENGINE_GLFW_INITIALIZE:
        return "GLFW could not initialize";
        break;
        
    case ERR_GRAPHICS_UNKNOW:
        return "Graphics error";
        break;
    case ERR_GRAPHICS_INITIALIZE:
        return "Graphics could not initialize";
        break;
        
    case ERR_WINDOW_UNKNOWN:
        return "Window error";
        break;
    case ERR_WINDOW_INITIALIZE:
        return "Window could not initialize";
        break;
    case ERR_WINDOW_NULL:
        return "Window is null";
        break;
    case ERR_WINDOW_GLEW_INITIALIZE:
        return "GLEW could not initialize";
        break;
        
    case ERR_FILE_UNKNOWN:
        return "File error";
        break;
    case ERR_FILE_NOT_OPEN:
        return "File could not open";
        break;
        
    case ERR_AUDIO_UNKNOWN:
        return "Audio error";
        break;
    case ERR_AUDIO_INITIALIZE:
        return "Audio could not initialize";
        break;
    case ERR_AUDIO_DEVICE_NULL:
        return "Audio device is null";
        break;
    case ERR_AUDIO_CONTEXT:
        return "Audio context error";
        break;
    }
} 
