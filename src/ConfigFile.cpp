#include "ConfigFile.hpp"

#include <fstream>
#include <iostream>

#include "Config.hpp"
#include "Errors.hpp"
#include "utils/Logger.hpp"

#include "utils/File.hpp"
#include "utils/String.hpp"

uint ConfigFile::Read()
{
	uint error = ERR_OK;
	
	error = ConfigFile::Check();
	
	if (error != ERR_OK)
	{
		Log(LOG_ERROR) << GetErrorMessage(error) << NEWLINE;
		
		return ERR_FILE_READ;
	}
	
	std::ifstream config;
	
	if (!config.is_open())
		config.open(FILE_CONFIG, std::ios::in);
	
	if (!config.is_open())
		return ERR_FILE_OPEN;
	
	std::string line;
	std::vector<std::string> configLines;
	
	while (std::getline(config, line))
	{
		if (line[0] != '#')
		{
			std::vector<std::string> temp = String::Split(line, '=');
			
			std::string val = temp[1];
			
			val.erase(val.end() - (sizeof(NEWLINE) / sizeof(const char*)), val.end());
			
			(*Config::Ref().GetConfigMap()).insert(std::pair<std::string, std::string>(temp[0], val));
			
			configLines.push_back(String::Combine(3, temp[0].c_str(), ": ", val.c_str()));
		}
	}
	
	Log(LOG_DEBUG) << "Read " << (*Config::Ref().GetConfigMap()).size() << " lines from \'" << FILE_CONFIG << "\'" << NEWLINE;
	
	for (uint i = 0; i < configLines.size(); i++)
		Log(LOG_TRACE) << configLines[i] << NEWLINE;
	
	if (config.is_open())
		config.close();
	
	return error;
}
 
uint ConfigFile::Check()
{
	uint error = ERR_OK;
	
	if (!File::Exists(FILE_CONFIG))
	{
		Log(LOG_WARNING) << "Config file does not exist, creating default" << NEWLINE;
		
		error = ConfigFile::Create();
		
		if (error != ERR_OK)
		{
			Log(LOG_ERROR) << GetErrorMessage(error) << NEWLINE;
			
			return ERR_FILE_WRITE;
		}
		
		return error;
	}
	
	return error;
}

uint ConfigFile::Write()
{
	std::ofstream config;
	
	if (!config.is_open())
		config.open(FILE_CONFIG, std::ios::app);
	
	if (!config.is_open()) //If config file still not open
		return ERR_FILE_OPEN;
	
	for (std::map<std::string, std::string>::iterator i = (*Config::Ref().GetConfigMap()).begin(); i != (*Config::Ref().GetConfigMap()).end(); i++)
	{
		Log(LOG_TRACE) << "Wrote to \'" << FILE_CONFIG << "\': " << i->first << "=" << i->second << NEWLINE;
		
		config << i->first << "=" << i->second << NEWLINE;
	}
	
	config.flush();
	
	Log(LOG_DEBUG) << "Wrote " << (*Config::Ref().GetConfigMap()).size() << " lines to \'" << FILE_CONFIG << "\'" << NEWLINE;
	
	if (config.is_open())
		config.close();
	
	return ERR_OK;
}

uint ConfigFile::Create()
{
	std::map<std::string, std::string> newConfig;
	
	newConfig.insert(std::pair<std::string, std::string>("iLogLevelTerm", String::ToString(LOG_INFO)));
	newConfig.insert(std::pair<std::string, std::string>("iLogLevelFile", String::ToString(LOG_DEBUG)));
	newConfig.insert(std::pair<std::string, std::string>("bLogColor", String::ToString(true)));
	newConfig.insert(std::pair<std::string, std::string>("iDisplayAspectRatio", String::ToString(ASPECT_16_9)));
	newConfig.insert(std::pair<std::string, std::string>("bDisplayFullscreen", String::ToString(false)));
	newConfig.insert(std::pair<std::string, std::string>("iDisplayResolution", String::ToString(480)));
	
	(*Config::Ref().GetConfigMap()).swap(newConfig);
	
	return ConfigFile::Write();
}
