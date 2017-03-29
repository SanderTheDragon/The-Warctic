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
		
	default:
		return String::Combine(3, "Could not find message for error \'", String::ToHexString(code).c_str(), "\'");
		break;
	}
}
