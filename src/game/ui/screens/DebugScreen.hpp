#ifndef UI_DEBUGSCREEN_HPP_
#define UI_DEBUGSCREEN_HPP_

#include "game/ui/toolkit/Screen.hpp"

namespace Ui
{
    class DebugScreen : public Ui::Screen
    {
    public:
        DebugScreen();
        
        static int ButtonResources(Ui::Button* button, int mouseButton, int type);
        static int ButtonResourcesHovering(Ui::Button* button);
        static int ButtonResourcesNotHovering(Ui::Button* button);
        
        virtual ~DebugScreen();
    };
};

#endif
