#ifndef FILE_HPP_
#define FILE_HPP_

#include <string>

#include "misc/Types.hpp"

class File
{
public:
	static bool Exists(std::string path);
};

#endif
