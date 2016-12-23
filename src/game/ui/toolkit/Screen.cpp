#include "game/ui/toolkit/Screen.hpp"

#include "Config.hpp"
#include "misc/Logger.hpp"
#include "misc/Errors.hpp"

#include "game/ui/toolkit/List.hpp"
#include "game/ui/toolkit/Overlay.hpp"

Ui::Screen::Screen()
{
    
}

void Ui::Screen::Draw(SDL_Renderer** renderer)
{
    for (uint i = 0; i < components.size(); i++)
        components.at(i)->Draw(renderer);
}

//TODO: Improve this stuff
void Ui::Screen::Update(int mouseX, int mouseY)
{
    for (uint i = 0; i < components.size(); i++)
    {
        if (Ui::Box* box = dynamic_cast<Ui::Box*>(components.at(i)))
        {
            if (Ui::Button* button = dynamic_cast<Ui::Button*>(box))
            {
                if (mouseX >= button->GetX() && mouseX <= button->GetX() + button->GetW() && mouseY >= button->GetY() && mouseY <= button->GetY() + button->GetH() && button->GetEnabled())
                    button->GetHovering()(button);
                else
                    button->GetNotHovering()(button);
            }
            
            if (Ui::List* list = dynamic_cast<Ui::List*>(box))
            {
                for (uint j = 0; j < list->GetComponents().size(); j++)
                {
                    Ui::Box* sub = list->GetComponents().at(j);
                    
                    if (Ui::Button* button = dynamic_cast<Ui::Button*>(sub))
                    {
                        if (mouseX >= button->GetX() && mouseX <= button->GetX() + button->GetW() && mouseY >= button->GetY() && mouseY <= button->GetY() + button->GetH() && button->GetEnabled())
                            button->GetHovering()(button);
                        else
                            button->GetNotHovering()(button);
                    }
                }
            }
            
            if (Ui::Overlay* list = dynamic_cast<Ui::Overlay*>(box))
            {
                for (uint j = 0; j < list->GetComponents().size(); j++)
                {
                    Ui::Component* sub = list->GetComponents().at(j);
                    
                    if (Ui::Button* button = dynamic_cast<Ui::Button*>(sub))
                    {
                        if (mouseX >= button->GetX() && mouseX <= button->GetX() + button->GetW() && mouseY >= button->GetY() && mouseY <= button->GetY() + button->GetH() && button->GetEnabled())
                            button->GetHovering()(button);
                        else
                            button->GetNotHovering()(button);
                    }
                }
            }
        }
    }
}

Ui::Button* Ui::Screen::GetButtonAt(int x, int y)
{
    for (uint i = 0; i < components.size(); i++)
    {
        if (Ui::Box* box = dynamic_cast<Ui::Box*>(components.at(i)))
        {
            if (x >= box->GetX() && x <= box->GetX() + box->GetW() && y >= box->GetY() && y <= box->GetY() + box->GetH())
            {
                if (Ui::Button* button = dynamic_cast<Ui::Button*>(box))
                    if (button->GetEnabled())
                        return button;
                
                if (Ui::List* list = dynamic_cast<Ui::List*>(box))
                {
                    for (uint j = 0; j < list->GetComponents().size(); j++)
                    {
                        Ui::Box* sub = list->GetComponents().at(j);
                        
                        if (x >= sub->GetX() && x <= sub->GetX() + sub->GetW() && y >= sub->GetY() && y <= sub->GetY() + sub->GetH())
                        {
                            if (Ui::Button* button = dynamic_cast<Ui::Button*>(sub))
                                if (button->GetEnabled())
                                    return button;
                        }
                    }
                }
                
                if (Ui::Overlay* list = dynamic_cast<Ui::Overlay*>(box))
                {
                    for (uint j = 0; j < list->GetComponents().size(); j++)
                    {
                        if (Ui::Button* sub = dynamic_cast<Ui::Button*>(list->GetComponents().at(j)))
                        {
                            if (x >= sub->GetX() && x <= sub->GetX() + sub->GetW() && y >= sub->GetY() && y <= sub->GetY() + sub->GetH())
                            {
                                if (sub->GetEnabled())
                                    return sub;
                            }
                        }
                    }
                }
            }
        }
    }
    
    return NULL;
}

std::pair<std::string, Resource*> Ui::Screen::LoadResource(std::string archive, std::string path)
{
    Log(LOG_DEBUG) << "Loading \'" << path << "\' from \'" << archive << "\'" << NEWLINE;
    
    Resource* resource = new Resource();
    resource->Load(archive, Utils::String::PathToFile(path));
    
    return std::pair<std::string, Resource*>(path, resource);
}

void Ui::Screen::ClearResources()
{
    for (std::map<std::string, Resource*>::iterator it = resources.begin(); it != resources.end(); it++)
        delete it->second;
    
    resources.clear();
}

Ui::Screen::~Screen()
{
    ClearResources();
    ClearComponents();
}
