#include "game/io/ConfigFile.hpp"

#include <vector>

#include "Config.hpp"
#include "misc/Logger.hpp"
#include "misc/Errors.hpp"

#include "misc/utils/File.hpp"

ConfigFile::ConfigFile()
{
    
}

std::map<std::string, std::string> ConfigFile::GetConfig()
{
    return config;
}

std::string ConfigFile::GetValue(std::string key)
{
    if (config.find(key) == config.end())
    {
        Log(LOG_DEBUG_ERROR) << GetErrorMessage(ERR_IO_CONFIG_KEYNOTFOUND) << key << NEWLINE;
        return "";
    }
    
    return config.at(key);
}

void ConfigFile::SetValue(std::string key, std::string val)
{
    if (config.find(key) != config.end())
        config.erase(key);
    
    config.insert(std::pair<std::string, std::string>(key, val));
}

int ConfigFile::Check()
{
    if (!Utils::File::Exists(FILE_CONFIG))
    {
        Log(LOG_DEBUG_ERROR) << "Creating default configuration file" << NEWLINE;
        
        SetValue("GraphicsWindowSizeW", "720");
        SetValue("GraphicsWindowSizeH", "480");
        
        uint error = Write();
        if (error != ERR_OK)
            Log(LOG_ERROR) << GetErrorMessage(error) << NEWLINE;
    }
    
    return ERR_OK;
}

int ConfigFile::Read()
{
    Check();
    
    std::string line;
    
    config.clear();
    
    if (!in.is_open())
        in.open(FILE_CONFIG, std::ios::in);
    
    if (!in.is_open()) //If still not open
        return ERR_IO_CONFIG_OPEN;
    
    while (std::getline(in, line))
    {
        if (!(line.find('#') == 0))
        {
            std::vector<std::string> temp = Utils::String::Split(line, '=');
            
            std::string val = temp[1];
            
            val.erase(val.end() - (sizeof(NEWLINE) / sizeof(const char*)), val.end());
            
            config.insert(std::pair<std::string, std::string>(temp[0], val));
            Log(LOG_DEBUG) << temp[0] << ": " << GetValue(temp[0]) << NEWLINE;
            
        }
    }
    
    Log(LOG_INFO) << "Read " << config.size() << " lines from \'" << FILE_CONFIG << "\'" << NEWLINE;
    
    if (in.is_open())
        in.close();
    
    return ERR_OK;
}

int ConfigFile::Write()
{
    if (!out.is_open())
        out.open(FILE_CONFIG, std::ios::out);
    
    if (!out.is_open()) //If still not open
        return ERR_IO_CONFIG_OPEN;
    
    out << "#You can edit this, it works like KEY=VAL, keys probably explain what they do themself" << NEWLINE;
    
    for (std::map<std::string, std::string>::iterator i = config.begin(); i != config.end(); i++)
    {
        out << i->first << "=" << i->second << NEWLINE;
    }
    
    out.flush();
    
    Log(LOG_INFO) << "Wrote " << config.size() << " lines to \'" << FILE_CONFIG << "\'" << NEWLINE;
    
    if (out.is_open())
        out.close();
    
    return ERR_OK;
}

ConfigFile::~ConfigFile()
{
    if (out.is_open())
        out.close();
    
    if (in.is_open())
        in.close();
}
