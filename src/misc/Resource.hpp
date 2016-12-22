#ifndef RESOURCE_HPP_
#define RESOURCE_HPP_

#include <string>
#include <vector>

#include "SDL2/SDL.h"

class Resource
{
private:
    uint* buffer;
    SDL_RWops* rw;
    
public:
    Resource();
    
    int Load(std::string archive, std::string file);
    
    SDL_RWops** Get() { return &rw; }
    
    virtual ~Resource();
};

#endif
