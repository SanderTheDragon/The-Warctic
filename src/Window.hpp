#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "misc/Types.hpp"

class Window
{
private:
	GLFWwindow* window;
	
public:
	Window();
	
	GLFWwindow** GetWindow() { return &window; }
	
	uint Initialize();
	
	virtual ~Window();
};

#endif
