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
#define UI_OVERLAY      0x01000F
//End define numbers for components

namespace Ui
{
    class Component
    {
    protected:
        int x;
        int y;
        int w;
        int h;
        
        Ui::Component* parent;
        
    public:
        Component(int x_, int y_, int w_, int h_) : x(x_), y(y_), w(w_), h(h_), parent(NULL) { }
        
        virtual int Draw(SDL_Renderer** renderer) = 0;
        
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
        
        static uint Type() { return UI_UNDEFINED; };
        virtual uint Type_() = 0; //Don't change to `uint Type_() { return Ui::Component::Type_(); }`, it won't work
        
        void SetParent(Ui::Component* parent_) { parent = parent_; }
        Ui::Component* GetParent() { return parent; }
    };
};

#endif
