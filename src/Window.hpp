#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#define ASPECT_16_9  0x0A1609
#define ASPECT_16_10 0x0A1610
#define ASPECT_4_3   0x0A0403

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
