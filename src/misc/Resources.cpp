#include "misc/Resources.hpp"

#include "zlib.h"
#include "minizip/zip.h"
#include "minizip/unzip.h"

SDL_RWops* Resources::GetFile(std::string archive, std::string file)
{
    unzFile data = unzOpen(archive.c_str());
    unz_file_info info;
    
    unzLocateFile(data, file.c_str(), 1);
    unzGetCurrentFileInfo(data, &info, NULL, 0, NULL, 0, NULL, 0);
    unzOpenCurrentFile(data);
    
    uint* buffer = (uint*)malloc(info.uncompressed_size);
    unzReadCurrentFile(data, buffer, info.uncompressed_size);
    
    SDL_RWops* rw = SDL_RWFromMem(buffer, info.uncompressed_size);
    
    unzClose(data);
    
    return rw;
}
