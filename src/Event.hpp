#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <string>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

class Event
{
public:
	static std::string ButtonName(uint button);
	static std::string KeyName(uint key);
	
	static void HandleKeys(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void HandleKeyUp(GLFWwindow* window, int key, int scancode, int mods);
	static void HandleKeyDown(GLFWwindow* window, int key, int scancode, int mods);
	
	static void HandleMouseButton(GLFWwindow* window, int button, int action, int mods);
	static void HandleMouseMove(GLFWwindow* window, double x, double y);
	static void HandleMouseWheel(GLFWwindow* window, double xOff, double yOff);
};

#endif
