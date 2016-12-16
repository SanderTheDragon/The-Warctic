#include "game/ui/toolkit/Screen.hpp"

#include "Config.hpp"
#include "misc/Logger.hpp"
#include "misc/Errors.hpp"

#include <iostream>

Ui::Screen::Screen()
{
    
}

void Ui::Screen::Draw(SDL_Renderer** renderer)
{
    for (uint i = 0; i < components.size(); i++)
        components[i]->Draw(renderer);
}

void Ui::Screen::Update(int mouseX, int mouseY)
{
    for (uint i = 0; i < components.size(); i++)
    {
        if (Ui::Button* button = dynamic_cast<Ui::Button*>(components[i]))
        {
            if (mouseX >= button->GetX() && mouseX <= button->GetX() + button->GetW() && mouseY >= button->GetY() && mouseY <= button->GetY() + button->GetH())
                button->GetHovering()(button);
            else
                button->GetNotHovering()(button);
        }
    }
}

Ui::Button* Ui::Screen::GetButtonAt(int x, int y)
{
    for (uint i = 0; i < components.size(); i++)
    {
        if (Ui::Button* button = dynamic_cast<Ui::Button*>(components[i]))
        {
            if (x >= button->GetX() && x <= button->GetX() + button->GetW() && y >= button->GetY() && y <= button->GetY() + button->GetH())
                return button;
        }
    }
    
    return NULL;
}

std::pair<std::string, SDL_RWops*> Ui::Screen::LoadResource(std::string archive, std::string path)
{
    Log(LOG_DEBUG) << "Loading \'" << path << "\' from \'" << archive << "\'" << NEWLINE;
    
    return std::pair<std::string, SDL_RWops*>(path, Resources::GetFile(archive, Utils::String::PathToFile(path)));
}

Ui::Screen::~Screen()
{
    
}
