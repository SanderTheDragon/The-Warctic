#ifndef UI_BOX_HPP_
#define UI_BOX_HPP_

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
        int borderSize;
        
        Ui::Color background;
        Ui::Color border;
        
    public:
        Box(int x_, int y_, int w_, int h_, Ui::Color col) : x(x_), y(y_), w(w_), h(h_), background(col), borderSize(0), border(0, 0, 0, 0) { }
        Box(int x_, int y_, int w_, int h_, Ui::Color col, int bSize, Ui::Color bColor) : x(x_), y(y_), w(w_), h(h_), background(col), borderSize(bSize), border(bColor) { }
        
        int Draw(SDL_Renderer** renderer)
        {
            SDL_SetRenderDrawColor(*renderer, background.GetRed(), background.GetGreen(), background.GetBlue(), background.GetAlpha());
            
            SDL_Rect rect;
            
            rect.x = x;
            rect.y = y;
            rect.w = w;
            rect.h = h;
            
            if (borderSize <= 0)
            {
                SDL_RenderFillRect(*renderer, &rect);
            }
            else
            {
                SDL_SetRenderDrawColor(*renderer, border.GetRed(), border.GetGreen(), border.GetBlue(), border.GetAlpha());
                
                SDL_RenderFillRect(*renderer, &rect);
                
                rect.x += borderSize;
                rect.y += borderSize;
                rect.w -= 2 * borderSize;
                rect.h -= 2 * borderSize;
                
                SDL_SetRenderDrawColor(*renderer, background.GetRed(), background.GetGreen(), background.GetBlue(), background.GetAlpha());
                
                SDL_RenderFillRect(*renderer, &rect);
            }
            
            SDL_SetRenderDrawColor(*renderer, 0, 0, 0, 255);
            
            return ERR_OK;
        }
        
        static uint Type() { return UI_BOX; }
        uint Type_() { Ui::Box::Type(); }
        
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

        //Call this if your arguments were x1, y1, x2, y2 instead of x, y, w, h
        void XYToWH() { w = w - x; h = h - y; }
        
        //Get position/size
        int GetX() { return x; }
        int GetY() { return y; }
        int GetW() { return w; }
        int GetH() { return h; }
        
        //Get/set backgroundcolor
        void SetBackground(Ui::Color color) { background = color; }
        void SetBackground(ushort r, ushort g, ushort b, ushort a) { background.SetColor(r, g, b, a); }
        Ui::Color GetBackground() { return background; }
        Ui::Color* GetBackgroundPointer() { return &background; }
        
        //Get/Set border
        void SetBorderSize(int bSize) { borderSize = bSize; }
        int GetBorderSize() { return borderSize; }
        void ShiftBorderSize(int i) { borderSize += i; }
        
        //Get/set bordercolor
        void SetBorderColor(Ui::Color color) { border = color; }
        void SetBorderColor(ushort r, ushort g, ushort b, ushort a) { border.SetColor(r, g, b, a); }
        Ui::Color GetBorder() { return border; }
        Ui::Color* GetBorderPointer() { return &border; }
        
        virtual ~Box() { }
    };
};

#endif
