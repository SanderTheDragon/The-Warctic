#ifndef UI_SCREEN_HPP_
#define UI_SCREEN_HPP_

#include <vector>
#include <map>
#include <string>

#include "game/ui/toolkit/Component.hpp"
#include "game/ui/toolkit/Button.hpp"

namespace Ui
{
    class Screen
    {
    private:
        std::vector<Ui::Component*> components;
        
        std::map<std::string, SDL_RWops*> resources;
        
    public:
        Screen();
        
        void Draw(SDL_Renderer** renderer);
        void Update(int mouseX, int mouseY);
        
        void AddComponent(Ui::Component* component) { components.push_back(component); }
        void ClearComponents() { components.clear(); }
        
        Ui::Button* GetButtonAt(int x, int y);
        
        virtual void LoadResources() = 0;
        
        std::pair<std::string, SDL_RWops*> LoadResource(std::string archive, std::string path);
        
        void AddResource(std::string archive, std::string path) { resources.insert(LoadResource(archive, path)); }
        void AddResource(std::pair<std::string, SDL_RWops*> resource) { resources.insert(resource); }
        SDL_RWops* GetResource(std::string path) { return resources[path]; }
        
        virtual ~Screen();
    };
};

#endif
