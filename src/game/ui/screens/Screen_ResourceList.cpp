#include "game/ui/screens/Screen_ResourceList.hpp"

#include "Config.hpp"
#include "misc/Logger.hpp"
#include "misc/Errors.hpp"

#include "game/ui/toolkit/Label.hpp"
#include "game/ui/toolkit/Button.hpp"
#include "game/ui/toolkit/List.hpp"
#include "game/ui/toolkit/Overlay.hpp"
#include "game/ui/screens/Screen_Debug.hpp"
#include "misc/utils/String.hpp"
#include "misc/utils/File.hpp"

Ui::Screen_ResourceList::Screen_ResourceList()
{
    LoadResources();
    
    Ui::Label* topBox = new Ui::Label(0, 0, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "The Warctic - Debug Mode - Resource list", 24, GetResource("fonts/freemono.ttf"));
    AddComponent(topBox);
    
    Ui::Button* otherButton = new Ui::Button(0, 32, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "other.zip", 24, GetResource("fonts/freemono.ttf"), &ButtonOther, &ButtonHovering, &ButtonNotHovering);
    otherButton->Enable();
    AddComponent(otherButton);
    
    Ui::List* files = new Ui::List(168, 40, WINDOW_W() - 8, WINDOW_H() - 8, Ui::Color(0, 0, 0, 255), 1, Ui::Color(255, 255, 255, 255));
    files->XYToWH(); //Call if w and h were x2 and y2
    AddComponent(files);
    
    Ui::Button* backButton = new Ui::Button(0, 456, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "< Back", 24, GetResource("fonts/freemono.ttf"), &ButtonBack, &ButtonHovering, &ButtonNotHovering);
    backButton->Enable();
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
        
        std::vector<std::string> items = Utils::File::ReadArchive(Utils::String::Combine(2, DIR_RESOURCE, button->GetText().c_str()));
        
        for (uint i = 0; i < items.size(); i++)
        {
            std::string text = Utils::String::Combine(3, button->GetText().c_str(), "/", Utils::String::FileToPath(items.at(i)).c_str());
            Ui::Button* file = new Ui::Button(files->GetX(), files->GetY(), files->GetW() - 2, -1, Ui::Color(0, 0, 0, 255), 1, Ui::Color(255, 255, 255, 255), Ui::Color(255, 255, 255, 255), text, 14, scr->GetResource("fonts/freemono.ttf"), &PreviewResource, &ButtonHovering, &ButtonNotHovering);
            file->SetFontFix(true);
            file->Enable();
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

int Ui::Screen_ResourceList::PreviewResource(Ui::Button* button, int mouseButton, int type)
{
    Ui::Screen_ResourceList* scr = dynamic_cast<Ui::Screen_ResourceList*>(screen);
    
    for (uint i = 0; i < scr->GetComponents().size(); i++)
    {
        if (Ui::Button* button = dynamic_cast<Ui::Button*>(scr->GetComponents().at(i)))
            button->Disable();
    }
    
    std::string file = button->GetText();
    
    std::string archive = Utils::String::Split(file, '/')[0];
    std::string path = file.substr(archive.length() + 1, file.length());
    std::string ext = path.substr(path.find(".") + 1, file.length());
    
    Log(LOG_DEBUG) << "Preview for \'" << path << "\' in \'" << archive << "\'" << NEWLINE;
    
    Ui::Overlay* overlay = new Overlay(8, 8, WINDOW_W() - 8, WINDOW_H() - 8, Ui::Color(0, 0, 0, 255), 2, Ui::Color(255, 255, 255, 255));
    overlay->XYToWH();
    
    if (ext == "ttf")
    {
        Ui::Label* str1 = new Ui::Label(10, 10, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "The quick brown fox jumps over the lazy dog", 24, scr->GetResource(path));
        overlay->AddComponent(str1);
        Ui::Label* str2 = new Ui::Label(10, 36, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "The quick brown fox jumps over the lazy dog", 22, scr->GetResource(path));
        overlay->AddComponent(str2);
        Ui::Label* str3 = new Ui::Label(10, 60, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "The quick brown fox jumps over the lazy dog", 20, scr->GetResource(path));
        overlay->AddComponent(str3);
        Ui::Label* str4 = new Ui::Label(10, 82, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "The quick brown fox jumps over the lazy dog", 18, scr->GetResource(path));
        overlay->AddComponent(str4);
        Ui::Label* str5 = new Ui::Label(10, 102, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "The quick brown fox jumps over the lazy dog", 16, scr->GetResource(path));
        overlay->AddComponent(str5);
        Ui::Label* str6 = new Ui::Label(10, 120, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "The quick brown fox jumps over the lazy dog", 14, scr->GetResource(path));
        overlay->AddComponent(str6);
        
        Ui::Label* prev1 = new Ui::Label(10, 166, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "ABCDEFGHIJKLMNOPQRTSUVWXYZ", 24, scr->GetResource(path));
        overlay->AddComponent(prev1);
        Ui::Label* prev2 = new Ui::Label(10, 192, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "abcdefghijklmnopqrstuvwxyz", 24, scr->GetResource(path));
        overlay->AddComponent(prev2);
        Ui::Label* prev3 = new Ui::Label(10, 218, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "!@#$%^&*()-_=+[]{}\\:;\"\',.<>?/~`", 24, scr->GetResource(path));
        overlay->AddComponent(prev3);
    }
    
    Ui::Button* close = new Ui::Button(10, overlay->GetY() + overlay->GetH() - 27, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "X Close", 24, scr->GetResource("fonts/freemono.ttf"), &ClosePreview, &ButtonHovering, &ButtonNotHovering);
    close->Enable();
    overlay->AddComponent(close);
    
    scr->AddComponent(overlay);
    
    return ERR_OK;
}

int Ui::Screen_ResourceList::ClosePreview(Ui::Button* button, int mouseButton, int type)
{
    Ui::Screen_ResourceList* scr = dynamic_cast<Ui::Screen_ResourceList*>(screen);
    
    Ui::Overlay* overlay = scr->FindComponent<Ui::Overlay>();
    
    scr->RemoveLastComponent();
    
    for (uint i = 0; i < scr->GetComponents().size(); i++)
    {
        if (Ui::Button* button = dynamic_cast<Ui::Button*>(scr->GetComponents().at(i)))
            button->Enable();
    }
    
    delete overlay;
        
    return ERR_OK;
}

Ui::Screen_ResourceList::~Screen_ResourceList()
{
    
}
