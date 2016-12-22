#ifndef UTILS_FILE_HPP_
#define UTILS_FILE_HPP_

#include <string>
#include <vector>

namespace Utils
{
    class File
    {
    public:
        static bool Exists(std::string path);                               //Checks if file exists
        
        static std::vector<std::string> ReadArchive(std::string archive);   //Lists files in archive
    };
};

#endif
