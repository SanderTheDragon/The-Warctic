#ifndef UI_OVERLAY_HPP_
#define UI_OVERLAY_HPP_

#include "ui/toolkit/Box.hpp"
#include "ui/toolkit/Color.hpp"

namespace Ui
{
    class Overlay : public Ui::Box
    {
    public:
        Overlay(int x_, int y_, int w_, int h_, Ui::Color bg, int bSize, Ui::Color bColor) : Box(x_, y_, w_, h_, bg, bSize, bColor) { }
        
        int Draw(SDL_Renderer** renderer)
        {
            Box::Draw(renderer);
            
            return ERR_OK;
        }
        
        int Component() { }
        
        static uint Type() { return UI_OVERLAY; }
        uint Type_() { Ui::Overlay::Type(); }
        
        virtual ~Overlay() { }
    };
};

#endif
 
