#ifndef UI_OVERLAY_HPP_
#define UI_OVERLAY_HPP_

#include "game/ui/toolkit/Box.hpp"
#include "game/ui/toolkit/Color.hpp"

namespace Ui
{
    class Overlay : public Ui::Box
    {
    protected:
        std::vector<Ui::Component*> components;
        
    public:
        Overlay(int x_, int y_, int w_, int h_, Ui::Color bg, int bSize, Ui::Color bColor) : Box(x_, y_, w_, h_, bg, bSize, bColor) { }
        
        int Draw(SDL_Renderer** renderer)
        {
            Box::Draw(renderer);
            
            for (uint i = 0; i < components.size(); i++)
            {
                components.at(i)->Draw(renderer);                
            }
            
            return ERR_OK;
        }
        
        static uint Type() { return UI_OVERLAY; }
        uint Type_() { Ui::Overlay::Type(); }
        
        void AddComponent(Ui::Component* component) { components.push_back(component); }
        std::vector<Ui::Component*> GetComponents() { return components; }
        void ClearComponents() { for(uint i = 0; i < components.size(); i++) { delete components.at(i); } components.clear(); components.shrink_to_fit(); }
        
        virtual ~Overlay() { ClearComponents(); }
    };
};

#endif
 
