#include "misc/utils/File.hpp"

#if defined(LIN)
#include <sys/stat.h>
#endif

#include "minizip/unzip.h"

#include "Config.hpp"
#include "misc/Logger.hpp"
#include "misc/Errors.hpp"

bool Utils::File::Exists(std::string path)
{
#if defined(LIN)
    struct stat buffer;
    
    if (stat(path.c_str(), &buffer) == 0)
    {
        Log(LOG_DEBUG) << "File \'" << path << "\' was found" << NEWLINE;
        
        return true;
    }
#elif defined(MAC)
    //TODO: File existance checker for Mac
#elif defined(WIN)
    //TODO: File existance checker for Windows
#endif

    Log(LOG_DEBUG_ERROR) << "File \'" << path << "\' was not found" << NEWLINE;
    
    return false;
}

std::vector<std::string> Utils::File::ReadArchive(std::string archive)
{
    std::vector<std::string> files;
    
    unzFile data = unzOpen(archive.c_str());
    unz_file_info info;
    
    unzGoToFirstFile(data);
    
    do
    {
        char buffer[256];
        unzGetCurrentFileInfo(data, &info, buffer, sizeof(buffer), NULL, 0, NULL, 0);
        
        files.push_back(std::string(buffer));
    } while (unzGoToNextFile(data) == UNZ_OK);

    unzClose(data);
    
    return files;
}
