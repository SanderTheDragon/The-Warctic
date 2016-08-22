#ifndef FILE_HPP_
#define FILE_HPP_

#include <iostream>

class File
{
public:
    static bool FileExists(const char* path, bool silent = false);
    
    static uint CreateFile(const char* path, bool silent = false);
    static uint DeleteFile(const char* path, bool silent = false);
};

#endif
