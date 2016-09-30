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

bool debug = false;

int main(int argc, char* argv[]) 
{
    Log(LOG_NONE) << "--- Starting `The Warctic` ---" << NEWLINE;
    Log(LOG_NONE) << "\tVersion " << VER_MAJOR << "." << VER_MINOR << "." << VER_BUILD << NEWLINE;
    
//Unstable version warning
#ifdef UNSTABLE
    Log(LOG_WARNING) << "This is an unstable release!" << NEWLINE;
    Log(LOG_WARNING) << "Please report bugs to make it stable" << NEWLINE;
#endif
    
    //Argument parsing
    for (int i = 0; i < argc; i++)
    {
        if (std::string(argv[i]) == "--debug")
        {
            ::debug = true;
            
            Log(LOG_DEBUG) << "Activating debug mode" << NEWLINE;
        }
    }
    
    //Debug info
    Log(LOG_DEBUG) << "Debug mode active" << NEWLINE;
    
    Log(LOG_NONE, false) << "--- Color coding ---" << NEWLINE;
    Log(LOG_DEBUG, false) << "Debug" << NEWLINE;
    Log(LOG_DEBUG_ERROR, false) << "Debug Error" << NEWLINE;
    Log(LOG_INFO, false) << "Info" << NEWLINE;
    Log(LOG_SYSTEM, false) << "System" << NEWLINE;
    Log(LOG_WARNING, false) << "Warning" << NEWLINE;
    Log(LOG_ERROR, false) << "Error" << NEWLINE;
    Log(LOG_NONE, false) << "--------------------" << NEWLINE;
    //End debug info
    
    Log(LOG_SYSTEM) << "System: " << SYSTEM << NEWLINE; //System info
    
    Log(LOG_NONE) << "---  End of `The Warctic`  ---" << NEWLINE;
}
