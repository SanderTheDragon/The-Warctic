#include "game/ui/toolkit/Screen.hpp"

#include <iostream>

Ui::Screen::Screen()
{
    
}

void Ui::Screen::Draw(SDL_Renderer** renderer)
{
    for (uint i = 0; i < components.size(); i++)
        components[i]->Draw(renderer);
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

Ui::Screen::~Screen()
{
    
}
