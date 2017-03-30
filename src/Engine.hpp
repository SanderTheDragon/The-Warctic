#ifndef ENGINE_HPP_
#define ENGINE_HPP_

#include "utils/Singleton.hpp"
#include "Window.hpp"

class Engine : public Singleton<Engine>
{
private:
	Window* window;
	
	bool running = false;
	
public:
	bool IsRunning() { return running; };
	
	uint Initialize();
	
	void Loop();
	void Stop();
};

#endif
