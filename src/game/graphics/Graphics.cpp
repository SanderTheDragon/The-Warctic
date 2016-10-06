#include "game/graphics/Graphics.hpp"

#include "Config.hpp"
#include "misc/Logger.hpp"

Graphics::Graphics()
{
    window = new Window();
}

Graphics::~Graphics()
{
    window->~Window();
}
