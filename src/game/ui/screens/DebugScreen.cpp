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
    
    Ui::Button* resListButton = new Ui::Button(0, 32, -1, -1, Ui::Color(255, 255, 255, 255), Ui::Color(0, 0, 0, 255), "List resources", 24, &ButtonResources);
    AddComponent(resListButton);
}

int Ui::DebugScreen::ButtonResources()
{
    Log(LOG_WARNING) << "Button is not implemented yet" << NEWLINE;
    
    return ERR_OK;
}

Ui::DebugScreen::~DebugScreen()
{
    
}
