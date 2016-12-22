#include "misc/Resource.hpp"

#include "minizip/unzip.h"

#include "Config.hpp"
#include "misc/Logger.hpp"
#include "misc/Errors.hpp"

Resource::Resource()
{
    
}

int Resource::Load(std::string archive, std::string file)
{
    unzFile data = unzOpen(archive.c_str());
    unz_file_info info;
    
    unzLocateFile(data, file.c_str(), 1);
    unzGetCurrentFileInfo(data, &info, NULL, 0, NULL, 0, NULL, 0);
    unzOpenCurrentFile(data);
    
    buffer = (uint*)malloc(info.uncompressed_size);
    unzReadCurrentFile(data, buffer, info.uncompressed_size);
    
    rw = SDL_RWFromMem(buffer, info.uncompressed_size);
    
    unzClose(data);
    
    return ERR_OK;
}

Resource::~Resource()
{
    SDL_FreeRW(rw);
    free(buffer);
}
