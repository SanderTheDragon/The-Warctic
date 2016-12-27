#ifndef UI_SCREENRESOURCELIST_HPP_
#define UI_SCREENRESOURCELIST_HPP_

#include "game/ui/toolkit/Screen.hpp"
#include "misc/Resource.hpp"

namespace Ui
{
    class Screen_ResourceList : public Ui::Screen
    {
    public:
        Screen_ResourceList();
        
        void LoadResources();
        
        static int ButtonOther(Ui::Button* button, int mouseButton, int type);
        static int ButtonBack(Ui::Button* button, int mouseButton, int type);
        
        static int PreviewResource(Ui::Button* button, int mouseButton, int type);
        static int ClosePreview(Ui::Button* button, int mouseButton, int type);
        
        virtual ~Screen_ResourceList();
    };
};

#endif
