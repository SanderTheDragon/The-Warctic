#include "Config.hpp"
#include "misc/Logger.hpp"

int main(int argc, char* argv[]) 
{
    Log(LOG_NONE) << "--- Starting `The Warctic` ---" << NEWLINE;
    Log(LOG_NONE) << "\tVersion " << VER_MAJOR << "." << VER_MINOR << "." << VER_BUILD << NEWLINE;
    
#ifdef DEBUG
    Log(LOG_DEBUG) << "Debug mode active" << NEWLINE;
    
    Log(LOG_NONE) << " --- Color coding ---" << NEWLINE;
    Log(LOG_DEBUG) << "Debug" << NEWLINE;
    Log(LOG_INFO) << "Info" << NEWLINE;
    Log(LOG_WARNING) << "Warning" << NEWLINE;
    Log(LOG_ERROR) << "Error" << NEWLINE;
    Log(LOG_NONE) << "---------------------" << NEWLINE;
#endif
}
