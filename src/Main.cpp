#include "Config.hpp"
#include "misc/Logger.hpp"

int main(int argc, char* argv[]) 
{
    Log(LOG_NONE) << "--- Starting `The Warctic` ---" << NEWLINE;
    Log(LOG_NONE) << "\tVersion " << VER_MAJOR << "." << VER_MINOR << "." << VER_BUILD << NEWLINE;
    
#ifdef DEBUG
    Log(LOG_DEBUG) << "Debug mode active" << NEWLINE;
    
    Log(LOG_NONE, false) << "--- Color coding ---" << NEWLINE;
    Log(LOG_DEBUG, false) << "Debug" << NEWLINE;
    Log(LOG_DEBUG_ERROR, false) << "Debug Error" << NEWLINE;
    Log(LOG_INFO, false) << "Info" << NEWLINE;
    Log(LOG_SYSTEM, false) << "System" << NEWLINE;
    Log(LOG_WARNING, false) << "Warning" << NEWLINE;
    Log(LOG_ERROR, false) << "Error" << NEWLINE;
    Log(LOG_NONE, false) << "--------------------" << NEWLINE;
#endif
    
    Log(LOG_NONE) << "---  End of `The Warctic`  ---" << NEWLINE;
}
