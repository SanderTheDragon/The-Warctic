#ifndef UI_OVERLAY_HPP_
#define UI_OVERLAY_HPP_

#include "game/ui/toolkit/Box.hpp"
#include "game/ui/toolkit/Color.hpp"

namespace Ui
{
    class Overlay : public Ui::Box
    {
    protected:
        std::vector<Ui::Component*>* components;
        
    public:
        Overlay(int x_, int y_, int w_, int h_, Ui::Color bg, int bSize, Ui::Color bColor, std::vector<Ui::Component*>* components_) : Box(x_, y_, w_, h_, bg, bSize, bColor), components(components_) { }
        
        int Draw(SDL_Renderer** renderer)
        {
            Box::Draw(renderer);
            
            for (uint i = 0; i < (*components).size(); i++)
            {
                if ((*components).at(i)->GetParent() == this)
                {
                    (*components).at(i)->Draw(renderer);
                }
            }
            
            return ERR_OK;
        }
        
        static uint Type() { return UI_OVERLAY; }
        uint Type_() { Ui::Overlay::Type(); }
        
        virtual ~Overlay() { }
    };
};

#endif
 
