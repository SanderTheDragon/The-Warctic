#ifndef UI_SCREEN_HPP_
#define UI_SCREEN_HPP_

#include <vector>

#include "game/ui/toolkit/Component.hpp"
#include "game/ui/toolkit/Button.hpp"

namespace Ui
{
    class Screen
    {
    private:
        std::vector<Ui::Component*> components;
        
    public:
        Screen();
        
        void Draw(SDL_Renderer** renderer);
        void Update(int mouseX, int mouseY);
        
        void AddComponent(Ui::Component* component) { components.push_back(component); }
        
        Ui::Button* GetButtonAt(int x, int y);
        
        virtual ~Screen();
    };
};

#endif
