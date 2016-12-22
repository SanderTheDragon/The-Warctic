#include "game/ui/screens/Screen_Debug.hpp"

#include "Config.hpp"
#include "misc/Logger.hpp"
#include "misc/Errors.hpp"

#include "game/ui/toolkit/Label.hpp"
#include "game/ui/toolkit/Button.hpp"
#include "game/ui/screens/Screen_ResourceList.hpp"

Ui::Screen_Debug::Screen_Debug()
{
    LoadResources();
    
    Ui::Label* topBox = new Ui::Label(0, 0, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "The Warctic - Debug Mode", 24, GetResource("fonts/freemono.ttf"));
    AddComponent(topBox);
    
    Ui::Button* resListButton = new Ui::Button(0, 32, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "List resources", 24, GetResource("fonts/freemono.ttf"), &ButtonResources, &ButtonHovering, &ButtonNotHovering);
    AddComponent(resListButton);
    
    Ui::Button* exitButton = new Ui::Button(0, 456, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "X Exit", 24, GetResource("fonts/freemono.ttf"), &ButtonExit, &ButtonHovering, &ButtonNotHovering);
    AddComponent(exitButton);
}

void Ui::Screen_Debug::LoadResources()
{
    AddResource(RESOURCE_OTHER, "fonts/freemono.ttf");
}

int Ui::Screen_Debug::ButtonResources(Ui::Button* button, int mouseButton, int type)
{
    if (mouseButton == SDL_BUTTON_LEFT && type == SDL_MOUSEBUTTONUP)
    {
        Log(LOG_DEBUG) << "Loading resource list screen" << NEWLINE;
        
        delete screen;
        screen = new Ui::Screen_ResourceList();
    }
    
    return ERR_OK;
}

int Ui::Screen_Debug::ButtonExit(Ui::Button* button, int mouseButton, int type)
{
    if (mouseButton == SDL_BUTTON_LEFT && type == SDL_MOUSEBUTTONUP)
    {
        running = false;
    }
    
    return ERR_OK;
}

int Ui::Screen_Debug::ButtonHovering(Ui::Button* button)
{
    button->GetBackgroundPointer()->SetRed(255);
    button->GetBackgroundPointer()->SetBlue(255);
    button->GetBackgroundPointer()->SetGreen(255);
    
    button->GetForegroundPointer()->SetRed(0);
    button->GetForegroundPointer()->SetBlue(0);
    button->GetForegroundPointer()->SetGreen(0);
    
    return ERR_OK;
}

int Ui::Screen_Debug::ButtonNotHovering(Ui::Button* button)
{
    button->GetBackgroundPointer()->SetRed(0);
    button->GetBackgroundPointer()->SetBlue(0);
    button->GetBackgroundPointer()->SetGreen(0);
    
    button->GetForegroundPointer()->SetRed(255);
    button->GetForegroundPointer()->SetBlue(255);
    button->GetForegroundPointer()->SetGreen(255);
    
    return ERR_OK;
}

Ui::Screen_Debug::~Screen_Debug()
{
    
}
