#ifndef UI_SCREENDEBUG_HPP_
#define UI_SCREENDEBUG_HPP_

#include "ui/toolkit/Screen.hpp"

namespace Ui
{
    class Screen_Debug : public Ui::Screen
    {
    public:
        Screen_Debug();
        
        int Initialize();
        int LoadResources();
        
        static int ButtonResources(Ui::Button* button, int mouseButton, int type);
        static int ButtonInfo(Ui::Button* button, int mouseButton, int type);
        static int ButtonExit(Ui::Button* button, int mouseButton, int type);
        
        virtual ~Screen_Debug();
    };
};

#endif
