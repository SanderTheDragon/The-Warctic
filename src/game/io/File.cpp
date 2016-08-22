#include "game/io/File.hpp"

#include <cstdio>
#include <fstream>
#if defined(LIN)
#include <sys/stat.h>
#endif

#include "Config.hpp"
#include "misc/Error.hpp"
#include "misc/Logger.hpp"

bool File::FileExists(const char* path, bool silent)
{
#ifdef DEBUG
    if (!silent)
        Log(LOG_DEBUG) << "Checking file \'" << path << "\'" << NEWLINE;
#endif

    bool exists = false;
    
#if defined(LIN)
    struct stat buffer;
    
    if (stat(path, &buffer) == 0)
        exists = true;
#elif defined(WIN)
    //TODO: FileExists() handler for Windows
#elif defined(MAC)
    //TODO: FileExists() handler for Mac
#endif
    
#ifdef DEBUG
    if (!silent)
        if (exists)
            Log(LOG_DEBUG) << "File \'" << path <<  "\' found" << NEWLINE;
        else
            Log(LOG_DEBUG_ERROR) << "File \'" << path << "\' not found" << NEWLINE;
#endif
    
    return exists;
}

uint File::CreateFile(const char* path, bool silent)
{
#ifdef DEBUG
    if (!silent)
        Log(LOG_DEBUG) << "Creating file \'" << path << "\'" << NEWLINE;
#endif
    
    std::ofstream file(path);
    
    if (!file.is_open())
        return ERR_FILE_NOT_OPEN;
    
    file.close();
    
    return ERR_OK;
}

uint File::DeleteFile(const char* path, bool silent)
{
#ifdef DEBUG
    if (!silent)
        Log(LOG_DEBUG) << "Deleting file \'" << path << "\'" << NEWLINE;
#endif
    
    int res = remove(path);
    
    if (res != 0)
        return ERR_FILE_UNKNOWN;
    
    return ERR_OK;
}
