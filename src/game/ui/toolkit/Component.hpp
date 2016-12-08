#ifndef UI_COMPONENT_HPP_
#define UI_COMPONENT_HPP_

#include "SDL2/SDL.h"

namespace Ui
{
    class Component
    {
    public:
        virtual void Draw(SDL_Renderer** renderer) = 0;
    };
};

#endif
