#include "ui/screens/Screen_ResourceList.hpp"

#include "Config.hpp"
#include "misc/Logger.hpp"
#include "misc/Errors.hpp"

#include "ui/toolkit/Label.hpp"
#include "ui/toolkit/Button.hpp"
#include "ui/toolkit/List.hpp"
#include "ui/toolkit/Overlay.hpp"
#include "ui/toolkit/ErrorBox.hpp"
#include "ui/screens/Screen_Debug.hpp"
#include "ui/screens/Screen_Info.hpp"
#include "misc/utils/String.hpp"
#include "misc/utils/File.hpp"

Ui::Screen_ResourceList::Screen_ResourceList()
{
    
}

int Ui::Screen_ResourceList::Initialize()
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
    
    Ui::Label* topBox = new Ui::Label(infoButton->GetW(), 0, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), " - Debug Mode - Resource list", 24, GetResource("fonts/freemono.ttf"));
    AddComponent(topBox);
    
    Ui::Button* otherButton = new Ui::Button(0, 32, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "other.zip", 24, GetResource("fonts/freemono.ttf"), &ButtonOther);
    otherButton->Enable();
    AddComponent(otherButton);
    
    Ui::List* files = new Ui::List(168, 40, WINDOW_W() - 8, WINDOW_H() - 8, Ui::Color(0, 0, 0, 255), 1, Ui::Color(255, 255, 255, 255), GetComponentsPointer());
    files->XYToWH(); //Call if w and h were x2 and y2
    AddComponent(files);
    
    Ui::Button* backButton = new Ui::Button(0, 456, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "< Back", 24, GetResource("fonts/freemono.ttf"), &ButtonBack);
    backButton->Enable();
    AddComponent(backButton);
    
    return ERR_OK;
}

int Ui::Screen_ResourceList::LoadResources()
{
    uint error = ERR_OK;
    
    error |= AddResource(RESOURCE_OTHER, "fonts/freemono.ttf");
    
    if (error != ERR_OK)
        return ERR_RESOURCE_LOAD;
    
    return ERR_OK;
}

int Ui::Screen_ResourceList::ButtonOther(Ui::Button* button, int mouseButton, int type)
{
    if (mouseButton == SDL_BUTTON_LEFT && type == SDL_MOUSEBUTTONUP)
    {
        Ui::List* files = ::screen->FindComponent<Ui::List>();
        
        for (uint i = (*::screen->GetComponentsPointer()).size() - 1; i > 0; i--) //Needs to be done backwards
        {
            if ((*::screen->GetComponentsPointer()).at(i)->GetParent() == files)
                (*::screen->GetComponentsPointer()).erase((*::screen->GetComponentsPointer()).begin() + i);
        }
        
        std::vector<std::string> items = Utils::File::ReadArchive(Utils::String::Combine(2, DIR_RESOURCE, button->GetText().c_str()));
        
        for (uint i = 0; i < items.size(); i++)
        {
            std::string text = Utils::String::Combine(3, button->GetText().c_str(), "/", Utils::String::FileToPath(items.at(i)).c_str());
            Ui::Button* file = new Ui::Button(files->GetX(), files->GetY(), files->GetW() - 2, -1, Ui::Color(0, 0, 0, 255), 1, Ui::Color(255, 255, 255, 255), Ui::Color(255, 255, 255, 255), text, 14, ::screen->GetResource("fonts/freemono.ttf"), &PreviewResource);
            file->SetFontFix(true);
            file->SetParent(files);
            file->Enable();
            ::screen->AddComponent(file);
        }
    }
    
    return ERR_OK;
}

int Ui::Screen_ResourceList::ButtonInfo(Ui::Button* button, int mouseButton, int type)
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

int Ui::Screen_ResourceList::ButtonBack(Ui::Button* button, int mouseButton, int type)
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
            
            ::screen->AddComponent(errorBox);
            
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

