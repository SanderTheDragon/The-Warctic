#ifndef UI_LIST_HPP_
#define UI_LIST_HPP_

#include "game/ui/toolkit/Box.hpp"
#include "game/ui/toolkit/Color.hpp"

namespace Ui
{
    class List : public Ui::Box
    {
    protected:
        std::vector<Ui::Box*> components;
        
    public:
        List(int x_, int y_, int w_, int h_, Ui::Color bg, int bSize, Ui::Color bColor) : Box(x_, y_, w_, h_, bg, bSize, bColor) { }
        
        int Draw(SDL_Renderer** renderer)
        {
            Box::Draw(renderer);
            
            int lY = 0;
            
            for (uint i = 0; i < components.size(); i++)
            {
                components.at(i)->SetY(lY + GetY());
                
                components.at(i)->Draw(renderer);
                
                lY += components.at(i)->GetH() + 2 * components.at(i)->GetBorderSize();
            }
            
            return ERR_OK;
        }
        
        static uint Type() { return UI_LIST; }
        uint Type_() { Ui::List::Type(); }
        
        void AddComponent(Ui::Box* component) { components.push_back(component); }
        std::vector<Ui::Box*> GetComponents() { return components; }
        void ClearComponents() { for(uint i = 0; i < components.size(); i++) { delete components.at(i); } components.clear(); components.shrink_to_fit(); }
        
        virtual ~List() { ClearComponents(); }
    };
};

#endif
