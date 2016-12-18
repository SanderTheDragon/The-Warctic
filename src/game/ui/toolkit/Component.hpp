#ifndef UI_COMPONENT_HPP_
#define UI_COMPONENT_HPP_

#include "SDL2/SDL.h"

#include "misc/Errors.hpp"

//Define numbers for components
#define UI_UNDEFINED    0x010000
#define UI_BOX          0x010001
#define UI_LABEL        0x010002
#define UI_BUTTON       0x010004
#define UI_LIST         0x010008
//End define numbers for components

namespace Ui
{
    class Component
    {
    public:
        virtual int Draw(SDL_Renderer** renderer) = 0;
        
        static uint Type() { return UI_UNDEFINED; };
        virtual uint Type_() = 0;
    };
};

#endif
