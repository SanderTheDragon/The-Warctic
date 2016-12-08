#include "game/ui/screens/DebugScreen.hpp"

#include "Config.hpp"
#include "misc/Logger.hpp"
#include "misc/Errors.hpp"

#include "game/ui/toolkit/Label.hpp"
#include "game/ui/toolkit/Button.hpp"

Ui::DebugScreen::DebugScreen()
{
    Ui::Label* topBox = new Ui::Label(0, 0, -1, -1, Ui::Color(0, 0, 0, 0), Ui::Color(255, 255, 255, 255), "Debug Mode", 24);
    AddComponent(topBox);
    
    Ui::Button* resListButton = new Ui::Button(0, 32, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "List resources", 24, &ButtonResources, &ButtonResourcesHovering, &ButtonResourcesNotHovering);
    AddComponent(resListButton);
}

int Ui::DebugScreen::ButtonResources(Ui::Button* button, int mouseButton, int type)
{
    if (mouseButton == SDL_BUTTON_LEFT && type == SDL_MOUSEBUTTONUP)
    {
        Log(LOG_WARNING) << "Button is not implemented yet" << NEWLINE;
    }
    
    return ERR_OK;
}

int Ui::DebugScreen::ButtonResourcesHovering(Ui::Button* button)
{
    button->GetBackgroundPointer()->ShiftRed(1);
    button->GetBackgroundPointer()->ShiftBlue(1);
    button->GetBackgroundPointer()->ShiftGreen(1);
    
    button->GetForegroundPointer()->ShiftRed(-1);
    button->GetForegroundPointer()->ShiftBlue(-1);
    button->GetForegroundPointer()->ShiftGreen(-1);
    
    return ERR_OK;
}

int Ui::DebugScreen::ButtonResourcesNotHovering(Ui::Button* button)
{
    button->GetBackgroundPointer()->ShiftRed(-1);
    button->GetBackgroundPointer()->ShiftBlue(-1);
    button->GetBackgroundPointer()->ShiftGreen(-1);
    
    button->GetForegroundPointer()->ShiftRed(1);
    button->GetForegroundPointer()->ShiftBlue(1);
    button->GetForegroundPointer()->ShiftGreen(1);
    
    return ERR_OK;
}

Ui::DebugScreen::~DebugScreen()
{
    
}