int Ui::Screen_ResourceList::PreviewResource(Ui::Button* button, int mouseButton, int type)
{
    if (mouseButton == SDL_BUTTON_LEFT && type == SDL_MOUSEBUTTONUP)
    {
        (*::screen->GetUiHandlerPointer())->DisableButtons();
        
        std::string file = button->GetText();
        
        std::string archive = Utils::String::Split(file, '/')[0];
        std::string path = file.substr(archive.length() + 1, file.length());
        std::string ext = path.substr(path.find(".") + 1, file.length());
        
        int error = ERR_OK;
        
        if (!::screen->GetResource(path))
            error = ::screen->AddResource(Utils::String::Combine(2, DIR_RESOURCE, archive.c_str()), path);
        
        Resource* res = ::screen->GetResource(path);
        
        if (error != ERR_OK || !res)
        {
            Log(LOG_ERROR) << GetErrorMessage(error) << NEWLINE;
            
            Ui::ErrorBox* errorBox = new Ui::ErrorBox(Utils::String::Combine(4, "Could not load file: \n", path.c_str(), "\n\n", GetErrorMessage(error).c_str()));
            
            ::screen->AddComponent(errorBox);
            
            return ERR_UNKNOWN;
        }
        
        Log(LOG_DEBUG) << "Preview for \'" << path << "\' in \'" << archive << "\'" << NEWLINE;
        
        Ui::Overlay* overlay = new Overlay(8, 8, WINDOW_W() - 8, WINDOW_H() - 8, Ui::Color(0, 0, 0, 255), 2, Ui::Color(255, 255, 255, 255));
        overlay->XYToWH();
        ::screen->AddComponent(overlay);
        
        if (ext == "ttf")
        {
            Ui::Label* str1 = new Ui::Label(10, 10, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "The quick brown fox jumps over the lazy dog", 24, res);
            str1->SetParent(overlay);
            ::screen->AddComponent(str1);
            Ui::Label* str2 = new Ui::Label(10, 36, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "The quick brown fox jumps over the lazy dog", 22, res);
            str2->SetParent(overlay);
            ::screen->AddComponent(str2);
            Ui::Label* str3 = new Ui::Label(10, 60, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "The quick brown fox jumps over the lazy dog", 20, res);
            str3->SetParent(overlay);
            ::screen->AddComponent(str3);
            Ui::Label* str4 = new Ui::Label(10, 82, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "The quick brown fox jumps over the lazy dog", 18, res);
            str4->SetParent(overlay);
            ::screen->AddComponent(str4);
            Ui::Label* str5 = new Ui::Label(10, 102, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "The quick brown fox jumps over the lazy dog", 16, res);
            str5->SetParent(overlay);
            ::screen->AddComponent(str5);
            Ui::Label* str6 = new Ui::Label(10, 120, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "The quick brown fox jumps over the lazy dog", 14, res);
            str6->SetParent(overlay);
            ::screen->AddComponent(str6);
            
            Ui::Label* prev1 = new Ui::Label(10, 166, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "ABCDEFGHIJKLMNOPQRTSUVWXYZ", 24, res);
            prev1->SetParent(overlay);
            ::screen->AddComponent(prev1);
            Ui::Label* prev2 = new Ui::Label(10, 192, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "abcdefghijklmnopqrstuvwxyz", 24, res);
            prev2->SetParent(overlay);
            ::screen->AddComponent(prev2);
            Ui::Label* prev3 = new Ui::Label(10, 218, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "1234567890", 24, res);
            prev3->SetParent(overlay);
            ::screen->AddComponent(prev3);
            Ui::Label* prev4 = new Ui::Label(10, 244, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "!@#$%^&*()-_=+[]{}\\:;\"\',.<>?/~`", 24, res);
            prev4->SetParent(overlay);
            ::screen->AddComponent(prev4);
        }
        
        Ui::Button* close = new Ui::Button(10, overlay->GetY() + overlay->GetH() - 27, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "X Close", 24, ::screen->GetResource("fonts/freemono.ttf"), &ClosePreview);
        close->SetParent(overlay);
        close->Enable();
        ::screen->AddComponent(close);
        
        if (!::screen->GetResource(path))
            delete res;
    }
    
    
    return ERR_OK;
}

int Ui::Screen_ResourceList::ClosePreview(Ui::Button* button, int mouseButton, int type)
{
    if (mouseButton == SDL_BUTTON_LEFT && type == SDL_MOUSEBUTTONUP)
    {
        Ui::Overlay* overlay = ::screen->FindComponent<Ui::Overlay>();
        
        (*::screen->GetUiHandlerPointer())->EnableButtons();
        
        for (uint i = (*::screen->GetComponentsPointer()).size() - 1; i > 0; i--) //Needs to be done backwards
        {
            if ((*::screen->GetComponentsPointer()).at(i)->GetParent() == overlay)
            {
                (*::screen->GetComponentsPointer()).erase((*::screen->GetComponentsPointer()).begin() + i);
            }
        }
        
        for (uint i = (*screen->GetButtonsPointer()).size() - 1; i > 0; i--) //Also needs to be done backwards
        {
            if ((*::screen->GetButtonsPointer()).at(i)->GetParent() == overlay)
            {
                (*::screen->GetButtonsPointer()).erase((*::screen->GetButtonsPointer()).begin() + i);
            }
        }
        
        (*::screen->GetComponentsPointer()).erase((*::screen->GetComponentsPointer()).end() - 1);
        
        delete overlay;
    }
    
    return ERR_OK;
}

Ui::Screen_ResourceList::~Screen_ResourceList()
{
    
}
