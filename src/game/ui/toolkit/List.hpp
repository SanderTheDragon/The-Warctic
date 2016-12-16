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
        
        Ui::Color foreground;
        
    public:
        List(int x_, int y_, int w_, int h_, Ui::Color bg, Ui::Color fg) : Box(x_, y_, w_, h_, bg), foreground(fg) { }
        
        int Draw(SDL_Renderer** renderer)
        {
            Box::Draw(renderer);
            
            int lY = 0;
            
            SDL_SetRenderDrawColor(*renderer, foreground.GetRed(), foreground.GetBlue(), foreground.GetGreen(), foreground.GetAlpha());
            
            SDL_Rect rect;
            
            rect.x = x + 1;
            rect.y = y + 1;
            rect.w = w - 2;
            rect.h = h - 2;
            
            SDL_RenderFillRect(*renderer, &rect);
            
            SDL_SetRenderDrawColor(*renderer, 0, 0, 0, 255);
            
            for (uint i = 0; i < components.size(); i++)
            {
                components[i]->SetX(GetX() + 2);
                components[i]->SetY(lY + GetY() + 2);
                
                components[i]->Draw(renderer);
                
                SDL_SetRenderDrawColor(*renderer, background.GetRed(), background.GetBlue(), background.GetGreen(), background.GetAlpha());
            
                SDL_Rect rect;
                
                rect.x = GetX() + 1;
                rect.y = components[i]->GetY() + components[i]->GetH() + 1;
                rect.w = GetW() - 2;
                rect.h = 1;
                
                SDL_RenderFillRect(*renderer, &rect);
                
                lY += components[i]->GetH() + 2;
                
                SDL_SetRenderDrawColor(*renderer, 0, 0, 0, 255);
            }
            
            return ERR_OK;
        }
        
        void AddComponent(Ui::Box* component) { components.push_back(component); }
        
        virtual ~List() { }
    };
};

#endif
