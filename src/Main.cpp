/***************************************************************************\
|*  The Warctic, A 3D game about penguins at war                           *|
|*  Copyright (C) 2016  SanderTheDragon                                    *|
|*                                                                         *|
|*  This program is free software: you can redistribute it and/or modify   *|
|*  it under the terms of the GNU General Public License as published by   *|
|*  the Free Software Foundation, either version 3 of the License, or      *|
|*  (at your option) any later version.                                    *|
|*                                                                         *|
|*  This program is distributed in the hope that it will be useful,        *|
|*  but WITHOUT ANY WARRANTY; without even the implied warranty of         *|
|*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *|
|*  GNU General Public License for more details.                           *|
|*                                                                         *|
|*  You should have received a copy of the GNU General Public License      *|
|*  along with this program.  If not, see <http://www.gnu.org/licenses/>.  *|
\***************************************************************************/

#include <string>

#include "Config.hpp"
#include "misc/Logger.hpp"
#include "misc/utils/Version.hpp"
#include "game/Engine.hpp"

bool debug = false;
bool colors = true;

int main(int argc, char* argv[]) 
{
    //Argument parsing
    for (int i = 0; i < argc; i++)
    {
        std::string arg = std::string(argv[i]);
        
        if (arg == "--debug" || arg == "-d")
        {
            ::debug = true;
        }
        
        if (arg == "--nocolor" || arg == "--no-color" || arg == "--nocolour" || arg == "--no-colour" || arg == "-n" || arg == "--no(-)colo(u)r") //Don't nag about color/colour, you can use either,  the last one, well..., you probably get it why
        {
            ::colors = false;
        }
        
        if (arg == "--help" || arg == "-h")
        {
            ::debug = true; //Fastest way to do this
            
            Log(LOG_DEFAULT, false) << NEWLINE;
            
            Log(LOG_DEFAULT, false) << "Help for `The Warctic` Version " << VERSION << NEWLINE;
            
#if defined(WIN) //Windows needs to be special again
            Log(LOG_DEFAULT, false) << "Usage: warctic.exe [-d,-n,-h]" << NEWLINE << NEWLINE;
#else
            Log(LOG_DEFAULT, false) << "Usage: ./warctic [-d,-n,-h]" << NEWLINE << NEWLINE;
#endif
            
            Log(LOG_DEFAULT, false) << "-d" << "\t--debug" << "\t\t\tStarts in debug mode" << NEWLINE;
            Log(LOG_DEFAULT, false) << "-n" << "\t--no(-)colo(u)r" << "\t\tRemoves ansi colors from terminal" << NEWLINE;
            Log(LOG_DEFAULT, false) << "-h" << "\t--help" << "\t\t\tShows this help message" << NEWLINE;
            
            Log(LOG_DEFAULT, false) << NEWLINE;
            
            return 0;
        }
    }
    
    Log(LOG_NONE) << "--- Starting `The Warctic` ---" << NEWLINE;
    Utils::Version::PrintWarctic();
    
    //Debug info
    Log(LOG_DEBUG) << "Debug mode active" << NEWLINE;
    
    if (::colors) //Color coding is useless without colors
    {
        Log(LOG_NONE, false) << "--- Color coding ---" << NEWLINE;
        Log(LOG_DEBUG, false) << "Debug" << NEWLINE;
        Log(LOG_DEBUG_ERROR, false) << "Debug Error" << NEWLINE;
        Log(LOG_INFO, false) << "Info" << NEWLINE;
        Log(LOG_SYSTEM, false) << "System" << NEWLINE;
        Log(LOG_WARNING, false) << "Warning" << NEWLINE;
        Log(LOG_ERROR, false) << "Error" << NEWLINE;
        Log(LOG_NONE, false) << "--------------------" << NEWLINE;
    }
    //End debug info
    
    Log(LOG_SYSTEM) << "System: " << SYSTEM << NEWLINE; //System info
    
    Engine* engine = new Engine();
    
    while (engine->IsRunning())
    {
        engine->Loop();
    }
    
    engine->~Engine();
    
    Log(LOG_NONE) << "---  End of `The Warctic`  ---" << NEWLINE;
    
    return 0;
}
