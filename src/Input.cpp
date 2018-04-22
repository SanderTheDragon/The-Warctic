#include "Input.hpp"

#include "Engine.hpp"

Input::Input(Engine* engine) :
	engine(engine)
{

}

void Input::loop()
{
	while (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
		case SDL_QUIT:
			engine->stop();
			break;
		}
	}
}
