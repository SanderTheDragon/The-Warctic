#include "Config.hpp"
#include "misc/Error.hpp"
#include "misc/Logger.hpp"
#include "game/Engine.hpp"
#include "game/io/File.hpp"

int main(int argc, char* argv[]) 
{
    int error = ERR_OK;
    
    if (File::FileExists("./out.log", true))
        File::DeleteFile("./out.log", true);

    File::CreateFile("./out.log", true);

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
    
    Log(LOG_INFO) << "Starting engine" << NEWLINE;
    
    Engine* engine = new Engine();
    
    error = engine->Initialize();
    if (error != ERR_OK)
        Log(LOG_ERROR) << GetErrorString(error) << NEWLINE;
    else
        Log(LOG_INFO) << "Engine is started" << NEWLINE;
    
    while (engine->IsRunning())
    {
        engine->Loop();
    }
    
    Log(LOG_INFO) << "Stopping engine" << NEWLINE;
    
    engine->~Engine();
    
    Log(LOG_INFO) << "Engine is stopped" << NEWLINE;
    
    Log(LOG_NONE) << "---  End of `The Warctic`  ---" << NEWLINE;
}
