/***************************************************************************\
|*  The Warctic, A 3D game about penguins at war                           *|
|*  Copyright (C) 2016-2017  SanderTheDragon                               *|
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
#include "misc/Errors.hpp"

#include "misc/utils/Version.hpp"
#include "Engine.hpp"

bool debug = false;
bool colors = true;
bool running = false;
bool suppressed = true;
bool mouseSuppressed = true;
bool logAll = false;

int main(int argc, char* argv[]) 
{
    //Argument parsing
    for (int i = 0; i < argc; i++)
    {
        std::string arg = std::string(argv[i]);
        
        //Debug mode, shows extra information about a lot of things
        if (arg == "--debug" || arg == "-d")
        {
            ::debug = true;
        }
        
        //Disables ANSI colors in terminal
        if (arg == "--nocolor" || arg == "--no-color" || arg == "--nocolour" || arg == "--no-colour" || arg == "-n" || arg == "--no(-)colo(u)r") //Don't nag about color/colour, you can use either, the last one, well..., you probably get it why
        {
            ::colors = false;
        }
        
        //Do not suppress event output, like key press, key release and mouse buttons (requires debug mode)
        if (arg == "--nosuppress" || arg == "--no-suppress" || arg == "-s" || arg == "--no(-)suppress")
        {
            ::suppressed = false;
        }
        
        //Do not suppress mouse event output, like motion and wheel (requires debug mode and no suppress)
        if (arg == "--nomousesuppress" || arg == "--no-mousesuppress" || arg == "--nomouse-suppress" || arg == "--no-mouse-suppress" || arg == "-m" || arg == "--no(-)mouse(-)suppress")
        {
            ::mouseSuppressed = false;
        }
        
        //Logs everything from terminal to file
        if (arg == "--logall" || arg == "--log-all" || arg == "-l" || arg == "--log(-)all")
        {
            ::logAll = true;
        }
        
        //Shows help
        if (arg == "--help" || arg == "-h")
        {
            ::debug = true; //Fastest way to do this
            ::logAll = false;
            
            Log(LOG_DEFAULT, false) << NEWLINE;
            
            Log(LOG_DEFAULT, false) << "Help for `The Warctic` Version " << VERSION << NEWLINE;
            
#if defined(WIN) //Windows needs to be special again
            Log(LOG_DEFAULT, false) << "Usage: warctic.exe [-d] [-n] [-h] [-s] [-m]" << NEWLINE << NEWLINE;
#else
            Log(LOG_DEFAULT, false) << "Usage: ./warctic [-d] [-n] [-h] [-s] [-m]" << NEWLINE << NEWLINE;
#endif
            
            Log(LOG_DEFAULT, false) << "-d" << "\t--debug" << "                    Starts in debug mode" << NEWLINE;
            Log(LOG_DEFAULT, false) << "-n" << "\t--no(-)colo(u)r" << "            Removes ansi colors from terminal" << NEWLINE;
            Log(LOG_DEFAULT, false) << "-s" << "\t--no(-)suppress" << "            Print event output, like \"Key \'A\' was pressed\" (requires debug mode {-d})" << NEWLINE;
            Log(LOG_DEFAULT, false) << "-m" << "\t--no(-)mouse(-)suppress" << "    Print mouse motion and wheel events (requires debug mode {-d} and no suppress {-s})" << NEWLINE;
            Log(LOG_DEFAULT, false) << "-l" << "\t--log(-)all" << "                Log everything from terminal to file" << NEWLINE;
            Log(LOG_DEFAULT, false) << "-h" << "\t--help" << "                     Shows this help message" << NEWLINE;
            
            Log(LOG_DEFAULT, false) << NEWLINE;
            
            return ERR_OK; //Exit program
        }
    }
    
    uint error = ERR_OK;
    
    Log(LOG_NONE) << "--- Starting `The Warctic` ---" << NEWLINE;
    Utils::Version::PrintWarctic();
    
    //Debug info
    Log(LOG_DEBUG) << "Debug mode active" << NEWLINE;
    
    if (!::suppressed)
        Log(LOG_DEBUG) << "Event output enabled" << NEWLINE;
    
    if (!::mouseSuppressed && !::suppressed)
        Log(LOG_DEBUG) << "Mouse event output enabled" << NEWLINE;
    else if (!::mouseSuppressed && ::suppressed)
        Log(LOG_DEBUG_ERROR) << "Mouse event output can't be enabled without event output (-s)" << NEWLINE;
    
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
    
    error = engine->Initialize();
    
    if (error != ERR_OK)
    {
        Log(LOG_ERROR) << GetErrorMessage(error) << NEWLINE;
        return error;
    }
    
    while (::running)
    {
        engine->Loop();
    }
    
    delete engine;
    
    Log(LOG_NONE) << "---  End of `The Warctic`  ---" << NEWLINE;
    
    return error;
}
