#ifndef UI_SCREEN_HPP_
#define UI_SCREEN_HPP_

#include <vector>
#include <map>
#include <string>

#include "game/ui/toolkit/Component.hpp"
#include "game/ui/toolkit/Button.hpp"
#include "misc/Resource.hpp"

namespace Ui
{
    class Screen
    {
    private:
        std::vector<Ui::Component*> components;
        
        std::map<std::string, Resource*> resources;
        
    public:
        Screen();
        
        void Draw(SDL_Renderer** renderer);
        void Update(int mouseX, int mouseY);
        
        virtual ~Screen();
        
        
        
        //Component related stuff
        void AddComponent(Ui::Component* component) { components.push_back(component); }
        
        std::vector<Ui::Component*> GetComponents() { return components; }
        std::vector<Ui::Component*>* GetComponentsPointer() { return &components; }
        
        void ClearComponents() { for(uint i = 0; i < components.size(); i++) { delete components.at(i); } components.clear(); components.shrink_to_fit(); }
        
        //I don't know how safe this is
        template<class T>
        T* FindComponent(uint target = 0)
        {
            uint index = 0;
            
            for (uint i = 0; i < components.size(); i++)
            {
                if (components.at(i)->Type_() == T::Type())
                {
                    if (index < target)
                        index++;
                    else
                        return dynamic_cast<T*>(components.at(i));
                }
            }
            
            return NULL;
        }
        
        template<class T>
        T* GetComponentAt(int x, int y, bool backwards = false)
        {
            if (T* c = dynamic_cast<T*>(GetAnyComponentAt(x, y, backwards, T::Type())))
                return c;
            
            return NULL;
        }
        
        Ui::Component* GetAnyComponentAt(int x, int y, bool backwards = false, uint type = UI_UNDEFINED);
        
        
        
        //Resource related stuff
        virtual void LoadResources() = 0;
        
        int LoadResource(std::string archive, std::string path, std::pair<std::string, Resource*>* resourcePair);
        
        int AddResource(std::string archive, std::string path)
        {
            std::pair<std::string, Resource*> resource;
            int error = LoadResource(archive, path, &resource);
            
            if (error != ERR_OK)
                return error;
            
            return AddResource(resource);
        }
        int AddResource(std::pair<std::string, Resource*> resource) { resources.insert(resource); return ERR_OK; }
        
        std::map<std::string, Resource*> GetResources() { return resources; }
        std::map<std::string, Resource*>* GetResourcesPointer() { return &resources; }
        
        Resource* GetResource(std::string path) { return resources[path]; }
        
        void PrintResources();
        void ClearResources();
    };
};

#endif
