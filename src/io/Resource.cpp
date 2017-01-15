#include "io/Resource.hpp"

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
    
    if (data == NULL)
        return ERR_RESOURCE_ARCHIVEOPEN;
    
    unz_file_info info;
    
    if (unzLocateFile(data, file.c_str(), 1) < UNZ_OK)
    {
        unzClose(data);
        
        return ERR_RESOURCE_FILENOTFOUND;
    }
    
    if (unzGetCurrentFileInfo(data, &info, NULL, 0, NULL, 0, NULL, 0) != UNZ_OK)
    {
        unzClose(data);
        
        return ERR_RESOURCE_FILEINFO;
    }

    if (unzOpenCurrentFile(data) != UNZ_OK)
    {
        unzClose(data);
        
        return ERR_RESOURCE_FILEOPEN;
    }
    
    buffer = (uint*)malloc(info.uncompressed_size);
    
    if (unzReadCurrentFile(data, buffer, info.uncompressed_size) < UNZ_OK)
    {
        free(buffer);
        
        unzCloseCurrentFile(data);
        unzClose(data);
        
        return ERR_RESOURCE_FILEREAD;
    }
    
    rw = SDL_RWFromMem(buffer, info.uncompressed_size);
    
    unzCloseCurrentFile(data);
    unzClose(data);
    
    return ERR_OK;
}

Resource::~Resource()
{
    SDL_FreeRW(rw);
    free(buffer);
}
