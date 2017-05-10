#include "Errors.hpp"

#include "utils/String.hpp"

std::string GetErrorMessage(uint code)
{
	switch (code)
	{
	case ERR_OK:
	case ERR_EXIT:
		return "No errors, if you see this, something is probably wrong";
		break;
	case ERR_UNKNOWN:
		return "A mysterious error occured";
		break;
		
	case ERR_INIT:
		return "The game could not initialize";
		break;
	case ERR_INIT_GLFW:
		return "GLFW could not initialize";
		break;
	case ERR_INIT_GLEW:
		return "GLEW could not initialize";
		break;
	case ERR_INIT_WINDOW:
		return "Window could not be created";
		break;
		
	case ERR_FILE_OPEN:
		return "Could not open file";
		break;
	case ERR_FILE_READ:
		return "Could not read from file";
		break;
	case ERR_FILE_WRITE:
		return "Could not write to file";
		break;
		
	case ERR_WINDOW_CREATE:
		return "Failed to create window";
		break;
		
	default:
		return String::Combine(3, "Could not find message for error \'", String::ToHexString(code).c_str(), "\'");
		break;
	}
}
