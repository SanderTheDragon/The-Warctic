#include "ui/UiHandler.hpp"

#include "Config.hpp"
#include "misc/Logger.hpp"
#include "misc/Errors.hpp"

#include "ui/toolkit/Button.hpp"

UiHandler::UiHandler()
{
    
}

void UiHandler::Draw(SDL_Renderer** renderer)
{
    for (uint i = 0; i < components.size(); i++)
        components.at(i)->Draw(renderer);
}

void UiHandler::Update(int mouseX, int mouseY)
{
    for (uint i = 0; i < buttons.size(); i++)
    {
        Ui::Button* b = buttons.at(i);
        
        if (mouseX >= b->GetX() && mouseX <= b->GetX() + b->GetW() && mouseY >= b->GetY() && mouseY <= b->GetY() + b->GetH() && b->GetEnabled())
            b->GetHovering()(b);
        else
            b->GetNotHovering()(b);
    }
}

void UiHandler::Add(Ui::Component* component)
{
    if (component->Type_() == Ui::Button::Type())
        buttons.push_back(static_cast<Ui::Button*>(component));
    
    components.push_back(component);
}

void UiHandler::Clear()
{
    for (uint i = 0; i < components.size(); i++)
        delete components.at(i);
    
    components.clear();
    components.shrink_to_fit();
    
    buttons.clear();
    buttons.shrink_to_fit();
}

void UiHandler::DisableButtons()
{
    for (uint i = 0; i < buttons.size(); i++)
        static_cast<Ui::Button*>(buttons.at(i))->Disable();
}

void UiHandler::EnableButtons()
{
    for (uint i = 0; i < buttons.size(); i++)
        static_cast<Ui::Button*>(buttons.at(i))->Enable();
}

UiHandler::~UiHandler()
{
    Clear();
}
