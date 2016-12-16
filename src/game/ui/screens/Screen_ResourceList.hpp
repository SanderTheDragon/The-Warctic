#ifndef UI_SCREENRESOURCELIST_HPP_
#define UI_SCREENRESOURCELIST_HPP_

#include "game/ui/toolkit/Screen.hpp"
#include "game/ui/toolkit/List.hpp"
#include "misc/Resources.hpp"

namespace Ui
{
    class Screen_ResourceList : public Ui::Screen
    {
    private:
        Ui::List* files;
        
    public:
        Screen_ResourceList();
        
        void LoadResources();
        
        static int ButtonOther(Ui::Button* button, int mouseButton, int type);
        static int ButtonBack(Ui::Button* button, int mouseButton, int type);
        static int ButtonHovering(Ui::Button* button);
        static int ButtonNotHovering(Ui::Button* button);
        
        virtual ~Screen_ResourceList();
    };
};

#endif
