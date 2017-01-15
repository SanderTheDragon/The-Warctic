#ifndef UI_LIST_HPP_
#define UI_LIST_HPP_

#include "ui/toolkit/Component.hpp"
#include "ui/toolkit/Color.hpp"
#include "ui/toolkit/Box.hpp"

namespace Ui
{
    class List : public Ui::Box
    {
    protected:
        std::vector<Ui::Component*>* components;
        
    public:
        List(int x_, int y_, int w_, int h_, Ui::Color bg, int bSize, Ui::Color bColor, std::vector<Ui::Component*>* components_) : Box(x_, y_, w_, h_, bg, bSize, bColor), components(components_) { }
        
        int Draw(SDL_Renderer** renderer)
        {
            Box::Draw(renderer);
            
            int lY = 0;
            
            for (uint i = 0; i < (*components).size(); i++)
            {
                if ((*components).at(i)->GetParent() == this)
                {
                    Ui::Box* box = dynamic_cast<Ui::Box*>((*components).at(i));
                    
                    box->SetY(lY + GetY());
                    
                    box->Draw(renderer);
                    
                    lY += box->GetH() + box->GetBorderSize();
                }
            }
            
            return ERR_OK;
        }
        
        static uint Type() { return UI_LIST; }
        uint Type_() { Ui::List::Type(); }
        
        virtual ~List() { }
    };
};

#endif
