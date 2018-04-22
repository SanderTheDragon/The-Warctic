#ifndef INPUT_HPP_
#define INPUT_HPP_

#include <SDL2/SDL.h>

class Engine;

class Input
{
public:
	Input(Engine* engine);

	void loop();

private:
	SDL_Event e;

	Engine* engine;
};

#endif
