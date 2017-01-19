#include "ui/screens/Screen_Debug.hpp"

#include "Config.hpp"
#include "misc/Logger.hpp"
#include "misc/Errors.hpp"

#include "ui/toolkit/Label.hpp"
#include "ui/toolkit/Button.hpp"
#include "ui/toolkit/ErrorBox.hpp"
#include "ui/screens/Screen_ResourceList.hpp"
#include "ui/screens/Screen_Info.hpp"

Ui::Screen_Debug::Screen_Debug()
{
    
}

int Ui::Screen_Debug::Initialize()
{
    if (LoadResources() != ERR_OK)
    {
        Log(LOG_ERROR) << GetErrorMessage(ERR_RESOURCE_LOAD) << NEWLINE;
        
        return ERR_RESOURCE_LOAD;
    }
    
    Ui::Button* infoButton = new Ui::Button(0, 0, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "The Warctic", 24, GetResource("fonts/freemono.ttf"), &ButtonInfo);
    infoButton->Enable();
    infoButton->Resolve();
    AddComponent(infoButton);
    
    Ui::Label* topBox = new Ui::Label(infoButton->GetW(), 0, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), " - Debug Mode", 24, GetResource("fonts/freemono.ttf"));
    AddComponent(topBox);
    
    Ui::Button* resListButton = new Ui::Button(0, 32, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "List resources", 24, GetResource("fonts/freemono.ttf"), &ButtonResources);
    resListButton->Enable();
    AddComponent(resListButton);
    
    Ui::Button* exitButton = new Ui::Button(0, 456, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "X Exit", 24, GetResource("fonts/freemono.ttf"), &ButtonExit);
    exitButton->Enable();
    AddComponent(exitButton);
    
    return ERR_OK;
}

int Ui::Screen_Debug::LoadResources()
{
    uint error = ERR_OK;
    
    error |= AddResource(RESOURCE_OTHER, "fonts/freemono.ttf");
    
    if (error != ERR_OK)
        return ERR_RESOURCE_LOAD;
    
    return ERR_OK;
}

int Ui::Screen_Debug::ButtonResources(Ui::Button* button, int mouseButton, int type)
{
    if (mouseButton == SDL_BUTTON_LEFT && type == SDL_MOUSEBUTTONUP)
    {
        Log(LOG_DEBUG) << "Loading resource list screen" << NEWLINE;
        
        Ui::Screen* tScreen = new Ui::Screen_ResourceList();
        
        int error = tScreen->Initialize();
        
        if (error != ERR_OK)
        {
            Log(LOG_ERROR) << GetErrorMessage(error) << NEWLINE;
            
            Ui::ErrorBox* errorBox = new Ui::ErrorBox(Utils::String::Combine(2, "Could not load screen ResourceList\n\n", GetErrorMessage(error).c_str()));
            
            ::screen->AddComponent(errorBox);
            
            errorBox->Component();
            
            return ERR_UNKNOWN;
        }
        else
        {
            delete ::screen;
            ::screen = tScreen;
        }
    }
    
    return ERR_OK;
}

int Ui::Screen_Debug::ButtonInfo(Ui::Button* button, int mouseButton, int type)
{
    if (mouseButton == SDL_BUTTON_LEFT && type == SDL_MOUSEBUTTONUP)
    {
        Log(LOG_DEBUG) << "Loading info screen" << NEWLINE;
        
        Ui::Screen* tScreen = new Ui::Screen_Info();
        
        int error = tScreen->Initialize();
        
        if (error != ERR_OK)
        {
            Log(LOG_ERROR) << GetErrorMessage(error) << NEWLINE;
            
            Ui::ErrorBox* errorBox = new Ui::ErrorBox(Utils::String::Combine(2, "Could not load screen Info\n\n", GetErrorMessage(error).c_str()));
            
            ::screen->AddComponent(errorBox);
            
            errorBox->Component();
            
            return ERR_UNKNOWN;
        }
        else
        {
            delete ::screen;
            ::screen = tScreen;
        }
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

Ui::Screen_Debug::~Screen_Debug()
{
    
}
