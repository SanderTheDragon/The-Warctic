#ifndef UIHANDLER_HPP_
#define UIHANDLER_HPP_

#include <vector>

#include "SDL2/SDL.h"

#include "ui/toolkit/Component.hpp"
#include "ui/toolkit/Button.hpp"

class UiHandler
{
private:
    std::vector<Ui::Component*> components;
    std::vector<Ui::Button*> buttons;
    
public:
    UiHandler();
    
    void Draw(SDL_Renderer** renderer);
    void Update(int mouseX, int mouseY);
    
    void Add(Ui::Component* component);
    void Clear();
    
    void DisableButtons();
    void EnableButtons();
    
    uint Size() { return components.size(); }
    
    std::vector<Ui::Component*> GetComponents() { return components; }
    std::vector<Ui::Component*>* GetComponentsPointer() { return &components; }
    std::vector<Ui::Button*> GetButtons() { return buttons; }
    std::vector<Ui::Button*>* GetButtonsPointer() { return &buttons; }
    
    template<class T>
    T* Find()
    {
        for (uint i = 0; i < components.size(); i++)
        {
            if (components.at(i)->Type_() == T::Type())
                return dynamic_cast<T*>(components.at(i));
        }
        
        return NULL;
    }
    
    template<class T>
    T* ComponentAt(int x, int y, bool backwards = true)
    {
        if (backwards)
        {
            for (uint i = components.size() - 1; i >= 0; i--)
            {
                if (i > components.size())
                    i = 0;
                
                Ui::Component* com = components.at(i);
                
                if (x >= com->GetX() && x <= com->GetX() + com->GetW() && y >= com->GetY() && y <= com->GetY() + com->GetH())
                {
                    if (com->Type_() == T::Type())
                        return dynamic_cast<T*>(com);
                }
            }
        }
        else
        {
            for (uint i = 0; i < components.size(); i++)
            {
                Ui::Component* com = components.at(i);
                
                if (x >= com->GetX() && x <= com->GetX() + com->GetW() && y >= com->GetY() && y <= com->GetY() + com->GetH())
                {
                    if (com->Type_() == T::Type())
                        return dynamic_cast<T*>(com);
                }
            }
        }
        
        return NULL;
    }
    
    Ui::Button* ButtonAt(int x, int y, bool backwards = true)
    {
        if (backwards)
        {
            for (uint i = buttons.size() - 1; i >= 0; i--)
            {
                if (i > buttons.size())
                    break;
                
                Ui::Button* com = buttons.at(i);
                
                if (x >= com->GetX() && x <= com->GetX() + com->GetW() && y >= com->GetY() && y <= com->GetY() + com->GetH())
                    return com;
            }
            
            return NULL;
        }
        else
        {
            for (uint i = 0; i < buttons.size(); i++)
            {
                Ui::Button* com = buttons.at(i);
                
                if (x >= com->GetX() && x <= com->GetX() + com->GetW() && y >= com->GetY() && y <= com->GetY() + com->GetH())
                    return com;
            }
            
            return NULL;
        }
        
        return NULL;
    }
    
    virtual ~UiHandler();
};

#endif
