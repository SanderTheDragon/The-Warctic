#ifndef UI_SCREENINFO_HPP_
#define UI_SCREENINFO_HPP_

#include "ui/toolkit/Screen.hpp"

namespace Ui
{
    class Screen_Info : public Ui::Screen
    {
    public:
        Screen_Info();
        
        int Initialize();
        int LoadResources();
        
        static int ShowCredits(Ui::Button* button, int mouseButton, int type);
        static int ShowLicense(Ui::Button* button, int mouseButton, int type);
        
        static int ButtonBack(Ui::Button* button, int mouseButton, int type);
        
        virtual ~Screen_Info();
    };
};

#endif
