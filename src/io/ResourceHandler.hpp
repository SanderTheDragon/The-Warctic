#ifndef RESOURCEHANDLER_HPP_
#define RESOURCEHANDLER_HPP_

#include <map>
#include <string>

#include "io/Resource.hpp"

class ResourceHandler
{
private:
    std::map<std::string, Resource*> resources;
    
public:
    ResourceHandler();
    
    int Add(std::string archive, std::string path);
    
    void Clear();
    void Print();
    
    Resource* Get(std::string path);
    
    virtual ~ResourceHandler();
};

#endif
