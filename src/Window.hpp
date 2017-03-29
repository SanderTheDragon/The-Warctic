#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <iostream>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "Config.hpp"

class Window
{
private:
	GLFWwindow* window;
	
public:
	Window();
	
	GLFWwindow** GetWindow() { return &window; }
	
	uint Initialize(ushort width, ushort height);
	
	virtual ~Window();
};

#endif
