#include "io/ResourceHandler.hpp"

#include "Config.hpp"
#include "misc/Logger.hpp"
#include "misc/Errors.hpp"

ResourceHandler::ResourceHandler()
{
    
}

int ResourceHandler::Add(std::string archive, std::string path)
{
    Resource* resource = new Resource();
    
    Log(LOG_DEBUG) << "Loading \'" << path << "\' from \'" << archive << "\'" << NEWLINE;
    
    int error = resource->Load(archive, Utils::String::PathToFile(path));
    
    if (error != ERR_OK)
    {
        Log(LOG_ERROR) << GetErrorMessage(error) << NEWLINE;
        
        return error;
    }
    
    resources.insert(std::pair<std::string, Resource*>(path, resource));
    
    return ERR_OK;
}

void ResourceHandler::Clear()
{
    for (std::map<std::string, Resource*>::iterator it = resources.begin(); it != resources.end(); it++)
        delete it->second;
    
    resources.clear();
}

void ResourceHandler::Print()
{
    int i = 0;
    
    for (std::map<std::string, Resource*>::iterator it = resources.begin(); it != resources.end(); it++)
    {
        Log(LOG_DEBUG) << i << ": " << it->first << " = " << it->second << NEWLINE;
        
        i++;
    }
}

Resource* ResourceHandler::Get(std::string path)
{
    if (resources.find(path) == resources.end())
        return NULL;
    
    return resources[path];
}

ResourceHandler::~ResourceHandler()
{
    Clear();
}
