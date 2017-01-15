#include "ui/screens/Screen_Info.hpp"

#include "Config.hpp"
#include "misc/Logger.hpp"
#include "misc/Errors.hpp"

#include "ui/toolkit/Label.hpp"
#include "ui/toolkit/Button.hpp"
#include "ui/toolkit/ErrorBox.hpp"
#include "ui/toolkit/MessageBox.hpp"
#include "ui/screens/Screen_Debug.hpp"
#include "misc/utils/String.hpp"
#include "misc/Credits.hpp"
#include "misc/License.hpp"

Ui::Screen_Info::Screen_Info()
{
    
}

int Ui::Screen_Info::Initialize()
{
    if (LoadResources() != ERR_OK)
    {
        Log(LOG_ERROR) << GetErrorMessage(ERR_RESOURCE_LOAD) << NEWLINE;
        
        return ERR_RESOURCE_LOAD;
    }
    
    Ui::Label* topBox = new Ui::Label(0, 0, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "The Warctic - Debug Mode - Info", 24, GetResource("fonts/freemono.ttf"));
    AddComponent(topBox);
    
    Ui::Button* credits = new Ui::Button(0, 32, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "Credits", 24, GetResource("fonts/freemono.ttf"), &ShowCredits);
    credits->Enable();
    AddComponent(credits);
    
    Ui::Button* license = new Ui::Button(0, 64, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "License", 24, GetResource("fonts/freemono.ttf"), &ShowLicense);
    license->Enable();
    AddComponent(license);
    
    Ui::Button* backButton = new Ui::Button(0, 456, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "< Back", 24, GetResource("fonts/freemono.ttf"), &ButtonBack);
    backButton->Enable();
    AddComponent(backButton);
    
    return ERR_OK;
}

int Ui::Screen_Info::LoadResources()
{
    uint error = ERR_OK;
    
    error |= AddResource(RESOURCE_OTHER, "fonts/freemono.ttf");
    
    if (error != ERR_OK)
        return ERR_RESOURCE_LOAD;
    
    return ERR_OK;
}

int Ui::Screen_Info::ShowCredits(Ui::Button* button, int mouseButton, int type)
{
    if (mouseButton == SDL_BUTTON_LEFT && type == SDL_MOUSEBUTTONUP)
    {
        Ui::MessageBox* messageBox = new Ui::MessageBox(credits, true);
        
        screen->AddComponent(messageBox);
        
        messageBox->Component();
    }
    
    return ERR_OK;
}

int Ui::Screen_Info::ShowLicense(Ui::Button* button, int mouseButton, int type)
{
    if (mouseButton == SDL_BUTTON_LEFT && type == SDL_MOUSEBUTTONUP)
    {
        Ui::MessageBox* messageBox = new Ui::MessageBox(license, true);
        
        screen->AddComponent(messageBox);
        
        messageBox->Component();
    }
    
    return ERR_OK;
}

int Ui::Screen_Info::ButtonBack(Ui::Button* button, int mouseButton, int type)
{
    if (mouseButton == SDL_BUTTON_LEFT && type == SDL_MOUSEBUTTONUP)
    {
        Log(LOG_DEBUG) << "Loading debug screen" << NEWLINE;
        
        Ui::Screen* tScreen = new Ui::Screen_Debug();
        
        int error = tScreen->Initialize();
        
        if (error != ERR_OK)
        {
            Log(LOG_ERROR) << GetErrorMessage(error) << NEWLINE;
            
            Ui::ErrorBox* errorBox = new Ui::ErrorBox(Utils::String::Combine(2, "Could not load screen Debug\n\n", GetErrorMessage(error).c_str()));
            
            screen->AddComponent(errorBox);
            
            errorBox->Component();
            
            return ERR_UNKNOWN;
        }
        else
        {
            delete screen;
            screen = tScreen;
        }
    }
    
    return ERR_OK;
}

Ui::Screen_Info::~Screen_Info()
{
    
}
