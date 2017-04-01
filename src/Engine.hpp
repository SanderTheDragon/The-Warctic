#ifndef ENGINE_HPP_
#define ENGINE_HPP_

#include "utils/Singleton.hpp"
#include "utils/Structs.hpp"
#include "Window.hpp"

class Engine : public Singleton<Engine>
{
private:
	Window* window;
	
	bool running = false;
	
	Point mouse;
	
public:
	bool IsRunning() { return running; }
	Window** GetWindow() { return &window; }
	
	uint Initialize();
	
	void Loop();
	void Stop();
	
	Point GetMousePos() { return mouse; }
	void SetMousePos(Point p) { mouse = p; }
	void SetMousePos(int x, int y) { mouse.x = x; mouse.y = y; }
};

#endif
