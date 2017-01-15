#ifndef UI_SCREEN_HPP_
#define UI_SCREEN_HPP_

#include <string>

#include "ui/toolkit/Component.hpp"
#include "ui/toolkit/Button.hpp"
#include "ui/UiHandler.hpp"
#include "io/ResourceHandler.hpp"
#include "io/Resource.hpp"

namespace Ui
{
    class Screen
    {
    private:
        UiHandler* uiHandler;
        ResourceHandler* resourceHandler;
        
    public:
        Screen();
        
        virtual int Initialize() = 0;
        virtual int LoadResources() = 0;
        
        void Draw(SDL_Renderer** renderer);
        void Update(int mouseX, int mouseY);
        
        virtual ~Screen();
        
        
        
        //Resource handler
        int AddResource(std::string archive, std::string path) { return resourceHandler->Add(archive, path); }
        
        ResourceHandler* GetResourceHandler() { return resourceHandler; }
        ResourceHandler** GetResourceHandlerPointer() { return &resourceHandler; }
        
        Resource* GetResource(std::string path) { return resourceHandler->Get(path); }
        
        
        
        //Ui handler
        void AddComponent(Ui::Component* component) { uiHandler->Add(component); }
        
        uint ComponentSize() { return uiHandler->Size(); }
        
        UiHandler* GetUiHandler() { return uiHandler; }
        UiHandler** GetUiHandlerPointer() { return &uiHandler; }
        std::vector<Ui::Component*> GetComponents() { return uiHandler->GetComponents(); }
        std::vector<Ui::Component*>* GetComponentsPointer() { return uiHandler->GetComponentsPointer(); }
        std::vector<Ui::Button*> GetButtons() { return uiHandler->GetButtons(); }
        std::vector<Ui::Button*>* GetButtonsPointer() { return uiHandler->GetButtonsPointer(); }
        
        template<class T>
        T* FindComponent() { return uiHandler->Find<T>(); }
        
        template<class T>
        T* GetComponentAt(int x, int y, bool backwards = true) { return uiHandler->ComponentAt<T>(x, y, backwards); }
        
        Ui::Button* GetButtonAt(int x, int y, bool backwards = true) { return uiHandler->ButtonAt(x, y, backwards); }
    };
};

#endif
