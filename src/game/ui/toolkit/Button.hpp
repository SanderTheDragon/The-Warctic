#ifndef UI_BUTTON_HPP_
#define UI_BUTTON_HPP_

#include <string>

#include "game/ui/toolkit/Label.hpp"

namespace Ui
{
    class Screen;
    
    class Button : public Ui::Label
    {
    protected:
        int (* callback)();
        
    public:
        Button(int x_, int y_, int w_, int h_, Ui::Color bg, Ui::Color fg, std::string msg, uint size, int (* callbackFunction)()) : Label(x_, y_, w_, h_, bg, fg, msg, size), callback(callbackFunction) { }
        
        void Draw(SDL_Renderer** renderer)
        {
            Label::Draw(renderer);
        }
        
        //Get/set callback
        void SetCallback(int (* callbackFunction)()) { callback = callbackFunction; }
        int (* GetCallback())() { return callback; }
        
        virtual ~Button() { }
    };
};

#endif
