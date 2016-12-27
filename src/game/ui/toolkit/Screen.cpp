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

void Ui::Screen::Update(int mouseX, int mouseY)
{
    for (uint i = 0; i < components.size(); i++)
    {
        if (Ui::Button* b = dynamic_cast<Ui::Button*>(components.at(i)))
        {
            if (mouseX >= b->GetX() && mouseX <= b->GetX() + b->GetW() && mouseY >= b->GetY() && mouseY <= b->GetY() + b->GetH() && b->GetEnabled())
                b->GetHovering()(b);
            else
                b->GetNotHovering()(b);
        }
    }
}

Ui::Component* Ui::Screen::GetAnyComponentAt(int x, int y, bool backwards, uint type)
{
    if (!backwards)
    {
        for (uint i = 0; i < components.size(); i++)
        {
            Ui::Component* com = components.at(i);
            
            if (x >= com->GetX() && x <= com->GetX() + com->GetW() && y >= com->GetY() && y <= com->GetY() + com->GetH())
            {
                if (type == com->Type_() || type == UI_UNDEFINED)
                    return com;
            }
        }
    }
    else
    {
        for (uint i = components.size() - 1; i > 0; i--)
        {
            Ui::Component* com = components.at(i);
            
            if (x >= com->GetX() && x <= com->GetX() + com->GetW() && y >= com->GetY() && y <= com->GetY() + com->GetH())
            {
                if (type == com->Type_() || type == UI_UNDEFINED)
                    return com;
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
