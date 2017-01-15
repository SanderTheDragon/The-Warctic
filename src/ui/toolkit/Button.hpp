#ifndef UI_BUTTON_HPP_
#define UI_BUTTON_HPP_

#include <string>

#include "ui/toolkit/Label.hpp"

namespace Ui
{
    class Button : public Ui::Label
    {
    protected:
        int (* callback)(Ui::Button*, int, int);
        int (* hovering)(Ui::Button*);
        int (* notHovering)(Ui::Button*);
        bool enabled;
        
    public:
        Button(int x_, int y_, int w_, int h_, Ui::Color bg, Ui::Color fg, std::string msg, uint size, Resource* font_, int (* callbackFunction)(Ui::Button*, int, int)) : Label(x_, y_, w_, h_, bg, fg, msg, size, font_), callback(callbackFunction), hovering(DefaultHovering), notHovering(DefaultNotHovering) { }
        Button(int x_, int y_, int w_, int h_, Ui::Color bg, Ui::Color fg, std::string msg, uint size, Resource* font_, int (* callbackFunction)(Ui::Button*, int, int), int (* hoveringFunction)(Ui::Button*), int (* notHoveringFunction)(Ui::Button*)) : Label(x_, y_, w_, h_, bg, fg, msg, size, font_), callback(callbackFunction), hovering(hoveringFunction), notHovering(notHoveringFunction) { }
        Button(int x_, int y_, int w_, int h_, Ui::Color bg, int bSize, Ui::Color bColor, Ui::Color fg, std::string msg, uint size, Resource* font_, int (* callbackFunction)(Ui::Button*, int, int)) : Label(x_, y_, w_, h_, bg, bSize, bColor, fg, msg, size, font_), callback(callbackFunction), hovering(DefaultHovering), notHovering(DefaultNotHovering) { }
        Button(int x_, int y_, int w_, int h_, Ui::Color bg, int bSize, Ui::Color bColor, Ui::Color fg, std::string msg, uint size, Resource* font_, int (* callbackFunction)(Ui::Button*, int, int), int (* hoveringFunction)(Ui::Button*), int (* notHoveringFunction)(Ui::Button*)) : Label(x_, y_, w_, h_, bg, bSize, bColor, fg, msg, size, font_), callback(callbackFunction), hovering(hoveringFunction), notHovering(notHoveringFunction) { }
        
        int Draw(SDL_Renderer** renderer)
        {
            return Label::Draw(renderer);
        }
        
        static uint Type() { return UI_BUTTON; }
        uint Type_() { Ui::Button::Type(); }
        
        //Get/set callback
        void SetCallback(int (* callbackFunction)(Ui::Button*, int, int)) { callback = callbackFunction; }
        int (* GetCallback())(Ui::Button*, int, int) { return callback; }
        
        //Get/set hovering
        void SetHovering(int (* hoveringFunction)(Ui::Button*)) { hovering = hoveringFunction; }
        int (* GetHovering())(Ui::Button*) { return hovering; }
        
        //Get/set not hovering
        void SetNotHovering(int (* notHoveringFunction)(Ui::Button*)) { notHovering = notHoveringFunction; }
        int (* GetNotHovering())(Ui::Button*) { return notHovering; }
        
        //Get/set enabled
        void SetEnabled(bool enable) { enabled = enable; }
        bool GetEnabled() { return enabled; }
        void Enable() { enabled = true; }
        void Disable() { enabled = false; }
        
        virtual ~Button() { }
 
 
 
        static int DefaultHovering(Ui::Button* button)
        {
            button->GetBackgroundPointer()->SetRed(255);
            button->GetBackgroundPointer()->SetBlue(255);
            button->GetBackgroundPointer()->SetGreen(255);
            
            button->GetForegroundPointer()->SetRed(0);
            button->GetForegroundPointer()->SetBlue(0);
            button->GetForegroundPointer()->SetGreen(0);
            
            return ERR_OK;
        }
        
        static int DefaultNotHovering(Ui::Button* button)
        {
            button->GetBackgroundPointer()->SetRed(0);
            button->GetBackgroundPointer()->SetBlue(0);
            button->GetBackgroundPointer()->SetGreen(0);
            
            button->GetForegroundPointer()->SetRed(255);
            button->GetForegroundPointer()->SetBlue(255);
            button->GetForegroundPointer()->SetGreen(255);
            
            return ERR_OK;
        }
    };
};

#endif
