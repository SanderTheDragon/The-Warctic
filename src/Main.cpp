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
#include "utils/Logger.hpp"

int main(int argc, char* argv[])
{
	for (int i = 0; i < argc; i++)
	{
		std::string arg(argv[i]);
		
		if (arg == "-h")
		{
			Config::Ref().SetLogLevelFile(LOG_OFF);
			
			Log(LOG_NONE) << "Help for \'The Warctic\' Version " << VERSION << NEWLINE;
			Log(LOG_NONE) << NEWLINE;
#if defined(WIN) //Windows needs to be special again
			Log(LOG_NONE) << "Usage: warctic.exe [-h] [-llt LEVEL] [-llf LEVEL] [-lnc]" << NEWLINE;
#else
			Log(LOG_NONE) << "Usage: ./warctic [-h] [-llt LEVEL] [-llf LEVEL] [-lnc]" << NEWLINE;
#endif
			Log(LOG_NONE) << NEWLINE;
			Log(LOG_NONE) << "-h      Show this help" << NEWLINE;
			Log(LOG_NONE) << "-llt    Set minimal log level required to print to terminal, values: off/0, fatal/1, error/2, warning/3, info/4, debug/5, trace/6" << NEWLINE;
			Log(LOG_NONE) << "-llf    Set minimal log level required to print to log file, values: off/0, fatal/1, error/2, warning/3, info/4, debug/5, trace/6" << NEWLINE;
			Log(LOG_NONE) << "-lnc    Disable colors in the terminal" << NEWLINE;
			
			return 0;
		}
		
		if (arg == "-llt" || arg == "-llf") //Set minimal log level required to print to terminal/file
		{
			if (i + 1 >= argc)
				continue;
			
			std::string value = argv[i + 1];
			uint level = LOG_NONE;
			
			if (value == "off" || value == "0" || value == "off/0")
				level = LOG_OFF;
			if (value == "fatal" || value == "1" || value == "fatal/1")
				level = LOG_FATAL;
			if (value == "error" || value == "2" || value == "error/2")
				level = LOG_ERROR;
			if (value == "warning" || value == "3" || value == "warning/3")
				level = LOG_WARNING;
			if (value == "info" || value == "4" || value == "info/4")
				level = LOG_INFO;
			if (value == "debug" || value == "5" || value == "debug/5")
				level = LOG_DEBUG;
			if (value == "trace" || value == "6" || value == "trace/6")
				level = LOG_TRACE;
			
			(arg == "-llt") ? Config::Ref().SetLogLevelTerm(level) : Config::Ref().SetLogLevelFile(level);
		}
		
		if (arg == "-lnc") //Disable colors in terminal
		{
			Config::Ref().SetLogTermColor(false);
		}
	}
	
	
	
	return 0;
}
