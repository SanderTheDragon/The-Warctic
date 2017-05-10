#include "File.hpp"

//#include <filesystem> --- waiting for filesystem support in libstdc++17

#if defined(LIN)
#include <sys/stat.h>
#else
//No support for other than linux yet, just wait for ^^^
#endif

#include "Config.hpp"
#include "Errors.hpp"
#include "utils/Logger.hpp"

bool File::Exists(std::string path)
{
#if defined(LIN)
	struct stat buffer;
	
	if (stat(path.c_str(), &buffer) == 0)
	{
		Log(LOG_TRACE) << "File \'" << path << "\' was found" << NEWLINE;
		
		return true;
	}
#endif
	
	Log(LOG_TRACE) << "File \'" << path << "\' was not found" << NEWLINE;
	
	return false;
}
