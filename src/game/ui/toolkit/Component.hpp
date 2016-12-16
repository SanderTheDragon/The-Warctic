#ifndef UI_COMPONENT_HPP_
#define UI_COMPONENT_HPP_

#include "SDL2/SDL.h"

#include "misc/Errors.hpp"

namespace Ui
{
    class Component
    {
    public:
        virtual int Draw(SDL_Renderer** renderer) = 0;
    };
};

#endif
