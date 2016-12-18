#include "game/ui/screens/Screen_ResourceList.hpp"

#include "Config.hpp"
#include "misc/Logger.hpp"
#include "misc/Errors.hpp"

#include "game/ui/toolkit/Label.hpp"
#include "game/ui/toolkit/Button.hpp"
#include "game/ui/toolkit/List.hpp"
#include "game/ui/screens/Screen_Debug.hpp"
#include "misc/utils/String.hpp"

Ui::Screen_ResourceList::Screen_ResourceList()
{
    LoadResources();
    
    Ui::Label* topBox = new Ui::Label(0, 0, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "Debug Mode - Resource list", 24, GetResource("fonts/freemono.ttf"));
    AddComponent(topBox);
    
    Ui::Button* otherButton = new Ui::Button(0, 32, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "other.zip", 24, GetResource("fonts/freemono.ttf"), &ButtonOther, &ButtonHovering, &ButtonNotHovering);
    AddComponent(otherButton);
    
    Ui::List* files = new Ui::List(168, 40, 536, 424, Ui::Color(255, 255, 255, 255), Ui::Color(0, 0, 0, 255));
    AddComponent(files);
    
    Ui::Button* backButton = new Ui::Button(0, 456, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "< Back", 24, GetResource("fonts/freemono.ttf"), &ButtonBack, &ButtonHovering, &ButtonNotHovering);
    AddComponent(backButton);
}

void Ui::Screen_ResourceList::LoadResources()
{
    AddResource(RESOURCE_OTHER, "fonts/freemono.ttf");
}

int Ui::Screen_ResourceList::ButtonOther(Ui::Button* button, int mouseButton, int type)
{
    if (mouseButton == SDL_BUTTON_LEFT && type == SDL_MOUSEBUTTONUP)
    {
        Ui::Screen_ResourceList* scr = dynamic_cast<Ui::Screen_ResourceList*>(screen);
        
        Ui::List* files = scr->FindComponent<Ui::List>();
        
        files->ClearComponents();
        
        std::vector<std::string> items = Resources::ReadArchive(Utils::String::Combine(2, std::string(DIR_RESOURCE), button->GetText()));
        
        for (uint i = 0; i < items.size(); i++)
        {
            Ui::Label* file = new Ui::Label(-1, -1, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), Utils::String::FileToPath(items.at(i)), 14, scr->GetResource("fonts/freemono.ttf"));
            files->AddComponent(file);
        }
    }
    
    return ERR_OK;
}

int Ui::Screen_ResourceList::ButtonBack(Ui::Button* button, int mouseButton, int type)
{
    if (mouseButton == SDL_BUTTON_LEFT && type == SDL_MOUSEBUTTONUP)
    {
        Log(LOG_DEBUG) << "Loading debug screen" << NEWLINE;
        
        delete screen;
        screen = new Ui::Screen_Debug();
    }
    
    return ERR_OK;
}

int Ui::Screen_ResourceList::ButtonHovering(Ui::Button* button)
{
    button->GetBackgroundPointer()->SetRed(255);
    button->GetBackgroundPointer()->SetBlue(255);
    button->GetBackgroundPointer()->SetGreen(255);
    
    button->GetForegroundPointer()->SetRed(0);
    button->GetForegroundPointer()->SetBlue(0);
    button->GetForegroundPointer()->SetGreen(0);
    
    return ERR_OK;
}

int Ui::Screen_ResourceList::ButtonNotHovering(Ui::Button* button)
{
    button->GetBackgroundPointer()->SetRed(0);
    button->GetBackgroundPointer()->SetBlue(0);
    button->GetBackgroundPointer()->SetGreen(0);
    
    button->GetForegroundPointer()->SetRed(255);
    button->GetForegroundPointer()->SetBlue(255);
    button->GetForegroundPointer()->SetGreen(255);
    
    return ERR_OK;
}

Ui::Screen_ResourceList::~Screen_ResourceList()
{
    
}
