#ifndef RESOURCES_HPP_
#define RESOURCES_HPP_

#include <string>

#include "SDL2/SDL.h"

class Resources
{
public:
    static SDL_RWops* GetFile(std::string archive, std::string file);
};

#endif
