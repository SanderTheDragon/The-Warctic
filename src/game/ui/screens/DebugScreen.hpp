#ifndef UI_DEBUGSCREEN_HPP_
#define UI_DEBUGSCREEN_HPP_

#include "game/ui/toolkit/Screen.hpp"

namespace Ui
{
    class DebugScreen : public Ui::Screen
    {
    public:
        DebugScreen();
        
        static int ButtonResources();
        
        virtual ~DebugScreen();
    };
};

#endif
