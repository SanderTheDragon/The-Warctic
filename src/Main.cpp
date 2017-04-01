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
#include "Errors.hpp"
#include "utils/Logger.hpp"

#include "Engine.hpp"
#include "Event.hpp"

void GLFWError(int c, const char* msg)
{
	Log(LOG_ERROR) << "GLFW " << c << ": " << msg << NEWLINE;
}

uint ParseArguments(int argc, char* argv[])
{
	for (int i = 0; i < argc; i++)
	{
		std::string arg(argv[i]);
		
		if (arg[1] == '-')
		{
			arg = arg.substr(1, arg.length());
		}
		
		if (arg == "-h")
		{
			Log(LOG_NONE, true) << "Help for \'The Warctic\' Version " << VERSION << NEWLINE;
			Log(LOG_NONE, true) << NEWLINE;
#if defined(WIN) //Windows needs to be special again
			Log(LOG_NONE, true) << "Usage: warctic.exe [-h] [-lnc] [-llt LEVEL] [-llf LEVEL] [-dar ASPECT]" << NEWLINE;
#else
			Log(LOG_NONE, true) << "Usage: ./warctic [-h] [-lnc] [-llt LEVEL] [-llf LEVEL] [-dar ASPECT]" << NEWLINE;
#endif
			Log(LOG_NONE, true) << NEWLINE;
			Log(LOG_NONE, true) << "-h      Show this help" << NEWLINE;
			Log(LOG_NONE, true) << "-llt    Set minimal log level required to print to terminal, values: off/0, fatal/1, error/2, warning/3, info/4, debug/5, trace/6" << NEWLINE;
			Log(LOG_NONE, true) << "-llf    Set minimal log level required to print to log file, values: off/0, fatal/1, error/2, warning/3, info/4, debug/5, trace/6" << NEWLINE;
			Log(LOG_NONE, true) << "-lnc    Disable colors in the terminal" << NEWLINE;
			Log(LOG_NONE, true) << "-dar    Set display aspect ratio, values: 16:9, 16:10, 4:3" << NEWLINE;
			
			return ERR_EXIT; //Just to exit
		}
		
		if (arg == "-llt" || arg == "-llf") //Set minimal log level required to print to terminal/file
		{
			if (i + 1 >= argc)
			{
				Log(LOG_ERROR) << "No value provided for " << ((arg == "-llt") ? "terminal" : "file") << NEWLINE;
				continue;
			}
			
			std::string value = argv[i + 1];
			uint level = LOG_NONE;
			
			if (value == "off" || value == "0" || value == "off/0")
				level = LOG_OFF;
			else if (value == "fatal" || value == "1" || value == "fatal/1")
				level = LOG_FATAL;
			else if (value == "error" || value == "2" || value == "error/2")
				level = LOG_ERROR;
			else if (value == "warning" || value == "3" || value == "warning/3")
				level = LOG_WARNING;
			else if (value == "info" || value == "4" || value == "info/4")
				level = LOG_INFO;
			else if (value == "debug" || value == "5" || value == "debug/5")
				level = LOG_DEBUG;
			else if (value == "trace" || value == "6" || value == "trace/6")
				level = LOG_TRACE;
			else
			{
				Log(LOG_ERROR) << "Invalid value \'" << value << "\' for " << ((arg == "-llt") ? "terminal" : "file") << NEWLINE;
				continue;
			}
			
			(arg == "-llt") ? Config::Ref().SetLogLevelTerm(level) : Config::Ref().SetLogLevelFile(level);
			
			Log(LOG_NONE) << "Changing log level to \'" << value << "\' for " << ((arg == "-llt") ? "terminal" : "file") << NEWLINE;
		}
		
		if (arg == "-dar") //Set aspect ratio
		{
			if (i + 1 >= argc)
			{
				Log(LOG_ERROR) << "No value provided for " << arg << NEWLINE;
				continue;
			}
			
			std::string value = argv[i + 1];
			uint ar = ASPECT_16_9;
			
			if (value == "16:9")
				ar = ASPECT_16_9;
			else if (value == "16:10")
				ar = ASPECT_16_10;
			else if (value == "4:3")
				ar = ASPECT_4_3;
			else
			{
				Log(LOG_ERROR) << "Invalid value \'" << value << "\' for " << arg << NEWLINE;
				continue;
			}
			
			Config::Ref().SetAspectRatio(ar);
			
			Log(LOG_NONE) << "Changing aspect ratio to \'" << value << "\'" << NEWLINE;
		}
		
		if (arg == "-lnc") //Disable colors in terminal
		{
			Config::Ref().SetLogTermColor(false);
			
			Log(LOG_NONE) << "Disabled colors in terminal (-lnc)" << NEWLINE;
		}
	}
	
	return ERR_OK;
}

int main(int argc, char* argv[])
{
	uint error = ERR_OK;
	
	if (ParseArguments(argc, argv) == ERR_EXIT)
		return ERR_OK;
	
	Log(LOG_NONE) << "--- Start log \'The Warctic\' ---" << NEWLINE;
	
	if (Config::Ref().GetLogTermColor())
	{
		Log(LOG_NONE, true) << "--- Start log colors ---" << NEWLINE;
		
		Log(LOG_FATAL, true)   << "Fatal"   << NEWLINE;
		Log(LOG_ERROR, true)   << "Error"   << NEWLINE;
		Log(LOG_WARNING, true) << "Warning" << NEWLINE;
		Log(LOG_INFO, true)    << "Info"    << NEWLINE;
		Log(LOG_DEBUG, true)   << "Debug"   << NEWLINE;
		Log(LOG_TRACE, true)   << "Trace"   << NEWLINE;
		
		Log(LOG_NONE, true) << "--- End log colors ---" << NEWLINE;
	}
	
	glfwSetErrorCallback(GLFWError);
	
	if ((error = Engine::Ref().Initialize()) != ERR_OK)
	{
		Log(LOG_FATAL) << GetErrorMessage(error) << NEWLINE;
		
		Log(LOG_NONE) << "--- End log \'The Warctic\' ---" << NEWLINE;
		
		return ERR_INIT;
	}
	
	Log(LOG_TRACE) << "Setting GLFW event callbacks" << NEWLINE;
	
	glfwSetKeyCallback(*(*Engine::Ref().GetWindow())->GetWindow(), Event::HandleKeys);
	glfwSetCursorPosCallback(*(*Engine::Ref().GetWindow())->GetWindow(), Event::HandleMouseMove);
	glfwSetScrollCallback(*(*Engine::Ref().GetWindow())->GetWindow(), Event::HandleMouseWheel);
	glfwSetMouseButtonCallback(*(*Engine::Ref().GetWindow())->GetWindow(), Event::HandleMouseButton);
	
	while (Engine::Ref().IsRunning())
	{
		Engine::Ref().Loop();
	}
	
	Log(LOG_NONE) << "--- End log \'The Warctic\' ---" << NEWLINE;
	
	return error;
}
