#ifndef UI_BOX_HPP_
#define UI_BOX_HPP_

#include "misc/Errors.hpp"

#include "game/ui/toolkit/Component.hpp"
#include "game/ui/toolkit/Color.hpp"

namespace Ui
{
    class Box : public Ui::Component
    {
    protected:
        int x;
        int y;
        int w;
        int h;
        
        Ui::Color background;
        
    public:
        Box(int x_, int y_, int w_, int h_, Ui::Color col) : x(x_), y(y_), w(w_), h(h_), background(col) { }
        
        int Draw(SDL_Renderer** renderer)
        {
            SDL_SetRenderDrawColor(*renderer, background.GetRed(), background.GetGreen(), background.GetBlue(), 255);
            
            SDL_Rect rect;
            
            rect.x = x;
            rect.y = y;
            rect.w = w;
            rect.h = h;
            
            SDL_RenderFillRect(*renderer, &rect);
            
            SDL_SetRenderDrawColor(*renderer, 0, 0, 0, 255);
            
            return ERR_OK;
        }
        
        //Shift position/size
        void ShiftX(int i) { x += i; }
        void ShiftY(int i) { y += i; }
        void ShiftW(int i) { w += i; }
        void ShiftH(int i) { h += i; }
        
        //Set position/size
        void SetPosition(int x_, int y_) { x = x_; y = y_; } 
        void SetX(int x_) { x = x_; } 
        void SetY(int y_) { y = y_; } 
        void SetSize(int w_, int h_) { w = w_; h = h_; } 
        void SetW(int w_) { w = w_; } 
        void SetH(int h_) { h = h_; }
        
        //Get position/size
        int GetX() { return x; }
        int GetY() { return y; }
        int GetW() { return w; }
        int GetH() { return h; }
        
        //Get/set color
        void SetBackground(Ui::Color color) { background = color; }
        void SetBackground(ushort r, ushort g, ushort b, ushort a) { background.SetColor(r, g, b, a); }
        Ui::Color GetBackground() { return background; }
        Ui::Color* GetBackgroundPointer() { return &background; }
        
        virtual ~Box() { }
    };
};

#endif
