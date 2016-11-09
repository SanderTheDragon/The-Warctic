#include "game/io/ConfigFile.hpp"

#include <vector>

#include "Config.hpp"
#include "misc/Logger.hpp"
#include "misc/Errors.hpp"

#include "misc/utils/String.hpp"

//TODO: More error handling

ConfigFile::ConfigFile()
{
    
}

int ConfigFile::Read()
{
    std::string line;
    
    config.clear();
    
    if (!in.is_open())
        in.open(FILE_CONFIG, std::ios::in);
    
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

    if (config.size() == 0)
    {
        Log(LOG_DEBUG_ERROR) << "Config size is zero, creating default" << NEWLINE;
        
        SetValue("Graphics_Window_Size_W", "720");
        SetValue("Graphics_Window_Size_H", "480");
        
        Write();
    }
    
    if (in.is_open())
        in.close();
    
    return ERR_OK;
}

int ConfigFile::Write()
{
    if (!out.is_open())
        out.open(FILE_CONFIG, std::ios::out);
    
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
